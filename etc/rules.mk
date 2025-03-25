
$(lib/lib): $(lib/obj)
	ar -r "$@" $(lib/obj) $(lib/xxx)

%: %.oo etc/ld_flags $(lib/lib)
	ld -o "$@" $< $(lib/lib)

%.ii: %.cc  etc/cppflags
	rm -f $*.ii $*.oo $*.S
	g++ -E -o "$@" $< @etc/cppflags -MD -MT $@ -MF $@.d

%.S: %.ii  etc/cxxflags
	rm -f $*.S $*.oo
	g++ -S -o "$@" $< @etc/cxxflags -MD -MT $@ -MF $@.d

%.oo: %.S  etc/asmflags
	as -o "$@" $< @etc/asmflags

%/run: %
	./$<

%: %.c
	gcc -o $@ $<
