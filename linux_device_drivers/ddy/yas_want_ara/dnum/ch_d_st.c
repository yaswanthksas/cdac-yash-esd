#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/types.h>
#include<linux/kdev_t.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("CDAC");
MODULE_DESCRIPTION("statical or manual allocation of major and minor numbers");

dev_t dev = MKDEV(100,0);

static int __init char_init(void){
    register_chrdev_region(dev,1,"chDevi");
    printk("\n----------------\n");
    printk("\n----------------\n");
    printk("\n----------------\n");
    printk("major: %d\n",MAJOR(dev));
    printk("minor: %d\n",MINOR(dev));
    printk("kernel mod inserted\n");
    return 0;
}

static void __exit char_exit(void){
    unregister_chrdev_region(dev,1);
    printk("\n----------------\n");
    printk("\n----------------\n");
    printk("\n----------------\n");
    printk("kernel mod removed \n");
}

module_init(char_init);
module_exit(char_exit);
