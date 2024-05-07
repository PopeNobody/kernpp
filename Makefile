MAKEFLAGS:= -rR -j24
.EXPORT_ALL_VARIABLED:
all:
define dir_infer

$1/src:=  $(wildcard  $1/*.cc)                         
$1/exe:=  $(patsubst  %.cc,%,   $($1/src))             
$1/asm:=  $(wildcard  $1/*.S)                          
$1/xxx:=  $(patsubst  %,%.o,   $($1/asm))             
$1/exe+=  $(patsubst  %,%,      $($1/asm))             
$1/obj:=  $(patsubst  %,%.o,   $($1/src))             
$1/cpp:=  $(patsubst  %,%.ii,   $($1/src))             
$1/dep:=  $(patsubst  %,%.d,    $($1/obj)   $($1/cpp)  $($1/asm))
$1:=$($1/exe)
endef
$(call dir_infir,bin,lib) 

#    lib/src:= $(wildcard lib/*.cc)
#    lib/lib:= lib/libkpp.a
#    lib/asm:= $(wildcard lib/*.S)
#    lib/xxx:= $(patsubst %.S,%.o, $(lib/asm))
#    lib/obj:= $(patsubst %.cc,%.o,  $(lib/src))
#    lib/cpp:= $(patsubst %.cc,%.ii,  $(lib/src))
#    lib/dep:= $(patsubst %.cc,%.o.d,$(lib/src))
#    lib/dep:= $(patsubst %.cc,%.ii.d,$(lib/src))
#    lib:=$(lib/lib)

all/obj:= $(lib/obj) $(bin/obj)
all/xxx:= $(lib/xxx) $(bin/xxx)
all/cpp:= $(lib/cpp) $(bin/cpp)
all/src:= $(lib/src) $(bin/src)
all/dep:= $(lib/dep) $(bin/dep)

include /dev/null $(wildcard $(all/dep))

ext/obj:= $(filter-out $(all/obj), $(wildcard *.o))
ext/xxx:= $(filter-out $(all/xxx), $(wildcard *.o))

all:= $(bin/exe) $(lib/lib)
bin:= $(bin/exe)
lib:= $(lib/lib)
$(bin): $(lib)
all: $(all)

include /dev/null $(wildcard $(all/dep))

$(lib/lib): $(lib/obj) $(lib/xxx)
	sbin/arch "$@" $(lib/obj) $(lib/xxx)

$(bin/exe): %: %.o sbin/link etc/ld_flags
	sbin/link "$@" $(lib/lib)

$(all/cpp): %.ii: %.cc sbin/prec etc/cppflags
	rm -f $*.ii $*.o
	sbin/prec "$@"

$(all/xxx): %.o: %.S sbin/casm etc/asmflags
	sbin/casm "$@"

$(all/obj): %.o: %.ii sbin/comp etc/cxxflags
	sbin/comp "$@"

cur/dep:=$(wildcard *.o.d)
cur/obj:=$(wildcard *.o) $(patsubst %.d,%,$(cur/dep))
cur/src:=$(patsubst %.o,%.cc,$(cur/obj))


ifneq ($(have),$(want))
$(lib/lib): rem-lib
endif

###   
clean: date:=$(shell serdate)

clean:
	rm -f */*.[ioad]

$(all/obj): sbin/comp
$(bin/exe): sbin/link
$(lib/lib): sbin/arch
$(bin/exe): $(lib)

tags: */*.cc */*.hh
	ctags --language-force=c++ */*.cc */*.hh

nm:
	nm */*.a */*.o --defined-only -A --demangle
