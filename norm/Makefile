MAKEFLAGS= -rR

all: powers strerror
	
powers: powers.cc



%: %.cc
	g++ -static -g -E $@.cc -o $@.i -fPIC -dD
	g++ -static -g -S $@.i -o $@.s -fPIC
	g++ -static -g -c $@.s -o $@.o -fPIC
	g++ -static -g    $@.o -o $@ -fPIC
