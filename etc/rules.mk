
.SECONDEXPANSION:


all: $(P)

$(int/cpp): %.ii: %.cc  etc/cppflags
	rm -f $*.ii $*.ii.dd $*.oo $*.SS
	g++ -E -o "$@" $< @etc/cppflags -MD -MT $@ -MF $@.dd

$(int/asm): %.SS: %.ii  etc/cxxflags
	rm -f $*.SS $*.oo
	g++ -S -o "$@" $< @etc/cxxflags -MD -MT $@ -MF $@.dd


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

.PRECIOUS: $(int/cpp) $(int/asm)
$(all/exe): %: %.oo etc/ld_flags $(lib/lib)
	ld -o "$@" --start-group $< $(lib/lib) --end-group

$(all/obj): %.oo: %.SS  etc/asmflags
	as -o "$@" $< @etc/asmflags

$(sort $(int/cpp:.ii=.ii.dd)): ;

%/run: %
	./$<

%: %.c
	gcc -o $@ $<

