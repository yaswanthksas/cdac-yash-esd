//headers 
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

//macros 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("CDAC");

static int __init hi_init(void){
    printk("hello ky");
    return 0;
}

static void __exit hi_exit(void){
    printk("bye ky");
}
module_init(hi_init);
module_exit(hi_exit);