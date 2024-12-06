obj-m := m1.o m2.o 
kdir = /lib/modules/$(shell uname -r)/build
pw := $(shell pwd)
all:
	$(MAKE) -C $(kdir) M=$(pw) modules
clean:
	$(MAKE) -C $(kdir) M=$(pw) clean
