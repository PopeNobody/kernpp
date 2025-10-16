extern "C" {
  typedef unsigned long size_t;
void __cxa_throw(void *thrown_exception, void *tinfo, void (*dest)(void *));
void __cxa_free_exception(void *thrown_exception);
void __gxx_personality_v0();
void* __cxa_allocate_exception(size_t thrown_size);
void *__cxa_begin_catch(void *exception_object);
void __cxa_end_catch();
void _Unwind_Resume();
};
#if 0
#include "unwind.hh"

// Define the structure for the C++ exception object
// See the Itanium C++ ABI for details.
struct __cxa_exception {
    void *exception_type;
    void (*exception_deleter)(void *);
    unsigned long long exception_class;
    unsigned long long handler_count;
    // ... additional fields for the unwinder
};


extern "C" {

// Called by the compiler to allocate memory for a thrown exception.
// The size is the size of the object being thrown.
void* __cxa_allocate_exception(size_t thrown_size) {
    // You must provide a malloc-like function.
    // The ABI requires 16-byte alignment.
    // The allocated block must have space for the __cxa_exception header.
    void* ptr = your_malloc(thrown_size + sizeof(__cxa_exception));
    return (void*)((char*)ptr + sizeof(__cxa_exception));
}

// Called when the exception object is no longer needed.
void __cxa_free_exception(void *thrown_exception) {
    // The pointer is to the user object, so we must get the header.
    void* header = (void*)((char*)thrown_exception - sizeof(__cxa_exception));
    your_free(header);
}

// Called by the compiler after setting up the exception header.
// This function calls the unwinder to start stack unwinding.
void __cxa_throw(void *thrown_exception, void *tinfo, void (*dest)(void *)) {
    // 1. Get a pointer to the __cxa_exception header.
    __cxa_exception *header = (__cxa_exception *)((char *)thrown_exception - sizeof(__cxa_exception));

    // 2. Populate the header (type info, destructor, etc.).
    header->exception_type = tinfo;
    header->exception_deleter = dest;

    // 3. Set the exception class for the unwinder.
    // This is a magic number for C++ exceptions ('G', 'N', 'U', 'C', '+', '+', '\0', '\0').
    header->exception_class = 0x474e5543432b2b00;

    // 4. Start the unwinding process.
    _Unwind_RaiseException(&header->unwind_header);

    // This function should not return. If it does, something went wrong.
    // You might call your kernel's panic function or std::terminate.
    your_panic("Unwind failed");
}

// Called when a catch block is entered.
void *__cxa_begin_catch(void *exception_object) {
    // This function can be used to manage reference counts for the exception
    // if you support re-throwing. For a simple implementation, it may
    // just return the pointer to the user object.
    __cxa_exception *header = (__cxa_exception*)exception_object;
    return (void*)((char*)header + sizeof(__cxa_exception));
}

// Called when leaving a catch block.
void __cxa_end_catch() {
    // Handles cleanup after a catch. If you support re-throwing, this is where
    // you would check if a re-throw was requested and resume unwinding
    // or destroy the exception if it was fully handled.
}

// The personality routine is the most complex part. It's called by the
// unwinder for each stack frame. It reads the `.eh_frame` data generated
// by the compiler to decide whether to continue unwinding, call a cleanup
// (destructor), or handle a catch.
// A full implementation is non-trivial. You would almost certainly use the
// one from libgcc. Its symbol is `__gxx_personality_v0`.
_Unwind_Reason_Code __gxx_personality_v0(int version,
                                        _Unwind_Action actions,
                                        uint64_t exceptionClass,
                                        _Unwind_Exception *exceptionObject,
                                        _Unwind_Context *context);

} // extern "C"
#endif
