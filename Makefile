test:
all:
include etc/vars.mk etc/util.mk
etc/multi.mk etc/cxxflags etc/ld_flags etc/cppflags etc/asmflags:;
all: lib bin tst



lib/lib:=lib/libkernpp.aa
abi/lib:=abi/libabi.aa

show= $(warning $1: $($1))
include etc/c++.mk
include etc/pl5.mk
include etc/asm.mk
$(c++/exe) $(asm/exe): $(lib/lib) $(abi/lib)
scr/genheaders.pl:;

$(c++/dep): clean-dep
include $(wildcard $(c++/dep))

all: $(c++/exe) $(asm/exe) lib
tst: $(c++/tst) $(asm/tst) $(pl5/tst)


test: tst
	$(foreach e,$(all/tst),./$e;)

$(c++/cpp): inc/syscall.gen.hh abi/syscall.gen.cc

obj: $(c++/obj) $(asm/obj) 
lib: $(lib/lib) $(abi/lib)

all/obj:= $(c++/obj) $(asm/obj)

all/exe:=$(c++/exe) $(c++/tst) $(asm/exe)
all/tst:
#    
all: $(all/exe)
$(foreach t,$(all/tst),$(eval $t/run: $t; $t)$(eval test: $t/run))

FORCE:

.PHONY: FORCE

inc/syscall.gen.hh abi/syscall.gen.cc: scr/genheaders.pl
	vi-perl scr/genheaders.pl
	mv gen/syscall.gen.hh inc/syscall.gen.hh
	mv gen/syscall.gen.cc abi/syscall.gen.cc

include etc/multi.mk
xtr/dep:=$(filter-out $(c++/dep),$(wildcard */*.dd))
clean-dep:
	$(if $(wildcard $(extra)),rm -f $(wildcard $(extra)))
clean: clean-dep
	$(foreach v,c++/obj c++/cpp c++/asm,$(if $(wildcard $v),rm -f $(wildcard $v)))

.PHONY: clean clean-dep
all:
	@echo made all
	@cp .gitignore .gitignore.old
	@printf '%s\n' $(all/exe) | sort .gitignore -u -o .gitignore -
	@report cmp -s .gitignore .gitignore.old || echo ".gitignore changed"


define lnk_libs
	-Wl,--start-group 
	$(lib/lib) 
	$(abi/lib) 
	-Wl,--end-group
	@etc/ld_flags 
endef
$(warning txt: $(lnk_libs))

cur:=$(filt <,etc/lnk_libs)
$(warning cur: $(cur/lnk_libs))
export lnk_libs
#    ifeq ($(txt),$(cur))
#    etc/lnk_libs:
#    	echo "$$x" | tee $@
#    endif


