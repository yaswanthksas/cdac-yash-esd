obj-m := tim.o 
kdir = /lib/modules/$(shell uname -r)/build
pw := $(shell pwd)
all:
	make -C $(kdir) M=$(pw) modules
clean:
	make -C $(kdir) M=$(pw) clean 
