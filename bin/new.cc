#include <syscall.hh>
#include <stream.hh>
#include <new.hh>
#include <array.hh>

using namespace stream;


int main(int argc, char**argv) {
	fdbuf_t out(1);
	char msg[]="args:\n";
	out.put(msg);
	for(int i=0;i<argc;i++)
		out.put(argv[i]).put("\n");

	int* p1 = new int;
	delete p1;

	int* p2 = new int[10]; // guaranteed to call the replacement in C++11
	delete[] p2;
	return 0;
}
