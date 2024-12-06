#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/types.h>
#include<linux/kdev_t.h>



MODULE_LICENSE("GPL");
MODULE_AUTHOR("CDAC");
MODULE_DESCRIPTION("dynamic or automatic allocation of major and minor numbers");


dev_t dev = 0;
/*automatic : kernel initialises major and minor numbers*/
static int __init c_init(void){
    alloc_chrdev_region(&dev,0,2,"ya_ara");
    printk("automatic major and minor by kernel\n");
    printk("major: %d\n",MAJOR(dev));
     printk("minor: %d\n",MINOR(dev));
    printk("kernel mod inserted\n");
    return 0;
}


static void __exit c_exit(void){
     unregister_chrdev_region(dev,2);
    printk("\n----------------\n");
    printk("\n----------------\n");
    printk("\n----------------\n");
    printk("kernel mod removed \n");
}

module_init(c_init);
module_exit(c_exit);