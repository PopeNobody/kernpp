#include "syscall.hh"
#pragma once


namespace __cxxabiv1
{
  class __class_type_info;
}

namespace std
{
  class type_info
  {
    public:
      virtual ~type_info();

      const char* name() const
      {
        return __name[0] == '*' ? __name + 1 : __name;
      }

      bool before(const type_info& __arg) const ;
      bool operator==(const type_info& __arg) const ;

      bool operator!=(const type_info& __arg) const 
      { return !operator==(__arg); }

      size_t hash_code() const noexcept
      {
        return reinterpret_cast<size_t>(__name);
      }

      // Return true if this is a pointer type of some kind
      virtual bool __is_pointer_p() const;

      // Return true if this is a function type
      virtual bool __is_function_p() const;

      // Try and catch a thrown type. Store an adjusted pointer to the
      // caught type in THR_OBJ. If THR_TYPE is not a pointer type, then
      // THR_OBJ points to the thrown object. If THR_TYPE is a pointer
      // type, then THR_OBJ is the pointer itself. OUTER indicates the
      // number of outer pointers, and whether they were const
      // qualified.
      virtual bool __do_catch(const type_info *__thr_type, void **__thr_obj,
          unsigned __outer) const;

      // Internally used during catch matching
      virtual bool __do_upcast(const __cxxabiv1::__class_type_info *__target,
          void **__obj_ptr) const;

    protected:
      const char * const __name;

      explicit type_info(const char *__n): __name(__n) { }

    private:
      /// Assigning type_info is not supported.
      type_info& operator=(const type_info&);
      type_info(const type_info&);
  };
  /**
   *  @brief  Thrown during incorrect typecasting.
   *  @ingroup exceptions
   *
   *  If you attempt an invalid @c dynamic_cast expression, an instance of
   *  this class (or something derived from this class) is thrown.  */
  class exception
  {
  };
  class bad_cast : public exception
  {
    public:
      bad_cast() { }

      // This declaration is not useless:
      // http://gcc.gnu.org/onlinedocs/gcc-3.0.2/gcc_6.html#SEC118
      virtual ~bad_cast() ;

      // See comment in eh_exception.cc.
      virtual const char* what() const ;
  };

  /**
   *  @brief Thrown when a NULL pointer in a @c typeid expression is used.
   *  @ingroup exceptions
   */
  class bad_typeid : public exception
  {
    public:
      bad_typeid ()  { }

      // This declaration is not useless:
      // http://gcc.gnu.org/onlinedocs/gcc-3.0.2/gcc_6.html#SEC118
      virtual ~bad_typeid() ;

      // See comment in eh_exception.cc.
      virtual const char* what() const ;
  };
} // namespace std

