#include <syscall.hh>
#include <new.hh>
namespace std {
  class type_info
  {
  public:
    /** Destructor first. Being the first non-inline virtual function, this
     *  controls in which translation unit the vtable is emitted. The
     *  compiler makes use of that information to know where to emit
     *  the runtime-mandated type_info structures in the new-abi.  */
    virtual ~type_info();

    /** Returns an @e implementation-defined byte string; this is not
     *  portable between compilers!  */
    const char* name() const 
    { return __name[0] == '*' ? __name + 1 : __name; }

#if !__GXX_TYPEINFO_EQUALITY_INLINE
    // In old abi, or when weak symbols are not supported, there can
    // be multiple instances of a type_info object for one
    // type. Uniqueness must use the _name value, not object address.
    bool before(const type_info& __arg) const ;
    bool operator==(const type_info& __arg) const ;
#else
  #if !__GXX_MERGED_TYPEINFO_NAMES
    /** Returns true if @c *this precedes @c __arg in the implementation's
     *  collation order.  */
    // Even with the new abi, on systems that support dlopen
    // we can run into cases where type_info names aren't merged,
    // so we still need to do string comparison.
    bool before(const type_info& __arg) const 
    { return (__name[0] == '*' && __arg.__name[0] == '*')
	? __name < __arg.__name
	: __builtin_strcmp (__name, __arg.__name) < 0; }

    bool operator==(const type_info& __arg) const 
    {
      return ((__name == __arg.__name)
	      || (__name[0] != '*' &&
		  __builtin_strcmp (__name, __arg.__name) == 0));
    }
  #else
    // On some targets we can rely on type_info's NTBS being unique,
    // and therefore address comparisons are sufficient.
    bool before(const type_info& __arg) const 
    { return __name < __arg.__name; }

    bool operator==(const type_info& __arg) const 
    { return __name == __arg.__name; }
  #endif
#endif
    bool operator!=(const type_info& __arg) const 
    { return !operator==(__arg); }

#if __cplusplus >= 201103L
    size_t hash_code() const noexcept
    {
#  if !__GXX_MERGED_TYPEINFO_NAMES
      return _Hash_bytes(name(), __builtin_strlen(name()),
			 static_cast<size_t>(0xc70f6907UL));
#  else
      return reinterpret_cast<size_t>(__name);
#  endif
    }
#endif // C++11

//       // Return true if this is a pointer type of some kind
//       virtual bool __is_pointer_p() const;
//   
//       // Return true if this is a function type
//       virtual bool __is_function_p() const;

    // Try and catch a thrown type. Store an adjusted pointer to the
    // caught type in THR_OBJ. If THR_TYPE is not a pointer type, then
    // THR_OBJ points to the thrown object. If THR_TYPE is a pointer
    // type, then THR_OBJ is the pointer itself. OUTER indicates the
    // number of outer pointers, and whether they were const
    // qualified.
//       virtual bool __do_catch(const type_info *__thr_type, void **__thr_obj,
//   			    unsigned __outer) const;

//       // Internally used during catch matching
//       virtual bool __do_upcast(const __cxxabiv1::__class_type_info *__target,
//   			     void **__obj_ptr) const;

  protected:
    const char *__name;

    explicit type_info(const char *__n): __name(__n) { }

  private:
    /// Assigning type_info is not supported.
    type_info& operator=(const type_info&);
    type_info(const type_info&);
  };
};

static int val=getpid();
static inline int xgetpid() {
	return val++;
};
static const char digs[]="0123456789abcedf";
inline char hex_dig(int val) {
	return digs[val%0xf];
};
	
inline char *fmt_dec(unsigned long val, char *beg, char *end)
{
	if(val) {
		while(val) {
			*--end=hex_dig(val%10);
			val/=10;
		};
	}else{
		*--end='0';
	};
	return end;
};
template<typename int_t>
void write_dec(fd_t fd, int_t val) {
	char buf[sizeof(val)*5];
	char *end=&buf[sizeof(buf)-1];
	char *str=fmt_dec(val,buf,end);
	while(str<end) {
		int res=write(fd,str,end);
		str+=res;
	};
};
const static int count=1000*1000*10;
int main(int, char**) {
	char *name;
	name=typeid(name).name();	
	return 0;
};
