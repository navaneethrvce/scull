#If KERNELRELEASE is defined, we have been invoked from the
#kernel build system and we can use its language
ifneq ($(KERNELRELEASE),)
        obj-m := scull1.o
#Otherwise we were called directly from the command
#line; invoke the kernel build system
else
     
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
     	PWD := $(shell pwd)

default:

	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

endif
