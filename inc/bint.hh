#pragma once
#include <cstdint>
#include <cstddef>

template<class T>
struct dbl_int {
  static_assert((T)0 < (T)-1, "dbl_int<T> requires an unsigned T");
  static constexpr unsigned limb_bits = sizeof(T) * 8;

  T hi, lo;

  // ctors
  constexpr dbl_int(T hi, T lo) : hi(hi), lo(lo) {}
  constexpr explicit dbl_int(T x) : hi(0), lo(x) {}
  constexpr dbl_int(const dbl_int &rhs) : hi(rhs.hi_), lo(rhs.lo_) {};

  // comparisons
  friend constexpr bool operator==(dbl_int a, dbl_int b) { return a.hi==b.hi && a.lo==b.lo; }
  friend constexpr bool operator!=(dbl_int a, dbl_int b) { return !(a==b); }
  friend constexpr bool operator<(dbl_int a, dbl_int b)  { return (a.hi<b.hi) || (a.hi==b.hi && a.lo<b.lo); }
  friend constexpr bool operator>(dbl_int a, dbl_int b)  { return b<a; }
  friend constexpr bool operator<=(dbl_int a, dbl_int b) { return !(b<a); }
  friend constexpr bool operator>=(dbl_int a, dbl_int b) { return !(a<b); }

  // bitwise
  friend constexpr dbl_int operator&(dbl_int a, dbl_int b) { return dbl_int(a.hi & b.hi, a.lo & b.lo); }
  friend constexpr dbl_int operator|(dbl_int a, dbl_int b) { return dbl_int(a.hi | b.hi, a.lo | b.lo); }
  friend constexpr dbl_int operator^(dbl_int a, dbl_int b) { return dbl_int(a.hi ^ b.hi, a.lo ^ b.lo); }
  friend constexpr dbl_int operator~(dbl_int a)       { return dbl_int(~a.hi, ~a.lo); }

  // add/sub (carry/borrow internal)
  friend constexpr dbl_int operator+(dbl_int a, dbl_int b) {
    dbl_int r;
    r.lo = a.lo + b.lo;
    T c  = (r.lo < a.lo);
    r.hi = a.hi + b.hi + c;
    return r;
  }
  friend constexpr dbl_int operator-(dbl_int a, dbl_int b) {
    dbl_int r;
    T brr = (a.lo < b.lo);
    r.lo = a.lo - b.lo;
    r.hi = a.hi - b.hi - brr;
    return r;
  }
  constexpr dbl_int& operator+=(dbl_int x){ *this = *this + x; return *this; }
  constexpr dbl_int& operator-=(dbl_int x){ *this = *this - x; return *this; }

  // shifts (0..2*limb_bits)
  friend constexpr dbl_int operator<<(dbl_int x, unsigned k){
    if (k==0) return x;
    if (k >= 2*limb_bits) return dbl_int(0,0);
    if (k >= limb_bits)   return dbl_int( (T)(x.lo << (k - limb_bits)), (T)0 );
    // 0 < k < limb_bits
    T carry = (k==0) ? 0 : (T)(x.lo >> (limb_bits - k));
    return dbl_int( (T)((x.hi << k) | carry), (T)(x.lo << k) );
  }
  friend constexpr dbl_int operator>>(dbl_int x, unsigned k){
    if (k==0) return x;
    if (k >= 2*limb_bits) return dbl_int(0,0);
    if (k >= limb_bits)   return dbl_int( (T)0, (T)(x.hi >> (k - limb_bits)) );
    // 0 < k < limb_bits
    T carry = (k==0) ? 0 : (T)(x.hi << (limb_bits - k));
    return dbl_int( (T)(x.hi >> k), (T)((x.lo >> k) | carry) );
  }
  constexpr dbl_int& operator<<=(unsigned k){ *this = *this << k; return *this; }
  constexpr dbl_int& operator>>=(unsigned k){ *this = *this >> k; return *this; }

  // rotates (useful for crypto)
  friend constexpr dbl_int rol(dbl_int x, unsigned k){
    k &= (2*limb_bits - 1);
    return (x << k) | (x >> (2*limb_bits - k));
  }
  friend constexpr dbl_int ror(dbl_int x, unsigned k){
    k &= (2*limb_bits - 1);
    return (x >> k) | (x << (2*limb_bits - k));
  }

  // scalar ops (by limb)
  friend constexpr dbl_int operator|(dbl_int x, T y){ return x | dbl_int(0,y); }
  friend constexpr dbl_int operator&(dbl_int x, T y){ return x & dbl_int(0,y); }
  friend constexpr dbl_int operator^(dbl_int x, T y){ return x ^ dbl_int(0,y); }

  // multiply by limb (returns 2x with carry folded in)
  friend constexpr dbl_int mul_limb(dbl_int a, T b){
    // schoolbook: (hi:lo) * b
    dbl_int r{};
    // low product
    T lo_lo = (T)(a.lo * b);
    // cross term carry: use wider temp if available, else split
#if defined(__SIZEOF_INT128__)
    unsigned __int128 w1 = (unsigned __int128)a.lo * b;
    unsigned __int128 w2 = (unsigned __int128)a.hi * b;
    r.lo = (T)w1;
    r.hi = (T)(w2 + (T)(w1 >> 64));
#else
    // portable fallback via 32-bit halves
    const unsigned hbits = limb_bits/2;
    const T mask = (hbits==32? (T)0xFFFFFFFFu : (T)((T)1<<hbits)-1);

    T a_lo0 = a.lo & mask,     a_lo1 = a.lo >> hbits;
    T b0    = b & mask,        b1    = b >> hbits;

    // a.lo * b
    T p00 = a_lo0 * b0;
    T p01 = a_lo0 * b1;
    T p10 = a_lo1 * b0;
    T p11 = a_lo1 * b1;

    // assemble low limb
    T carry = ((p00 >> hbits) + (p01 & mask) + (p10 & mask)) >> hbits;
    r.lo = (p00 & mask) | (( (p00 >> hbits) + (p01 & mask) + (p10 & mask) ) << hbits);

    // high limb: a.hi*b + p11 + cross carries
    // (simple but correct; you can micro-opt later)
    r.hi = a.hi * b;
    r.hi += (p01 >> hbits) + (p10 >> hbits) + p11 + carry;
#endif
    return r;
  }
};
