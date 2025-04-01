
src/c++ =$(wildcard */*.cc)
P+=$(src/c++)
src/asm =$(wildcard */*.SS)
P+=$(src/asm)
int/cpp =$(src/c++:.cc=.ii)
P+=$(int/cpp)
int/asm =$(src/c++:.cc=.SS)
P+=$(int/asm)
all/asm =$(src/asm) $(int/asm)
P+=$(all/asm)
all/obj =$(all/asm:.SS=.oo)
P+=$(all/obj)
bin/obj =$(filter bin/%,$(all/obj))
P+=$(bin/obj)
bin/exe = $(bin/obj:.oo=)
P+=$(bin/exe)
lib/obj = $(filter lib/%,$(all/obj))
P+=$(lib/obj)
kernpp/obj = $(filter kernpp/%,$(all/obj))
P+=$(kernpp/obj)
linux/obj =$(filter linux/%,$(all/obj))
P+=$(linux/obj)
tst/obj = $(filter tst/%,$(all/obj))
P+=$(tst/obj)
tst/exe = $(tst/obj:.oo=)
P+=$(tst/exe)
lib/obj = $(filter lib/%,$(all/obj))
P+=$(lib/obj)

lib/lib+= lib/libkernpp.a lib/liblinux.a lib/liblib.a

.PRECIOUS: $(P)

USE/obj = $(bin/obj) $(linux/obj) $(kernpp/obj) $(tst/obj) $(lib/obj)
NOUSE/obj = $(filter-out $(USE/obj),$(all/obj))

ifneq ($(NOUSE/obj),)
$(error NOUSE/obj:=$(NOUSE/obj))
endif

