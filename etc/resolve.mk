bin/exe:= $(patsubst %.cc,%,     $(bin/src))
bin/asm:= $(wildcard bin/*.S)
bin/xxx:= $(patsubst %.S,%.oo,$(bin/asm))
bin/exe+= $(patsubst %.S,%,      $(bin/asm))
bin/obj:= $(patsubst %.cc,%.oo,  $(bin/src))
bin/cpp:= $(patsubst %.cc,%.ii,  $(bin/src))
bin/dep:= $(patsubst %,%.d,$(bin/obj) $(bin/cpp))
bin:=$(bin/exe)

lib/src:= $(wildcard lib/*.cc)
lib/lib:= lib/libkpp.aa
lib/asm:= $(wildcard lib/*.S)
lib/xxx:= $(patsubst %.S,%.oo, $(lib/asm))
lib/obj:= $(patsubst %.cc,%.oo,  $(lib/src))
lib/cpp:= $(patsubst %.cc,%.ii,  $(lib/src))
lib/dep:= $(patsubst %.cc,%.oo.d,$(lib/src))
lib/dep:= $(patsubst %.cc,%.ii.d,$(lib/src))
lib:=$(lib/lib)

all/obj:= $(lib/obj) $(bin/obj)
all/xxx:= $(lib/xxx) $(bin/xxx)
all/cpp:= $(lib/cpp) $(bin/cpp)
all/src:= $(lib/src) $(bin/src)
all/dep:= $(lib/dep) $(bin/dep)
