CONFIG_PROC_EX:=m

obj-$(CONFIG_PROC_EX) += proc_ex.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

Makefile: ;


test: demo-test

dev-test: all
	-sudo rmmod dev_ex.ko
	sudo dmesg -c
	sudo insmod dev_ex.ko
	dmesg

demo-test: all
	-sudo rmmod demo.ko
	sudo dmesg -c
	sudo insmod demo.ko
	dmesg

proc-test: all
	-sudo rmmod proc_ex.ko
	sudo dmesg -c
	sudo insmod proc_ex.ko
	dmesg
	grep -n . /dev/null /proc/pstree
