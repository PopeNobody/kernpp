all: tcgetattr

CFLAGS:=-dMDNIU

tcgetattr.i: tcgetattr.c
	$(CC) -E -o $@ $< $(CFLAGS)
