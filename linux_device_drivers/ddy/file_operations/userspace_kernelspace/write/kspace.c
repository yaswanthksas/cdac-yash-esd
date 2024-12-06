#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/uaccess.h>
// static ssize_t y_read (struct file *, char __user *, size_t, loff_t *);
static ssize_t y_write (struct file *, const char __user *, size_t, loff_t *);
static int y_open (struct inode *, struct file *);
static int y_close (struct inode *, struct file *);


char str[1024];

dev_t dev = 0;
static struct cdev c_dev;
static struct file_operations fo = {
    .owner = THIS_MODULE,
    .open = y_open,
    .release = y_close,
    .write = y_write,
    // .read = y_read
};
static ssize_t y_write (struct file *a, const char __user *b, size_t c, loff_t *d){
    // printk("writing to driver\n");
    copy_from_user(str,b,c);
    printk("%s\n",str);
    return c;
}
static int y_open (struct inode *a, struct file *b){
    printk("Driver is open\n");
    return 0;
}
static int y_close (struct inode *a, struct file *b){
    printk("Driver is closed\n");
    return 0;
}


static int k_init(void){
    printk("In kernel\n");
    alloc_chrdev_region(&dev,0,1,"user_ker_file");
    printk("Major: %d\n",MAJOR(dev));
    printk("Minor: %d\n",MINOR(dev));

    /*device registration */
    cdev_init(&c_dev,&fo);
    cdev_add(&c_dev,dev,1);

    return 0;
}

static void k_exit(void){
    cdev_del(&c_dev);
    unregister_chrdev_region(dev,1);
    printk("exit from kernel\n");
}

module_init(k_init);
module_exit(k_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("CDAC");

