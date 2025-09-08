// ssl_raii.hh (OpenSSL 1.1+ assumed)
#pragma once
#include <memory>
#include <string>
#include <stdexcept>
#include <openssl/evp.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include <openssl/pem.h>
#include <openssl/bn.h>

// ---------- generic deleter traits ----------
template<class T> struct ssl_free;
template<> struct ssl_free<EVP_PKEY> { void operator()(EVP_PKEY* p) const { EVP_PKEY_free(p); } };
template<> struct ssl_free<X509>     { void operator()(X509* p)     const { X509_free(p); } };
template<> struct ssl_free<X509_NAME>{ void operator()(X509_NAME* p)const { X509_NAME_free(p); } };
template<> struct ssl_free<BIGNUM>   { void operator()(BIGNUM* p)   const { BN_free(p); } };

template<class T>
using ssl_up = std::unique_ptr<T, ssl_free<T>>;

// ---------- small helpers ----------
inline ASN1_INTEGER* bn_to_asn1(const BIGNUM* bn){
  return BN_to_ASN1_INTEGER(const_cast<BIGNUM*>(bn), nullptr);
}
inline ssl_up<BIGNUM> rand_bn(int bits=64){ ssl_up<BIGNUM> b(BN_new()); if(!b||!BN_rand(b.get(),bits,0,0)) return {}; return b; }

// ---------- EVP_PKEY wrapper ----------
class PKey {
  ssl_up<EVP_PKEY> pk_;
public:
  PKey(): pk_(EVP_PKEY_new()) {}
  explicit PKey(EVP_PKEY* raw): pk_(raw) {}
  static PKey make_rsa(int bits=2048){
    PKey out;
    if(!out.pk_) return {};
    RSA* rsa = RSA_new();
    ssl_up<BIGNUM> e(BN_new()); if(!rsa||!e) return {};
    BN_set_word(e.get(), RSA_F4);
    if(!RSA_generate_key_ex(rsa,bits,e.get(),nullptr)) { RSA_free(rsa); return {}; }
    if(!EVP_PKEY_assign_RSA(out.pk_.get(), rsa)) { RSA_free(rsa); return {}; } // ownership moved
    return out;
  }
  EVP_PKEY* get() const { return pk_.get(); }
  explicit operator bool() const { return (bool)pk_; }

  bool write_pem_priv(const std::string& path) const {
    FILE* f = fopen(path.c_str(),"wb"); if(!f) return false;
    bool ok = PEM_write_PrivateKey(f, pk_.get(), nullptr, nullptr, 0, nullptr, nullptr);
    fclose(f); return ok;
  }
};

// ---------- X509 wrapper ----------
class Cert {
  ssl_up<X509> cert_;
public:
  Cert(): cert_(X509_new()) {}
  explicit Cert(X509* raw): cert_(raw) {}
  static Cert create_v3() { Cert c; if(c.cert_) X509_set_version(c.cert_.get(),2); return c; }
  X509* get() const { return cert_.get(); }
  explicit operator bool() const { return (bool)cert_; }

  bool set_serial_random(int bits=64){
    auto bn = rand_bn(bits); if(!bn) return false;
    ASN1_INTEGER* ai = bn_to_asn1(bn.get()); if(!ai) return false;
    int ok = X509_set_serialNumber(cert_.get(), ai);
    ASN1_INTEGER_free(ai);
    return ok==1;
  }
  bool set_subject(const std::string& C, const std::string& O, const std::string& CN){
    ssl_up<X509_NAME> n(X509_NAME_new()); if(!n) return false;
    auto add = [&](int nid, const std::string& v){
      return X509_NAME_add_entry_by_NID(n.get(), nid, MBSTRING_ASC,
                                        (const unsigned char*)v.c_str(), -1, -1, 0)==1;
    };
    if(!add(NID_countryName,C) || !add(NID_organizationName,O) || !add(NID_commonName,CN)) return false;
    return X509_set_subject_name(cert_.get(), n.get())==1;
  }
  bool set_issuer_from(const Cert& issuer){
    return X509_set_issuer_name(cert_.get(), X509_get_subject_name(issuer.get()))==1;
  }
  bool set_validity_days(int days, long skew_seconds = -60){
    X509_gmtime_adj(X509_getm_notBefore(cert_.get()), skew_seconds);
    X509_gmtime_adj(X509_getm_notAfter (cert_.get()), 60L*60*24*days);
    return true;
  }
  bool set_pubkey(const PKey& k){ return X509_set_pubkey(cert_.get(), k.get())==1; }

