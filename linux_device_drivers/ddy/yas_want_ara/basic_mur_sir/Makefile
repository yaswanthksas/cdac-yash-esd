obj-m := basic.o
kdir = /lib/modules/$(shell uname -r)/build
Pw := $(shell pwd)

all:
	make -C $(kdir) M=$(Pw) modules
clean:
	make -C $(kdir) M=$(Pw) clean 
