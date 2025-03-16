MAKEFLAGS:= -rR -j24
.EXPORT_ALL_VARIABLED:
all:

bin/src:= $(wildcard bin/*.cc)

include etc/resolve.mk $(wildcard $(all/dep))

ext/obj:= $(filter-out $(all/obj), $(wildcard *.oo))
ext/xxx:= $(filter-out $(all/xxx), $(wildcard *.oo))

all:= $(bin/exe) $(lib/lib) bin/echo
bin:= $(bin/exe)
lib:= $(lib/lib)
$(bin): $(lib)
all: $(all)

include /dev/null $(wildcard $(all/dep))

bin/echo: bin/printenv
	ln $< $@

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
