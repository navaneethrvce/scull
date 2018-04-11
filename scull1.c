#include<linux/init.h>
#include<linux/module.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/kernel.h>
#include "scull1.h"

MODULE_LICENSE("Dual DSD/GPL");

MODULE_AUTHOR("Navaneeth Krishnan Yadunandanan");
MODULE_DESCRIPTION("Scull first version");

//Contains SCULL's major and minor numbers
dev_t dev;
int result;

static int scull_init(void)
{
    if(SCULL_MAJOR)
	{
        	dev = MKDEV(SCULL_MAJOR,SCULL_MINOR_START);
        	result = register_chrdev_region(dev,SCULL_COUNT,SCULL_NAME);
         }
    else
	result = alloc_chrdev_region(&dev,SCULL_MINOR_START,SCULL_COUNT,SCULL_NAME);
    if(result<0)
	printk(KERN_WARNING "scull1: Could not allocate device");
    else
	printk(KERN_WARNING "scull1: Registered with major number %i\n",MAJOR(dev));
    return 0;
}

static void scull_exit(void)
{
    unregister_chrdev_region(dev,SCULL_COUNT);
}

module_init(scull_init);
module_exit(scull_exit);
	
