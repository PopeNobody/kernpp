RM_F=:

lib/lib := lib/liblib.a lib/libkernpp.a lib/liblinux.a

src/c++ =$(wildcard */*.cc)
int/cpp =$(src/c++:.cc=.ii)
int/asm =$(src/c++:.cc=.SS)
src/asm =$(filter-out $(int/asm),$(wildcard */*.SS))
src/all =$(src/c++) $(src/asm)
dir/all =$(patsubst %/,%,$(dir $(src/all)))
dir/lib =$(patsubst lib/lib%.a,%,$(lib/lib))
dir/bin =$(filter-out $(dir/lib),$(dir/all))

all/mod =$(src/c++:.cc=) $(src/asm:.SS=)
all/asm =$(all/c++:.cc=.SS) $(src/asm)
all/obj =$(all/mod:=.oo)
all/exe:=$(filter $(dir/bin:=/%),$(all/mod))

all/dir =$(sort $(patsubst %/,%,$(dir $(all/obj))))
dir_obj= $(eval $1/obj = $(filter $1/%,$(all/obj)))
$(foreach d,$(all/dir),$(eval $$(call dir_obj,$d)))

vars:=
vars+= all/asm all/dir all/mod all/obj dir/all dir/bin dir/lib
vars+= int/asm int/cpp lib/lib src/all src/asm src/c++
define lines

src/c++:=$(src/c++)
int/cpp:=$(int/cpp)
int/asm:=$(int/asm)
src/asm:=$(src/asm)
all/obj:=$(all/obj)

endef

types:= cc ii SS oo 
all/c++:= $(sort $(foreach t,ii SS oo,$(patsubst %.cc,%.$t,$(src/cpp))))
all/asm:= $(sort $(foreach t,oo      ,$(patsubst %.SS,%.$t,$(src/asm))))
all/all:= $(all/c++) $(all/asm)
.PRECIOUS: $(all/all)
all: $(all/all)






