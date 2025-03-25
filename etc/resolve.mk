all:=
all/var:=
define scandir
$1/var = src src/c++ src/asm mod mod/c++ mod/asm asm exe obj cpp dep all
$1/mod/c++ = $$($1/src/c++:.cc=)
$1/cpp = $$($1/mod/c++:=.ii)
$1/src/c++ := $$(wildcard $1/*.cc)
$1/src/asm = $$(filter-out $$($1/mod/c++:=.S),$$(wildcard $1/*.S))
$1/mod/asm = $$($1/src/asm:.S=)
$1/mod = $$($1/mod/c++) $$($1/mod/asm)
$1/src = $$($1/src/c++) $$($1/src/asm)
$1/asm = $$($1/mod:=.S)
$1/obj = $$($1/mod:=.oo)
$1/all = $$($1/cpp) $$($1/obj) $$($1/lib) $$($1/exe) $$(filter-out $$($1/src/asm),$$($1/asm))
# $1 = $$($1/exe) $$($1/lib)
dir += $1
all += $$($1)
all/var += $$(patsubst %,$1/%,$$($1/var))
$1= $$($1/exe) $$($1/lib)
$1: $$($1)
.PHONY: $1
.PRECIOUS: $$($1/all)
endef
save.and.eval=$(eval $1.resolve:=$$(call scandir,$1)) $(eval $($1.resolve)) 
tst/exe = $(tst/mod)
bin/exe = $(bin/mod)
lib/lib:=lib/libkernpp.a
$(foreach d,lib tst bin,$(call save.and.eval,$d))
