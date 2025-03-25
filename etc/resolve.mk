define search_dir
$1/src:= $$(wildcard $1/*.cc)
$1/mod:= $$($1/src:.cc=)
$1/cpp:= $$($1/mod:=.ii)
$1/asm:= $$($1/mod:=.SS)
$1/obj:= $$($1/mod:=.oo)
ifeq ($1,lib)
else
$1/exe:= $$($1/mod)
endif
endef
$(eval $(call search_dir,bin))


all/obj:= $(lib/obj) $(bin/obj)
all/xxx:= $(lib/xxx) $(bin/xxx)
all/cpp:= $(lib/cpp) $(bin/cpp)
all/src:= $(lib/src) $(bin/src)
all/dep:= $(lib/dep) $(bin/dep)
