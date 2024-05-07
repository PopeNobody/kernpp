MAKEFLAGS:= -rR -j24
.EXPORT_ALL_VARIABLED:
all:

bin/src:= $(wildcard bin/*.cc)
bin/exe:= $(patsubst %.cc,%,     $(bin/src))
bin/asm:= $(wildcard bin/*.S)
bin/xxx:= $(patsubst %.S,%.oo,$(bin/asm))
bin/exe+= $(patsubst %.S,%,      $(bin/asm))
bin/obj:= $(patsubst %.cc,%.oo,  $(bin/src))
bin/cpp:= $(patsubst %.cc,%.ii,  $(bin/src))
bin/dep:= $(patsubst %,%.d,$(bin/obj) $(bin/cpp))
bin:=$(bin/exe)

lib/src:= $(wildcard lib/*.cc)
lib/lib:= lib/libkpp.aa
lib/asm:= $(wildcard lib/*.S)
lib/xxx:= $(patsubst %.S,%.oo, $(lib/asm))
lib/obj:= $(patsubst %.cc,%.oo,  $(lib/src))
lib/cpp:= $(patsubst %.cc,%.ii,  $(lib/src))
lib/dep:= $(patsubst %.cc,%.oo.d,$(lib/src))
lib/dep:= $(patsubst %.cc,%.ii.d,$(lib/src))
lib:=$(lib/lib)

all/obj:= $(lib/obj) $(bin/obj)
all/xxx:= $(lib/xxx) $(bin/xxx)
all/cpp:= $(lib/cpp) $(bin/cpp)
all/src:= $(lib/src) $(bin/src)
all/dep:= $(lib/dep) $(bin/dep)

include /dev/null $(wildcard $(all/dep))

ext/obj:= $(filter-out $(all/obj), $(wildcard *.oo))
ext/xxx:= $(filter-out $(all/xxx), $(wildcard *.oo))

all:= $(bin/exe) $(lib/lib)
bin:= $(bin/exe)
lib:= $(lib/lib)
$(bin): $(lib)
all: $(all)

include /dev/null $(wildcard $(all/dep))

$(lib/lib): $(lib/obj) $(lib/xxx)
	sbin/arch "$@" $(lib/obj) $(lib/xxx)

$(bin/exe): %: %.oo sbin/link etc/ld_flags
	sbin/link "$@" $(lib/lib)

$(all/cpp): %.ii: %.cc sbin/prec etc/cppflags
	rm -f $*.ii $*.oo
	sbin/prec "$@"

$(all/xxx): %.oo: %.S sbin/casm etc/asmflags
	sbin/casm "$@"

$(all/obj): %.oo: %.ii sbin/comp etc/cxxflags
	sbin/comp "$@"

cur/dep:=$(wildcard *.oo.d)
cur/obj:=$(wildcard *.oo) $(patsubst %.d,%,$(cur/dep))
cur/src:=$(patsubst %.oo,%.cc,$(cur/obj))


ifneq ($(have),$(want))
$(lib/lib): rem-lib
endif

###   
clean: date:=$(shell serdate)

clean:
	rm -f */*.[ioa][ioa]

$(all/obj): sbin/comp
$(bin/exe): sbin/link
$(lib/lib): sbin/arch
$(bin/exe): $(lib)

tags: */*.cc */*.hh
	ctags --language-force=c++ */*.cc */*.hh

nm:
	nm */*.aa */*.oo --defined-only -A --demangle
