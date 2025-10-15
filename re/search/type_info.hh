
  template<class val_t, bool is_i, bool is_b, bool is_f, bool is_p>
  struct val_data {
    typedef val_t type;
    static constexpr bool is_integral=is_i;
    static constexpr bool is_bool=is_b;
    static constexpr bool is_float=is_f;
    static constexpr bool is_pointer=is_p;
  };
  template<class T> struct int_types { static constexpr is_integral = false };
  template<> struct int_types< typedef signed char > { static constexpr is_integral = true };
  template<> struct int_types<     typedef signed short  > { static constexpr is_integral = true };
  template<> struct int_types<     typedef signed int > { static constexpr is_integral = true };
  template<> struct int_types<     typedef signed long > { static constexpr is_integral = true };
  template<> struct int_types<     typedef signed long long > { static constexpr is_integral = true };
  template<> struct int_types<     typedef signed int128_t > { static constexpr is_integral = true };
  template<> struct int_types<     typedef unsigned char > { static constexpr is_integral = true };
  template<> struct int_types<     typedef unsigned short > { static constexpr is_integral = true };
  template<> struct int_types<     typedef unsigned int > { static constexpr is_integral = true };
  template<> struct int_types<     typedef unsigned long > { static constexpr is_integral = true };
  template<> struct int_types<     typedef unsigned long long > { static constexpr is_integral = true };
  template<> struct int_types<     typedef unsigned int128_t > { static constexpr is_integral = true };
  template>class T>
    using int_type_v = int_types<T>::is_integral;

