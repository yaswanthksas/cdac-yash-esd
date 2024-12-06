#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");

int add(int a,int b){
    return a+b;
}

EXPORT_SYMBOL(add);

static int __init mod1_init(void){
    printk("Entering kernel\n");
    return 0;
}
static void __exit mod2_exit(void){
    printk("exiting kernel\n");
}

module_init(mod1_init);
module_exit(mod2_exit);

