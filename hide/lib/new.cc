#include <syscall.hh>
#include <new.hh>

using std::align_val_t;
using std::nothrow_t;

void* operator new(size_t sz)
{
	return malloc(sz);
}
void* operator new(size_t sz, align_val_t align)
{
	return operator new(sz);
}
void* operator new(size_t sz, align_val_t al, const nothrow_t&)
  noexcept
{
	return operator new(sz, al);
}

void* operator new[](size_t sz)
{
	return operator new(sz);
}
void* operator new[](size_t sz, align_val_t align)
{
	return operator new[](sz);
};

void* operator new[](size_t sz, align_val_t al, const nothrow_t&)
  noexcept
{
	return operator new[](sz, al);
}
