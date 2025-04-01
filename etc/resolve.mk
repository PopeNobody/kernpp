RM_F=:

lib/lib := lib/liblib.a lib/libkernpp.a lib/liblinux.a

src/c++ = $(wildcard */*.cc)
src/asm = $(filter-out $(src/c++:.cc=.SS),$(wildcard */*.SS)
all/obj = $(src/c++:.cc=.oo) $(src/asm:.SS=.oo)
all/mod = $(all/obj:.oo=)
lib/dir = lib linux kernpp
bin/dir = bin 1ea tst

lib/lib = $(patsubst %,lib/lib%.a,$(lib/dir))
bin/pat = $(patsubst %,%/%,$(bin/dir))
bin/exe = $(filter $(bin/pat),$(src/c++:.cc=))
