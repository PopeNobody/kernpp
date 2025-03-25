
ifneq ($(wildcard sbin/genctype.c),)

all+=sbin/genctype

%.i: %.c
	gcc -o $@ $< -E -ggdb3
%.S: %.i
	gcc -o $@ $< -S -ggdb3
%.o: %.S
	gcc -o $@ $< -c -ggdb3
%: %.o
	gcc -o $@ $< -ggdb3

doit.c: sbin/genctype
	sbin/genctype > $@

all:
	./doit

all+=doit

.PRECIOUS: doit.i sbin/genctype.o doit.o sbin/genctype.i
.PRECIOUS: doit.S sbin/genctype.S

endif
