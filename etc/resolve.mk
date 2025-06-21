define nl



endef

dir/src:=bin lib tst
src/c++:=$(foreach d,$(dir/src),$(wildcard $d/*.cc))
src/asm:=$(foreach d,$(dir/src),$(wildcard $d/*.S))
bin/exe:=$(filter bin/%,$(src/c++:.cc=) $(src/asm:.S=))
tst/exe:=$(filter tst/%,$(src/c++:.cc=) $(src/asm:.S=))
$(warning $(nl) SOURCES: )
SHOW=$(eval $$(warning $1:  $$($1)))
$(foreach v,src/c++ src/asm src/mod,$(call SHOW,$v))
$(warning $(nl) EXECS:)
$(foreach v,bin/exe tst/exe,$(call SHOW,$v))
tgt/exe:=$(bin/exe) $(tst/exe)
tgt/cpp:=$(src/c++:=.ii)
tgt/dep:=$(tgt/cpp:=.dd)
tgt/asm:=$(src/c++:=.SS)
tgt/obj:=$(src/c++:=.oo) $(src/asm:=.oo)
$(warning $(nl) TARGETS:)
$(foreach v,tgt/cpp tgt/asm tgt/obj tgt/exe tgt/dep,$(call SHOW,$v))
tgt/all:=$(foreach v,cpp asm obj exe dep,$(tgt/$v))
$(warning $(nl)$(nl)$(nl) ALL TARGETS:)
$(foreach v,tgt/all,$(call SHOW,tgt/all))
