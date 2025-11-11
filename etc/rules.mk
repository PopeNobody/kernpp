
$(lib/lib): $(lib/obj)
	ar -r "$@" $(lib/obj) $(lib/xxx)

$(c++/ii): %.cc.ii: %.cc  etc/cppflags
	rm -f $*.ii $*.oo $*.S
	g++ -E -o "$@" $< @etc/cppflags -MD -MT $@ -MF $@.d

$(c++/SS): %.SS: %.ii  etc/cxxflags
	rm -f $*.S $*.oo
	g++ -S -o "$@" $< @etc/cxxflags -MD -MT $@ -MF $@.d

$(c++/oo): %.oo: %.SS  etc/asmflags
	as -o "$@" $< @etc/asmflags

$(tst/c++): %: %.cc.oo etc/ld_flags $(lib/lib)
	ld -o "$@" $< $(lib/lib)

$(bin/c++): %: %.cc.oo etc/ld_flags $(lib/lib)
	ld -o "$@" $< $(lib/lib)

$(tst/asm): %: %.S.o
	ld -o "$@" $<

$(bin/asm): %: %.S.o
	ld -o "$@" $<

$(asm/oo): %.S.o: %.S etc/asmflags
	as -o $@ $<

%/run: %
	./$<

%: %.c
	gcc -o $@ $<
