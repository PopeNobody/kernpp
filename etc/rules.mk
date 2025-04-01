
.SECONDEXPANSION:


all: $(P)

lib/libkernpp.a: $(kernpp/obj)
	ar -r "$@" $(kernpp/obj)
	ranlib $@

lib/liblinux.a: $(linux/obj)
	ar -r "$@" $(linux/obj)
	ranlib $@

lib/liblib.a: $(lib/obj)
	ar -r "$@" $(lib/obj) 
	ranlib $@

%.nm: lib/lib%.a
	nm -A $< | tee $@


%: %.oo etc/ld_flags $(lib/lib)
	ld -o "$@" --start-group $< $(lib/lib) --end-group

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
