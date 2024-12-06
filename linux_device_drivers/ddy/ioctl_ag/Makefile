obj-m := ker.o
kdir = /lib/modules/$(shell uname -r)/build
pw := $(shell pwd) 
default:
	make -C $(kdir) M=$(pw) modules 
clean:
	make -C $(kdir) M=$(pw) clean

