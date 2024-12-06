#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/cdev.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("CDAC");

dev_t dev = 0;
static struct cdev my_cdev;
static ssize_t yash_read (struct file *, char __user *, size_t, loff_t *);
static ssize_t yash_write (struct file *, const char __user *, size_t, loff_t *);
static int yash_open (struct inode *, struct file *);
static int yash_close (struct inode *, struct file *);

static struct file_operations foper = {
    .owner = THIS_MODULE,
    .read = yash_read,
    .write = yash_write,
    .release = yash_close,
    .open = yash_open,
};

static int yash_open (struct inode *a, struct file *b){
    printk("Driver opened\n");
    return 0;
}

static ssize_t yash_write (struct file *a, const char __user *b, size_t x, loff_t *re){
    printk("Driver written\n");
    return x;
}

static ssize_t yash_read (struct file *a, char __user *b, size_t c, loff_t *d){
    printk("Driver read\n");
    return 0;
}
static int yash_close (struct inode *a, struct file *b){
    printk("Driver closed\n");
    return 0;
}

static int __init f_init(void){
    alloc_chrdev_region(&dev,0,1,"dev_file");
    printk("Insert into Module\n");
    printk("Major : %d\n",MAJOR(dev));
    printk("Minor : %d\n",MINOR(dev));
    /*registration */
    cdev_init(&my_cdev,&foper);
    int y=cdev_add(&my_cdev,dev,1);
    printk("%d\n",y);

    return 0;
}
static void __exit f_exit(void){
    cdev_del(&my_cdev);
    unregister_chrdev_region(dev,1);
    printk("Exit from module\n");
}

module_init(f_init);
module_exit(f_exit);
