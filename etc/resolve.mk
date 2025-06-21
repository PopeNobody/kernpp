define nl



endef

dir/src:=bin lib
#    bin/exe:=$(filter bin/%,$(src/c++:.cc=)
#    tst/exe:=$(filter tst/%,$(src/c++:.cc=)
#    $(warning $(nl) SOURCES: )
#    #SHOW=$(eval $$(warning $1:  $$($1)))
#    $(foreach v,src/c++ src/asm src/mod,$(call SHOW,$v))
#    $(warning $(nl) EXECS:)
#    $(foreach v,bin/exe tst/exe,$(call SHOW,$v))
#    tgt/exe:=$(bin/exe) $(tst/exe)
#    tgt/cpp:=$(src/c++:=.ii)
#    tgt/dep:=$(tgt/cpp:=.dd)
#    tgt/asm:=$(src/c++:=.SS)
#    tgt/obj/c++:=$(src/c++:=.oo)
#    tgt/obj:=$(tgt/obj/c++) $(tgt/obj/c++)
#    $(warning $(nl) TARGETS:)
#    $(foreach v,exe lib cpp asm obj dep,$(call SHOW,tgt/$v))
#    tgt/all:=$(foreach v,cpp asm obj exe dep,$(tgt/$v))
#    $(warning $(nl)$(nl)$(nl) ALL TARGETS:)
#    $(foreach v,tgt/all,$(call SHOW,$v))

src/c++:=$(wildcard */*.cc)
c++/cpp:=$(src/c++:=.ii)
c++/asm:=$(src/c++:=.SS)
c++/obj:=$(src/c++:=.oo)
c++/exe:=$(src/c++:.cc=)


src/asm:=$(wildcard */*.S)
asm/obj:=$(src/asm:=.oo)
asm/exe:=$(asm/obj:.S=)

all/cpp:=$(c++/cpp)
all/asm:=$(c++/asm)
all/obj:=$(c++/obj) $(asm/obj)
all/exe:=$(c++/exe) $(asm/exe)
lib/obj:=$(filter lib/%,$(all/obj))


# lib/obj:=$(filter lib/%,$(tgt/obj))
# tgt/obj/asm:=$(src/asm:=.oo)
#    tst/exe+=$(src/asm:.S=))
#    tst/exe+=$(src/asm:.S=))


$(c++/cpp): %.cc.ii: %.cc  etc/cppflags
	sbin/g++ $@ $< @etc/cppflags 

$(c++/asm): %.SS: %.ii  etc/cxxflags
	sbin/g++ $@ $< @etc/cxxflags

$(c++/obj): %.oo: %.SS  etc/asmflags
	sbin/as  $@ $< @etc/asmflags

$(c++/exe): %: %.cc.oo etc/ld_flags $(lib/lib)
	sbin/ld $@ $< $(lib/lib) @etc/ldflags

$(asm/obj): %.S.oo: %.S
	sbin/as  $@ $< @etc/asmflags

$(asm/exe): %: %.S.oo

$(tgt/lib): $(lib/obj) etc/arflags
	sbin/ar $@ $(lib/obj)


/dev/null:;
%.mk:;
Makefile:;
$(wildcard etc/*flags):
