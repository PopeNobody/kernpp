
//   #include <cstdio>
//   #include <cstdlib>
// replacement of a minimal set of functions:
inline void* operator new(size_t sz) {
    return malloc(sz);
}
inline void operator delete(void* ptr) noexcept
{
    free(ptr);
}
inline void operator delete[](void *ptr) {
	free(ptr);
};
inline void operator delete(void* ptr, size_t size)
{
	free(ptr);
};
inline void* operator new[](size_t size)
{
	return malloc(size);
};

