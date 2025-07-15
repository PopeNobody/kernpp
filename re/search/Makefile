MAKEFLAGS:= -rR -j20

all: tcgetattr isprint

all:
#CPPFLAGS:=-dMDNIU
CFLAGS:= -ggdb3 -g3 -ggdb -O0 
CXXFLAGS:= $(CFLAGS) -std=c++23
CC:=clang
CXX:= clang++

c:= $(wildcard *.c)
cc:= $(wildcard *.cc)

o:= $(c:.c=.o)
oo:=$(cc:.cc=.oo)

rvalue-ref: rvalue-ref.oo
	$(CXX) -o $@ $< 

x:= $(o:.o=)
xx:= $(oo:.oo=)

xx: $(xx)
x: $(x)
.PRECIOUS: %

show= $(warning $(eval $1=$$($1)))

# $(warning $(xx) $(oo) $(cc) )

$(o): %.o: %.c
	$(CC) $(CFLAGS) $< -o $@ -c

%: %.o
	$(CC) -o $@ $< $(LDFLAGS)


%.a: %.oo
	ar r $@ $<

%.oo: %.cc
	$(CXX) $(CXXFLAGS) $< -o $@ -c

%: %.a
	$(CXX) -o $@ $< $(LDFLAGS) 



%.S: %.c
	$(CC) -S -o $@ $<

%.i: %.c
	$(CC) -E -o $@ $< $(CFLAGS)

all: $(x) $(xx)
