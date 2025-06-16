#include <syscall.hh>

void* operator new(size_t sz);
void* operator new(size_t size, std::align_val_t align);
void* operator new[](size_t size);
void* operator new[](size_t size, std::align_val_t align);

void operator delete(void* ptr) noexcept;
void operator delete[](void *ptr);
void operator delete(void* ptr, size_t size);
namespace std {
	new_handler set_new_handler (new_handler handler) throw();
	new_handler get_new_handler () noexcept;
}

