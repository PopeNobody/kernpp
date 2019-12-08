
//   #include <cstdio>
//   #include <cstdlib>
// replacement of a minimal set of functions:
void* operator new(size_t sz) {
//    printf("global op new called, size = %zu\n",sz);
    return malloc(sz);
}
void operator delete(void* ptr) noexcept
{
//       puts("global op delete called");
    free(ptr);
}
void operator delete[](void *ptr) {
	free(ptr);
};
void operator delete(void* ptr, size_t size)
{
	free(ptr);
};
void* operator new[](size_t size)
{
	return malloc(size);
};

