#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/fs.h>
#include<linux/err.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/types.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("CDAC");
MODULE_DESCRIPTION("dynamic or automatic allocation of major and minor numbers and doing file operations ");


dev_t dev = 0;
static struct cdev file_cdev;

// int (*open) (struct inode *, struct file *);
static int file_open (struct inode *a, struct file *b);
// ssize_t (*read) (struct file *, char __user *, size_t, loff_t *);
static ssize_t file_read (struct file *, char __user *, size_t , loff_t *);
static ssize_t file_write (struct file *, const char __user *, size_t, loff_t *);
static int file_release (struct inode *, struct file *);


static struct file_operations fops ={
    .owner = THIS_MODULE,
    .read = file_read,
    .write = file_write,
    .open = file_open,
    .release = file_release,

};

static int file_open(struct inode *inode, struct file *file)
{
        pr_info("Driver Open Function Called...!!!\n");
        return 0;
}



static int file_release(struct inode *inode, struct file *file)
{
        pr_info("Driver Release Function Called...!!!\n");
        return 0;
}



static ssize_t file_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
        pr_info("Driver Read Function Called...!!!\n");
        return 0;
}


static ssize_t file_write(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
        pr_info("Driver Write Function Called...!!!\n");
        return len;
}

static int __init file_op_init(void){
    alloc_chrdev_region(&dev,0,1,"d_name");    //device driver  /*device name*/
    printk("Major: %d\n",MAJOR(dev));
    printk("Minor: %d\n",MINOR(dev));
    
    /*char device registration d_name*/
    
    cdev_init(&file_cdev,&fops);    /*representation of character devices*/

    cdev_add(&file_cdev,dev,1);


    printk("Device Driver Insert...\n");
    return 0;
}

static void __exit file_op_exit(void){
    cdev_del(&file_cdev);
    unregister_chrdev_region(dev,1);
    printk("Device Driver Remove...\n");
}


module_init(file_op_init);
module_exit(file_op_exit);
