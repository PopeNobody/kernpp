c++=ii dd SS oo
asm=oo
beg=c++ asm
c++/cc:=$(wildcard */*.cc)
c++/ii:=$(c++/cc:=.ii)
c++/dd:=$(c++/cc:=.dd)
c++/SS:=$(c++/cc:=.SS)
c++/oo:=$(c++/cc:=.oo)
asm/SS:=$(wildcard */*.S)
asm/oo:=$(asm/SS:=.o)

bin/c++:=$(filter bin/%,$(c++/cc:.cc=))
bin/asm:=$(filter bin/%,$(asm/SS:.S=))
tst/c++:=$(filter tst/%,$(c++/cc:.cc=))
tst/asm:=$(filter tst/%,$(asm/SS:.S=))
all: $(bin/c++) $(bin/asm) $(bin/tst)
#    $(warning $(bin/c++))
#    $(warning $(bin/asm))
lib/asm:=$(filter lib/%,$(asm/oo))
lib/c++:=$(filter lib/%,$(c++/oo))
#    $(warning $(lib/c++))
#    $(warning $(lib/asm))
lib/obj:=$(lib/asm) $(lib/c++)
