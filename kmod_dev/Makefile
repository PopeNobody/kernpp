obj-m += lkm_example.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

Makefile: ;


test: all
	-sudo rmmod lkm_example.ko
	sudo dmesg -c
	sudo insmod lkm_example.ko
	dmesg
