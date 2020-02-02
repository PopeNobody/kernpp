#include <sys/stat.h>

int main(int argc, char**argv) {
	struct stat buf;
	stat("/dev/null",&buf);
};
