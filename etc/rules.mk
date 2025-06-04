
$(lib/lib): $(lib/obj)
	ar -r "$@" $(lib/obj) $(lib/xxx)

%: %.oo etc/ld_flags $(lib/lib)
	ld -o "$@" $< $(lib/lib)

%.ii: %.cc  etc/cppflags
	rm -f $*.ii $*.oo $*.SS
	g++ -E -o "$@" $< @etc/cppflags -MD -MT $@ -MF $@.dd

%.SS: %.ii  etc/cxxflags
	rm -f $*.SS $*.oo
	g++ -S -o "$@" $< @etc/cxxflags -MD -MT $@ -MF $@.dd

%.oo: %.SS  etc/asmflags
	as -o "$@" $< @etc/asmflags

%/run: %
	./$<

%: %.c
	gcc -o $@ $<
