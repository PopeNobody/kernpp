MAKEFLAGS:= -rR -j20

#CPPFLAGS:=-dMDNIU
CFLAGS:= -ggdb3 -g3 -ggdb -O0 
CXXFLAGS:= $(CFLAGS) -std=c++23
CC:=gcc
CXX:= g++

c := $(wildcard *.c)
cc := $(wildcard *.cc)
$(foreach c,$(c),$(warning $c))

o:= $(c:.c=.o)
oo:=$(cc:.cc=.oo)

i:= $(c:.c=.i)
ii:= $(cc:.cc=.ii)


x:= $(o:.o=)
xx:= $(oo:.oo=)

xx: $(xx)
x: $(x)
.PRECIOUS: %

show= $(warning $(eval $1=$$($1)))


clean:
	rm -f $(i)
	rm -f $(o)
	rm -f $(e)

$(warning rule $(i))
$(i): %.i: %.c
	$(CC) $(CFLAGS) $< -o $@ -E

$(o): %.o: %.i
	$(CC) $(CFLAGS) $< -o $@ -c


$(x): %: %.o
	$(CC) -o $@ $< $(LDFLAGS)


%.a: %.oo
	ar r $@ $<

%.oo: %.cc
	$(CXX) $(CXXFLAGS) $< -o $@ -c

%: %.a
	$(CXX) -o $@ $< $(LDFLAGS) 



#    %.S: %.c
#    	$(CC) -S -o $@ $<
#    
#    %.i: %.c
#    	$(CC) -E -o $@ $< $(CFLAGS)

all: $(x) $(xx)
