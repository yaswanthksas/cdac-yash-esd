#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("CDAC");

static char *c = "yas_ara";
static int x=23;
module_param(c,charp,S_IRUGO);
module_param(x,int,S_IRUGO);

static int __init b_init(void){
    printk("hello world\n");
    printk("%s",c);

    return 0;
}
static void __exit b_exit(void){
    printk("Bye\n");
    printk("number: %d\n",x);

}

module_init(b_init);
module_exit(b_exit);
