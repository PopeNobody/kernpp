CONFIG_PROC_EX:=m

test_pstree:

obj-$(CONFIG_PROC_EX) += pstree.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

Makefile: ;


test: demo-test
	echo tested

test_pstree: all
	-sudo rmmod pstree.ko
	sudo dmesg -c
	sudo insmod pstree.ko
	dmesg
	perl mktree.pl
