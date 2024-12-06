#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include"add.h"

MODULE_LICENSE("GPL");

static int b=343;
static int a=12;

module_param(a,int,S_IRUGO);
module_param(b,int,S_IRUGO);

static int __init mod1_init(void){
    // printk("Entering kernel\n");
    printk("sum : %d\n",add(a,b));
    printk("jio: : :\n");

    return 0;
}
static void __exit mod2_exit(void){
    printk("exiting kernel\n");

    printk("bye\n");

}

module_init(mod1_init);
module_exit(mod2_exit);
