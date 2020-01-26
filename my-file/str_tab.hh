
struct str_tab
{
  struct val_t
  {
    c_str key;
    size_t val;
    val_t()
      : val(0)
    {
    };
    val_t(const c_str &key, const size_t &val)
    {
    };
  };
  struct tab_t
  {
    vector<val_t> vals;
    size_t &operator[](const c_str &str){
      for(int i=0;i<vals.size();i++){
        if(vals[i].key==str)
          return vals[i].val;
      };
      vals.push_back(val_t());
      vals[size()-1].key=str;
      vals[size()-1].val=0;
      return vals[size()-1].val;
    };
    size_t operator[](const c_str &str) const;
    size_t size() const {
      return vals.size();
    };
  };
  tab_t tab;
  str_tab()
  {
  };
  void push_back(const c_str &str){
    tab[str]=size();
  };
  size_t size() const {
    return tab.size();
  };
  size_t add(const c_str &str) {
    size_t &loc=tab[str];
    if(!loc)
      loc=size();
    return loc;
  };
  struct const_iterator
  {
    const str_tab &tab;
    size_t idx;
    const_iterator(const str_tab &tab, size_t idx)
      : tab(tab), idx(idx)
    {
    };
    bool operator!=(const const_iterator &rhs)
    {
      assert(&tab==&rhs.tab);
      return idx!=rhs.idx;
    };
    const val_t &ptr() const
    {
      assert(idx<tab.size());
      return tab.tab.vals[idx];
    };
    const_iterator operator++(int)
    {
      size_t pos=idx++;
      return const_iterator(tab,pos);
    };
    const_iterator &operator++(){
      assert(idx<tab.size());
      ++idx;
      return *this;
    };
    const val_t *operator->() const
    {
      assert(idx>=0);
      assert(idx<tab.tab.size());
      return &tab.tab.vals[idx];
    };

  };
  const_iterator end() const
  {
    return const_iterator(*this,size());
  };
  const_iterator begin() const
  {
    return const_iterator(*this,0);
  };
};
