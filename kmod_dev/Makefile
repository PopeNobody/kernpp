CONFIG_PROC_EX:=m

obj-$(CONFIG_PROC_EX) += proc_tree.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

Makefile: ;


test: demo-test
	echo tested

proc_tree: all
	-sudo rmmod proc_tree.ko
	sudo dmesg -c
	sudo insmod proc_tree.ko
	dmesg
	grep -n . /dev/null /proc/pstree
