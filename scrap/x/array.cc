
template<class val_t>
constexpr size_t fmt_size();
template<class _val_t, class _itr_t>
struct types_t {
  typedef _val_t val_t;
  typedef _itr_t itr_t;
  typedef val_t &ref_t;
  typedef val_t *ptr_t;
  typedef const val_t val_T;
  typedef
  typedef types_t<val_T,itr_T> types_T;
  typedef types_T::ptr_t ptr_T;
  typedef types_T::ref_t ref_T;
  typedef types_T::ptr_t ptr_T;
};
template<class _val_t>
struct array_t : public types_t<_val_t> {
  body_t body;
  const itr_T beg() const { return body.beg(); }
  const itr_T end() const { return body.end(); }
  const itr_t beg()       { return body.beg(); }
  const itr_t end()       { return body.end(); }
  ref_t &operator[](size_t idx) {
    return beg()[itx];
  }
  ref_T &operator[](size_t idx) const {
    return beg()[idx];
  };
};
template<class val_t,size_t _count>
struct array_t {
  static constexpr count=_count;
  static constexpr size=_count*sizeof(val_t);
  val_t array[count];
};
template<class val_t>
struct fmt_t {
  static constexpr size_t size=fmt_size<val_t>();
  array<char,size> buf;
  fmt_buf
};

