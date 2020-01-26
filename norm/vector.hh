#ifndef vector_hh
#define vector_hh vector_hh

template<typename val_t>
struct vector {
  size_t cap;
  size_t cnt;
  val_t *dat;
  vector(int cap=4)
    : cap(cap), cnt(0), dat(new val_t[cap])
  {
  };
  ~vector()
  {
    cap=-1;
    cnt=-1;
    delete[] dat;
  };
  void reserve(size_t new_cap)
  {
    if(new_cap <= cap)
      return;
    size_t min_cap=new_cap;
    new_cap=cap;
    while(new_cap<min_cap)
      new_cap*=2;
    val_t *new_dat=new val_t[new_cap];
#if 0
    debug((void*)new_dat);
    debug(new_cap);
#endif
    for(int i=0;i<cnt;i++){
      new_dat[i]=dat[i];
    };
    val_t *old_dat=dat;
    dat=new_dat;
    cap=new_cap;
    delete old_dat;
  };
  val_t &back() {
    assert(size());
    return (*this)[size()-1];
  };
  void push_back(const val_t &val)
  {
    while(cnt>=cap)
      reserve(cap*2);
    dat[cnt++]=val;
  };
  size_t size() const {
    return cnt;
  };
  const val_t &operator[](int idx) const {
    assert(idx<cnt);
    return dat[idx];
  };
  val_t &operator[](int idx) {
    if(idx>=cnt)
      reserve(idx+1);
    return dat[idx];
  };
  struct const_iterator
  {
    vector *vec;
    size_t idx;
    const_iterator( vector *vec, size_t idx )
      : vec(vec), idx(idx)
    {
    }
    bool operator!=(const const_iterator &rhs);
    const_iterator &operator++(int);
    const_iterator operator++();
    const val_t *operator->() const;
  };
  const_iterator begin() const
  {
    return const_iterator(this,0);
  };
  const_iterator end() const
  {
    return const_iterator(this,size());
  };
};

#endif
