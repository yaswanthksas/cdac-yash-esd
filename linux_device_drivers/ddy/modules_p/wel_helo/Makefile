obj-m := mod_par.o 

kdir = /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

all:
	$(MAKE) -C $(kdir) M=$(PWD) modules 

clean:
	$(MAKE) -C $(kdir) M=$(PWD) clean 

