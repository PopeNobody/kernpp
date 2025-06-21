MAKEFLAGS+= -rR -j1
#export override PATH:=$(PWD)/sbin:$(PATH)
SHELL:=/bin/bash -xe
all: lib bin tst

tgt/lib:=lib/libkernpp.aa
lib/lib:=lib/libkernpp.aa
include etc/resolve.mk
include etc/rules.mk
include $(wildcard $(all/dep))
clean_asm:=$(filter-out $(src/asm),$(all/asm))
clean:
	rm -f $(tgt/all)

all: $(tgt/all)
	@echo made all

deps= $(sort $(wildcard */*.ii.d))
cxxs= $(sort $(wildcard */*.cc))
cpps= $(cxxs:.cc=.ii)
include /dev/null  $(filter-out $(xtra),$(wildcard */*.dd))

src/c++:=$(wildcard */*.cc)
c++/obj:=$(src/c++:.cc=.oo)
c++/ebj:=$(filter bin/% tst/%,$(c++/obj))
c++/exe:=$(c++/ebj:.oo=)
c++/lib:=$(filter lib/%,$(c++/obj))

lib: $(c++/lib)
all: $(c++/exe)

src/asm:=$(wildcard */*.S)
asm/obj:=$(src/asm:.S=.oo)
asm/lib:=$(filter lib/%,$(asm/obj))
lib: $(asm/lib)

$(lib/lib): $(asm/lib) $(c++/lib)
	ar r $@ $(asm/lib) $(c++/lib)

all/obj:= $(c++/obj) $(asm/obj)

$(asm/obj): %.oo: %.S etc/asmflags
	as -o $@ $< @etc/asmflags


#    lib/abi.cc
#    lib/c_str.cc
#    lib/dbg.cc
#    lib/errno.cc
#    lib/getopt.cc
#    lib/init_array.cc
#    lib/search_path.cc
#    lib/strerror_list.cc
#    lib/unistd.cc
#    lib/write_buf.cc
#$(warning c++/obj)

$(c++/obj): %.oo: %.cc  etc/cxxflags etc/cppflags
	echo "cxx/obj:+ $(c++/obj)"
	g++  -o $@ -c $< @etc/cxxflags @etc/cppflags

all: $(c++/obj)

$(c++/exe): %: %.oo etc/ld_flags $(lib/lib)
	g++ -o $@ $< $(lib/lib) @etc/ld_flags
#    
#    $(asm/obj): %.S.oo: %.S
#    	sbin/as  $@ $< @etc/asmflags
#    
#    $(asm/exe): %: %.S.oo
#    
#    $(tgt/lib): $(lib/obj) etc/arflags
#    	sbin/ar $@ $(lib/obj)

#    $(c++/cpp): %.cc.ii: %.cc  etc/cppflags
#    	sbin/g++ $@ $< @etc/cppflags 
#    
#    $(c++/asm): %.SS: %.ii  etc/cxxflags
#    	sbin/g++ $@ $< @etc/cxxflags


/dev/null:;
%.mk:;
Makefile:;
$(wildcard etc/*flags):
