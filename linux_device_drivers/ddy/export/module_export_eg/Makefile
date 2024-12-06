obj-m := mod_exporting_1.o mod_exported_2.o
kdir = /lib/modules/$(shell uname -r)/build
pw := $(shell pwd)

all:
	$(MAKE) -C $(kdir) M=$(pw) modules 
clean:
	$(MAKE) -C $(kdir) M=$(pw) clean
