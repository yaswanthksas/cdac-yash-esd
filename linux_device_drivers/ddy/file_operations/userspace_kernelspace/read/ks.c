#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/uaccess.h>
uint8_t str[1024]="hello I am in kernal";
dev_t dev = 0;
static struct cdev c_dev;
static ssize_t y_read (struct file *, char __user *, size_t, loff_t *);
static ssize_t y_write (struct file *, const char __user *, size_t, loff_t *);
static int y_close (struct inode *, struct file *);
static int y_open (struct inode *, struct file *);
static struct file_operations fops={
    .owner = THIS_MODULE,
    .open = y_open,
    .release = y_close,
    .read = y_read,
    .write = y_write
};
static ssize_t y_read (struct file *a, char __user *b, size_t c, loff_t *d){
    // printk("driver is read\n");
    unsigned long int s;
    s=copy_to_user(b,str,1024);
    if(s != c){
        printk("copy to user succesful\n");
    }
    return 0;

}
static ssize_t y_write (struct file *a, const char __user *b, size_t c, loff_t *d){
    printk("driver written\n");
    return c;
}
static int y_close (struct inode *a, struct file *b){
    printk("Driver closed\n");
    return 0;
}
static int y_open (struct inode *a, struct file *b){
    printk("Driver opened\n");
    return 0;
}

static int __init k_init(void){
    printk("In kernel \n");
    alloc_chrdev_region(&dev,0,1,"ker_user_file");
    printk("Major: %d\n",MAJOR(dev));
    printk("Minor: %d\n",MINOR(dev));

    cdev_init(&c_dev,&fops);
    cdev_add(&c_dev,dev,1);
    
    return 0;
}

static void __exit k_exit(void){

    unregister_chrdev_region(dev,1);
    printk("Exit from kernel\n");
}

module_init(k_init);
module_exit(k_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("cdac");

