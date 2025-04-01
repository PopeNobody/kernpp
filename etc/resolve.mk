RM_F=:

src/c++ =$(wildcard */*.cc)
int/cpp =$(src/c++:.cc=.ii)
int/asm =$(src/c++:.cc=.SS)
src/asm =$(filter-out $(int/asm),$(wildcard */*.SS))
src/cpp =$(filter-out $(int/cpp),$(wildcard */*.ii))
all/asm =$(src/asm) $(int/asm)
all/obj =$(all/asm:.SS=.oo)
all/mod =$(patsubst %.oo,%,$(all/obj))
all/dir =$(sort $(patsubst %/,%,$(dir $(all/obj))))

types:= .cc .ii .SS .oo 
all/all = $(sort $(foreach t,$(types),$(patsubst %.oo,%.$t,$(all/obj))))
.PRECIOUS: $(all/all)

dir_obj= $(eval $1/obj = $(filter $1/%,$(all/obj)))
$(foreach d,$(all/dir),$(eval $$(call dir_obj,$d)))

lib/lib := lib/liblib.a lib/libkernpp.a lib/liblinux.a




