#include <iostream.h>
#include <vector>

using namespace sys;
using namespace fmt;

struct c_str {
  char *beg;
  char *end;
  c_str()
    : beg(nullptr), end(nullptr)
  {
  };
  c_str(char *beg, char *end = 0)
    : beg(beg), end(end)
  {
    if(end)
      return;
    end=beg;
    while(*end)
      ++end;
  };
  c_str(char *beg, size_t len)
    : beg(beg), end(beg+len)
  {
  };
  size_t len() const
  {
    return end-beg;
  };
  char operator[](size_t pos) const
  {
    return beg[pos];
  };
};
size_t min(size_t lhs,size_t rhs)
{
  return lhs<rhs?lhs:rhs;
};
inline ssize_t write(fd_t fd, const c_str &str)
{
  return write(fd,str.beg,str.end-str.beg);
};
int cmp(size_t lhs, size_t rhs) {
  if(lhs<rhs)
    return -1;
  else if (rhs<lhs)
    return 1;
  else
    return 0;
};
int cmp(const c_str &lhs, const c_str &rhs) {
  size_t mlen=min(lhs.len(),rhs.len());
  for(size_t i=0;i<mlen;i++){
    char lchr=lhs[i];
    char rchr=rhs[i];
    if(lchr==rchr)
      continue;
    return lchr<rchr?-1:1;
  };
  return cmp(lhs.len(),rhs.len());
};
struct btree_t {
  struct node_t {
    c_str key;
    node_t *lnode;
    node_t *rnode;
    node_t(const c_str &key)
      : key(key), lnode(0), rnode(0)
    {
    };
    node_t *find(const c_str &key)
    {
      int cmpres=cmp(this->key,key);
      if(!cmpres)
        return this;
      if(cmpres<0){
        if(!lnode)
          return lnode;
        else
          return lnode->find(key);
      } else {
        if(!rnode)
          return rnode;
        else
          return rnode->find(key);
      };
    };
    node_t *add(const c_str &key)
    {
      int cmpres=cmp(this->key,key);
      if(!cmpres)
        return this;
      if(cmpres<0){
        if(lnode)
          return lnode->add(key);
        else
          return lnode=new node_t(key);
      } else {
        if(rnode)
          return rnode->add(key);
        else
          return rnode=new node_t(key);
      };
    };
    size_t size() const
    {
      size_t res=1;
      if(lnode)
        res+=lnode->size();
      if(rnode)
        res+=rnode->size();
      return res;
    };
    void dump() const
    {
      if(lnode)
        lnode->dump();
      write(1,key);
      write(1,L("\n"));
      if(rnode)
        rnode->dump();
    };
  };
  node_t *tree;
  btree_t()
    :tree(0)
  {
  };
  size_t size() {
    if(!tree)
      return 0;
    return tree->size();
  };
  node_t *add(const c_str &key)
  {
    if(tree)
      return tree->add(key);
    else
      return tree=new node_t(key);
  };
  node_t *find(const c_str &key){
    if(!tree)
      return tree;
    return tree->find(key);
  };
  void dump() const {
    write(1,L("tree dump {\n"));
    if(tree)
      tree->dump();
    else
      write(1,L("empty tree"));
    write(1,L("}\n"));
  };
};
struct list_t {
  c_str *beg;
  size_t cap;
  size_t cnt;
  list_t()
    :beg(new c_str[16]), cap(16), cnt(0)
  {
  };
  size_t add(const c_str &str)
  {
    if(!cnt){
      beg[cnt++]=str;
      return cnt;
    };
    int cmp_res=cmp(beg[cnt-1],str);
    if(cmp_res>0) {
      write(2,"disorder\n  ");
      write(2,beg[cnt-1]);
      write(2,L("\n    >\n  "));
      write(2,str);
      write(2,L("\n\n"));
      dump();
      exit(1);
    } 
    if ( cmp_res ) {
      if( cnt == cap ) {
        size_t new_cap=cap*2;
        c_str *new_beg=new c_str[new_cap];
        for(int i = 0; i<cap; i++)
          new_beg[i]=beg[i];
        c_str *old_beg=beg;
        beg=new_beg;
        cap=new_cap;
        delete old_beg;
      } 
      beg[cnt++]=str;
    };
    return cnt;
  };
  size_t size() const {
    return cnt;
  };
  void dump() const {
    for(size_t i=0;i<cnt;i++) {
      write_dec(1,i);
      write(1,L(" "));
      write(1,beg[i]);
      write(1,L("\n"));
    };
  };
};
struct isspace_t {
  char tab[256];
  isspace_t()
  {
    memset(tab,0,sizeof(tab));
    tab[' ']=1;
    tab['\t']=1;
    tab['\n']=1;
    tab['\v']=1;
  };
  bool operator()(char ch) const
  {
    return tab[ch];
  };
};
isspace_t isspace;

int main(int, char**)
{
  const char fn[] =
    "data/mirror.clarkson.edu_ubuntu_dists_bionic-updates_Contents-amd64";
    //"testfile";
  int fd = open(fn,o_rdonly);
  if(fd<0) {
    write(2,L("open failed\n"));
    exit(1);
  };
  write(2,L("opened: "));
  write_dec(2,fd);
  write(2,L("\n"));
  ssize_t len=lseek(fd,0,end);
  write_dec(2,len);
  write(2,L(" bytes in file\n"));
  char *data=(char*)mmap(
      0, len, prot_read|prot_write, map_private, fd, 0
      );
  write(2,L("mapped to: "));
  write_ptr(2,data);
  write(2,L("\n"));

  list_t list;
  char *beg=data;
  char *end=data+len;
  size_t lines=0;
  while(beg!=end){
    char *pos=beg;
    while(pos!=end && !isspace(*pos))
      ++pos;
    c_str path(beg,pos);
    while(*path.end != '/')
      --path.end;
    c_str name(path.end+1,pos);
    while(pos!=end && isspace(*pos))
      ++pos;
    beg=pos;
    while(pos!=end && *pos != '\n')
      ++pos;
    c_str pkg(beg,pos);
    beg=pos;
    if(beg!=end)
      ++beg;
    *path.end=0;
    *name.end=0;
    *pkg.end=0;
    list.add(path);
    if(!(++lines%10000)){
      write(1,L("lines: "));
      write_dec(1,lines);
      write(1,L(" nodes: "));
      write_dec(1,list.size());
      write(1,L("\n"));
    };
  };
  list.dump();
  return 0;
};

