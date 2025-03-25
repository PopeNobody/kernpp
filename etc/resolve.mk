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
# dir += $1
# all += $$($1)
# all/var += $$(patsubst %,$1/%,$$($1/var))
$1= $$($1/exe) $$($1/lib)
$1: $$($1)
.PHONY: $1
.PRECIOUS: $$($1/all)
endef
#$(warning $(scandir))
#$(warning $(call scandir,bin))
tst/exe = $(tst/mod)
bin/exe = $(bin/mod)
tst.resolve:=$(call scandir,tst)
bin.resolve:=$(call scandir,bin)
lib.resolve:=$(call scandir,lib)
lib/lib:=lib/libkernpp.a
$(eval $(tst.resolve))
$(eval $(lib.resolve))
$(eval $(bin.resolve))
