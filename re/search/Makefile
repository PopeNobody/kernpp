all:
MAKEFLAGS:= -rR -j20

#CPPFLAGS:=-dMDNIU
CFLAGS:= -ggdb3 -g3 -ggdb -O0 
CXXFLAGS:= $(CFLAGS) -std=c++23
CC:=gcc
CXX:= g++

c := $(wildcard *.c)
cc := $(wildcard *.cc)

o:= $(c:.c=.o)
oo:=$(cc:.cc=.oo)

i:= $(c:.c=.i)
ii:= $(cc:.cc=.ii)


x:= $(c:.c=)
xx:= $(cc:.cc=)

#$(foreach v, i ii o oo x xx, $(warning $v:=$($v)))
$(foreach v, i ii o oo x xx, $(eval $v: $($v)))

xx: $(xx)
x: $(x)

.PRECIOUS: %

show= $(warning $(eval $1=$$($1)))


clean:
	rm -f $(i)
	rm -f $(o)
	rm -f $(x)
	rm -f $(ii)
	rm -f $(oo)
	rm -f $(xx)

$(ii): %.ii: %.cc
	$(CXX) $(CXXFLAGS) $< -o $@ -E

$(i): %.i: %.c
	$(CC) $(CFLAGS) $< -o $@ -E

$(o): %.o: %.i
	$(CC) $(CFLAGS) $< -o $@ -c

$(oo): %.oo: %.cc
	$(CXX) $(CXXFLAGS) $< -o $@ -c

$(x): %: %.o
	$(CC) -o $@ $< $(LDFLAGS)

$(xx): %: %.oo
	$(CXX) -o $@ $< $(LDFLAGS)


all: x xx o oo i ii 

.PRECIOUS: $(i) $(o) $(x) $(ii) $(oo) $(xx)
