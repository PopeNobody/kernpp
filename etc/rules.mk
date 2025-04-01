.SECONDEXPANSION:


all: $(P)

asm-src:=$(lib-$(sub)/asm)
asm-obj:=$(asm-src:=.oo)

%.SS.oo: %.SS  etc/asmflags
	as     -o "$@" $< @etc/asmflags

%.cc.oo: %.cc  etc/cxxflags
	g++ -c -o "$@" $< @etc/cppflags -MD -MT $@ -MF $@.dd


$(lib-$(sub)/lib): $(lib-$(sub)/obj)
	ar -r "$@" $($(sub)/obj)
	ranlib $@


$($(sub)/exe): %: %.oo etc/ld_flags $(lib/lib)
	ld --start-group $(all/lib) $< --end-group -o $@


