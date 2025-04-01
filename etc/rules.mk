
.SECONDEXPANSION:


all: $(P)

$(warning $(all/lib))

$($(sub)/asm:.SS+.oo): %.oo: %.SS  etc/asmflags
	as     -o "$@" $< @etc/asmflags

$($(sub)/c++:.cc=.oo): %.oo: %.cc  etc/cxxflags
	g++ -c -o "$@" $< @etc/cppflags -MD -MT $@ -MF $@.dd

$($(sub)/lib): $($(sub)/obj)
	ar -r "$@" $($(sub)/obj)
	ranlib $@


$($(sub)/exe): %: %.oo etc/ld_flags $(lib/lib)
	ld --start-group $(all/lib) $< --end-group -o $@


