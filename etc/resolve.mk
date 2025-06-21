dir/src:=bin lib tst
src/c++:=$(foreach d,$(dir/src),$(wildcard $d/*.cc))
src/asm:=$(foreach d,$(dir/src),$(wildcard $d/*.S))
src/mod:=$(src/c++) $(src/asm)
SHOW=$(eval $$(warning $1:  $$($1)))
$(foreach v,src/c++ src/asm,$(call SHOW,$v))

#$(warning $(call SHOW,src/c++))
#src/exe:=$(filter bin/%,$(src/mod)) $(filter tst/%,$(src/mod))
#all/c++:=$(src/c++)
#all/dep:=$(src/c++:=.dd)
#all/cpp:=$(all/c++:=.ii)
#gen/asm:=$(src/c++:=.SS)
#all/asm:=$(src/asm) $(gen/asm)
#all/obj:=$(all/asm:=.oo)
#lib/obj:=$(filter lib/%,$(all/obj))
#all/exe:=$(src/exe)
#
#all: $(all/exe)
