#pragma once
namespace vec {
  template<typename val_t>
    struct vector
    {
      val_t *arr;
      size_t len;
      vector()
        : arr(nullptr), len(0)
      {
      };
      vector(val_t *beg, val_t *end)
      {
      };
      val_t &operator[](size_t n)
      {
        assert(n<size());
        return arr[n];
      };
      const val_t &operator[](size_t n) const
      {
        assert(n<size());
        return arr[n];
      };
      size_t size() const {
        return  len;
      };
      const val_t *begin() const {
        return arr;
      };
      const val_t *end() const {
        return arr+len;
      };
      val_t *begin() {
        return arr;
      };
      val_t *end() {
        return arr+len;
      };
    };
}
