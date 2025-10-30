#include "types.hh"

//   #include "temp/rem-ref.hh"
//   #include "temp/forward.hh"
//   #include "min.hh"

#define BOOL static constexpr bool
namespace std {
  template<class T>
    struct is_t {
      BOOL  is_abstract                 =  false;
      BOOL  is_aggregate                =  false;
      BOOL  is_arithmetic               =  false;
      BOOL  is_array                    =  false;
      BOOL  is_base_of                  =  false;
      BOOL  is_bounded_array            =  false;
      BOOL  is_class                    =  false;
      BOOL  is_compound                 =  false;
      BOOL  is_const                    =  false;
      BOOL  is_empty                    =  false;
      BOOL  is_enum                     =  false;
      BOOL  is_final                    =  false;
      BOOL  is_floating_point           =  false;
      BOOL  is_function                 =  false;
      BOOL  is_fundamental              =  false;
      BOOL  is_implicit_lifetime        =  false;
      BOOL  is_integral                 =  false;
      BOOL  is_layout_compatible        =  false;
      BOOL  is_literal_type             =  false;
      BOOL  is_lvalue_reference         =  false;
      BOOL  is_member_function_pointer  =  false;
      BOOL  is_member_object_pointer    =  false;
      BOOL  is_member_pointer           =  false;
      BOOL  is_member_ptr               =  false;
      BOOL  is_null_pointer             =  false;
      BOOL  is_null_ptr                 =  false;
      BOOL  is_object                   =  false;
      BOOL  is_pod                      =  false;
      BOOL  is_pointer                  =  false;
      BOOL  is_polymorphic              =  false;
      BOOL  is_reference                =  false;
      BOOL  is_rvalue_reference         =  false;
      BOOL  is_same                     =  false;
      BOOL  is_scalar                   =  false;
      BOOL  is_scoped_enum              =  false;
      BOOL  is_signed                   =  false;
      BOOL  is_standard_layout          =  false;
      BOOL  is_trivial                  =  false;
      BOOL  is_trivially_copyable       =  false;
      BOOL  is_unbounded_array          =  false;
      BOOL  is_union                    =  false;
      BOOL  is_unsigned                 =  false;
      BOOL  is_virtual_base_of          =  false;
      BOOL  is_void                     =  false;
      BOOL  is_volatile                 =  false;
    };

}
#undef BOOL

int main(int, char**, char**){
  return 0;
};
