MAKEFLAGS:= -rR -j1
.EXPORT_ALL_VARIABLED:
all:

bin/src:= $(wildcard bin/*.cc)
bin/exe:= $(patsubst %.cc,%,     $(bin/src))
bin/obj:= $(patsubst %.cc,%.oo,  $(bin/src))
bin/cpp:= $(patsubst %.cc,%.ii,  $(bin/src))
bin/dep:= $(patsubst %,%.d,$(bin/obj))
bin:=$(bin/exe)

lib/src:= $(wildcard lib/*.cc)
lib/lib:= lib/libsimchat.aa
lib/obj:= $(patsubst %.cc,%.oo,  $(lib/src))
lib/cpp:= $(patsubst %.cc,%.ii,  $(lib/src))
lib/dep:= $(patsubst %.cc,%.oo.d,$(lib/src))
lib:=$(lib/lib)

all/obj:= $(lib/obj) $(bin/obj)
all/cpp:= $(lib/cpp) $(bin/cpp)
all/src:= $(lib/src) $(bin/src)
all/dep:= $(lib/dep) $(bin/dep)
ext/obj:= $(filter-out $(all/obj), $(wildcard *.oo))

all:= $(bin/exe) $(lib/lib)
bin:= $(bin/exe)
lib:= $(lib/lib)
$(bin): $(lib)
all: $(all)


include /dev/null $(wildcard $(all/dep))

$(bin/exe): %: %.oo
	sbin/link "$@"	

$(all/cpp): %.ii: %.cc
	rm -f $*.ii $*.oo
	sbin/prec "$@"

$(all/obj): %.oo: %.ii
	sbin/comp "$@"

cur/dep:=$(wildcard *.oo.d)
cur/obj:=$(wildcard *.oo) $(patsubst %.d,%,$(cur/dep))
cur/src:=$(patsubst %.oo,%.cc,$(cur/obj))


ifneq ($(have),$(want))
$(lib/lib): rem-lib
endif

$(lib/lib): $(lib/obj)
	sbin/arch "$@" $(lib/obj)

###   
clean: date:=$(shell serdate)

clean: sbin/clean
	sbin/clean $(wildcard */*.oo */*.aa */**.d bin/*.exe)

$(eval $(all/obj): sbin/comp)
$(eval $(bin/exe): sbin/link )
$(eval $(lib/lib): sbin/arch )
$(eval $(bin/exe): $(lib) )


###   
###   
