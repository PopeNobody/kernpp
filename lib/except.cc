
namespace std {
  void abort();
};
extern "C" {
  using std::abort;
  void __gxx_personality_v0() {
  }
  void _Unwind_Resume() {
  }
  void __cxa_end_catch() {
  };
  void __cxa_begin_catch() {
  };
  void __cxa_throw_bad_array_new_length() {
    abort();
  };
};