  bool add_ext(int nid, const char* value, const Cert* issuer_ctx=nullptr){
    X509V3_CTX ctx; X509V3_set_ctx(&ctx, issuer_ctx?issuer_ctx->get():nullptr, cert_.get(), nullptr, nullptr, 0);
    X509_EXTENSION* ex = X509V3_EXT_nconf_nid(nullptr, &ctx, nid, (char*)value);
    if(!ex) return false;
    int ok = X509_add_ext(cert_.get(), ex, -1);
    X509_EXTENSION_free(ex);
    return ok==1;
  }
  bool add_san_dns(const std::string& host, const Cert* issuer_ctx=nullptr){
    X509V3_CTX ctx; X509V3_set_ctx(&ctx, issuer_ctx?issuer_ctx->get():nullptr, cert_.get(), nullptr, nullptr, 0);
    std::string v = "DNS:" + host;
    X509_EXTENSION* ex = X509V3_EXT_conf_nid(nullptr,&ctx,NID_subject_alt_name,(char*)v.c_str());
    if(!ex) return false;
    int ok = X509_add_ext(cert_.get(), ex, -1);
    X509_EXTENSION_free(ex);
    return ok==1;
  }
  bool sign(const PKey& signer, const EVP_MD* md = EVP_sha256()){
    return X509_sign(cert_.get(), signer.get(), md) > 0;
  }
  bool write_pem(const std::string& path) const {
    FILE* f = fopen(path.c_str(),"wb"); if(!f) return false;
    bool ok = PEM_write_X509(f, cert_.get());
    fclose(f); return ok;
  }
};

// ---------- tiny CA façade ----------
struct SimpleCA {
  PKey ca_key;
  Cert ca_cert;

  static SimpleCA make(const std::string& cn="Local Dev Root CA", int days=3650){
    SimpleCA ca;
    ca.ca_key = PKey::make_rsa(4096);
    ca.ca_cert = Cert::create_v3();
    if(!ca.ca_key || !ca.ca_cert) return {};
    ca.ca_cert.set_serial_random();
    ca.ca_cert.set_subject("US","Local Dev Root", cn);
    ca.ca_cert.set_issuer_from(ca.ca_cert);       // self-signed
    ca.ca_cert.set_validity_days(days);
    ca.ca_cert.set_pubkey(ca.ca_key);
    ca.ca_cert.add_ext(NID_basic_constraints, "critical,CA:TRUE,pathlen:0", &ca.ca_cert);
    ca.ca_cert.add_ext(NID_key_usage,         "critical,keyCertSign,cRLSign", &ca.ca_cert);
    ca.ca_cert.add_ext(NID_subject_key_identifier, "hash", &ca.ca_cert);
    ca.ca_cert.add_ext(NID_authority_key_identifier,"keyid:always,issuer", &ca.ca_cert);
    ca.ca_cert.sign(ca.ca_key);
    return ca;
  }

  // issue a server cert for hostname
  std::pair<PKey, Cert> issue_server(const std::string& host, int days=825) const {
    PKey k = PKey::make_rsa(2048);
    Cert c = Cert::create_v3();
    if(!k || !c) return {};
    c.set_serial_random();
    c.set_subject("US","Intercepted Server", host);
    c.set_issuer_from(ca_cert);
    c.set_validity_days(days);
    c.set_pubkey(k);
    c.add_ext(NID_basic_constraints, "critical,CA:FALSE", &ca_cert);
    c.add_ext(NID_key_usage,         "critical,digitalSignature,keyEncipherment", &ca_cert);
    c.add_ext(NID_ext_key_usage,     "serverAuth", &ca_cert);
    c.add_san_dns(host, &ca_cert);
    c.add_ext(NID_subject_key_identifier, "hash", &ca_cert);
    c.add_ext(NID_authority_key_identifier,"keyid,issuer", &ca_cert);
    c.sign(ca_key);
    return {std::move(k), std::move(c)};
  }
};
