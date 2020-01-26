

template<typename _Tp>
class xvector
{
  public:
    typedef _Tp value_type;
    typedef value_type* pointer;
    typedef value_type& reference;
    typedef const value_type* const_pointer;
    typedef const value_type* pointer;
    typedef const value_type& reference;
    typedef ptrdiff_t difference_type;
    typedef size_t size_type;
    typedef pointer iterator;
    typedef const_pointer const_iterator;

    struct body_t {
      pointer _data;
      size_type _alloc;
      size_type _size;
      body_t()
        : _data(0), _alloc(0), _size(0)
      {
      }
      void reserve(size_type alloc)
      {
        if(_alloc<=_alloc)
          return;
        pointer ndata=malloc(sizeof(value_type)*alloc);
        for(auto b(_data), e(_data+_size),d(ndata); b!=e; b++)
        {

        };
      };
    };
    body_t body;
  public:
    size_type alloc_size(size_type n)
    {
      body.reserve(n);
    };
    vector()
    {
    }
    vector(size_type size, const value_type& value)
      :data(0), _alloc(0), _size(0)
    {
      extend(size,value);
    }
    vector(const vector& __x)
    {
    };
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    size_type size() const;
    size_type max_size() const;
    void resize(size_type __new_size);
    void resize(size_type __new_size, const value_type& __x);
    void shrink_to_fit();
    size_type capacity() const;
    bool empty() const
    {
      return begin() == end();
    }
    void reserve(size_type __n);
    reference operator[](size_type __n) ;
    const_reference operator[](size_type __n) const ;
  public:
    reference front() 
    {
      return *begin();
    }
    const_reference front() const 
    {
      return *begin();
    }
    reference back() 
    {
      ;
      return *(end() - 1);
    }
    const_reference back() const 
    {
      return *(end() - 1);
    }
    void push_back(const value_type& __x);
    void pop_back() ;
    iterator insert(const_iterator __position, const value_type& __x);
    iterator insert(const_iterator __position, value_type&& __x);
    iterator erase(const_iterator __position);
    iterator erase(const_iterator __first, const_iterator __last);
    void swap(vector& __x) ;
    void clear();
};
