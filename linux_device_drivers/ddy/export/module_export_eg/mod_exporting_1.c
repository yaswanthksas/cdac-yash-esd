#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include"k_add.h"

MODULE_LICENSE("GPL");
MODULE_LICENSE("cdac");

int add(int a,int b){
    return a+b;
}

EXPORT_SYMBOL(add);

static int __init me_init(void){
    printk("We are in Kernel\n");
    return 0;
}

static void __exit me_exit(void){
    printk("We are exiting the kernel\n");
}

module_init(me_init);
module_exit(me_exit);