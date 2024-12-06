#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

#include<linux/types.h>
#include<linux/kdev_t.h>
#include<linux/fs.h>
#include<linux/cdev.h>

#include<linux/timer.h>
#include<linux/jiffies.h>

unsigned int TIMEOUT = 1000;

static struct timer_list tim;
static unsigned int count = 0;

dev_t dev =  0;
static struct cdev c_dev;

static ssize_t t_read (struct file *, char __user *, size_t, loff_t *);
static ssize_t t_write (struct file *, const char __user *, size_t, loff_t *);
static int t_open (struct inode *, struct file *);
static int t_close (struct inode *, struct file *);

static ssize_t t_read (struct file *a, char __user *b, size_t c, loff_t *d){
    printk("Driver read\n");
    return 0;
}
static ssize_t t_write (struct file *a, const char __user *b, size_t c, loff_t *d){
    printk("Driver written\n");
    return c;
}
static int t_open (struct inode *a, struct file *b){
    printk("Driver opened\n");
    return 0;
}
static int t_close (struct inode *a, struct file *b){
    printk("Driver closed\n");
    return 0;
}


static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = t_open,
    .release = t_close,
    .read = t_read,
    .write = t_write
};

void timer_callback(struct timer_list *data){
    printk("Timer callback function called %d\n",count++);

    mod_timer(&tim,jiffies + msecs_to_jiffies(TIMEOUT));

}

static int __init t_init(void){
    printk("In the kernel\n");
    alloc_chrdev_region(&dev,0,1,"tim_name");
    printk("Major : %d\n",MAJOR(dev));
    printk("Minor : %d\n",MINOR(dev));
    cdev_init(&c_dev,&fops);
    cdev_add(&c_dev,dev,1);

    timer_setup(&tim,timer_callback,0);

    mod_timer(&tim,jiffies + msecs_to_jiffies(TIMEOUT));

    return 0;
}

static void __exit t_exit(void){
    del_timer(&tim);
    cdev_del(&c_dev);
    unregister_chrdev_region(dev,1);
    printk("Out of kernel\n");
}


module_init(t_init);
module_exit(t_exit);

MODULE_AUTHOR("GPL");
MODULE_LICENSE("yash");

