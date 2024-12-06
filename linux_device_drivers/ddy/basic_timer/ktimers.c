#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/timer.h>
#include<linux/jiffies.h>

static struct timer_list tim;
static int count = 0;

void tcall(struct timer_list *data){
    printk("Timer call back\n");
    count++;
    printk("count : %d\n",count);
    mod_timer(&tim,jiffies + msecs_to_jiffies(1000));
}
static int __init kt_init(void){
    printk("In kernel\n");
    timer_setup(&tim,tcall,0);
    mod_timer(&tim, jiffies + msecs_to_jiffies(1000));
    // printk("timer initialised %d\n",jiffies);
    return 0;
}
static void __exit kt_exit(void){
    del_timer(&tim);
    printk("out of kernel\n");
}

module_init(kt_init);
module_exit(kt_exit);

MODULE_AUTHOR("GPL");
MODULE_LICENSE("yash");
