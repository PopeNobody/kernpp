#include <syscall.hh>
#include <new.hh>

namespace std
{
  void free(void*);
}

using std::align_val_t;
using std::nothrow_t;
using std::free;

void operator delete(void* ptr, align_val_t) noexcept
{
  free (ptr);
}
void operator delete (void *ptr, align_val_t al, const nothrow_t&)
	noexcept
{
  ::operator delete (ptr, al);
}
void operator delete(void* ptr) noexcept
{
  free(ptr);
}
void operator delete (void *ptr, const nothrow_t&) noexcept
{
  ::operator delete (ptr);
}
void operator delete(void* ptr, size_t, align_val_t al) noexcept
{
  ::operator delete (ptr, al);
}
void operator delete(void* ptr, size_t) noexcept
{
  ::operator delete (ptr);
}

void operator delete[] (void *ptr) 
{
  ::operator delete (ptr);
}
void operator delete[] (void *ptr, align_val_t al) noexcept
{
  ::operator delete (ptr, al);
}
void operator delete[] (void *ptr, align_val_t al, const nothrow_t&)
	noexcept
{
  ::operator delete[] (ptr, al);
}
void operator delete[] (void *ptr, const nothrow_t&) noexcept
{
  ::operator delete[] (ptr);
}
void operator delete[] (void *ptr, size_t, align_val_t al) noexcept
{
  ::operator delete[] (ptr, al);
}
void operator delete[] (void *ptr, size_t) noexcept
{
  ::operator delete[] (ptr);
}
