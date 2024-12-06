obj-m := my_driver.o 
kdir = /lib/modules/$(shell uname -r)/build
pw := $(shell pwd)

all:    write1 write2 read 
	make -C $(kdir) M=$(pw) modules
clean:
	make -C $(kdir) M=$(pw) clean
write1:
	gcc write1.c -o write1
write2:
	gcc write2.c -o write2
read:
	gcc read.c -o read 
clea:
	rm -rf write1 write2 read

