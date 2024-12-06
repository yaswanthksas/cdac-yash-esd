#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>

#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/uaccess.h>

#define i_s_m _IOR('q',1,char *)
#define i_g_m _IOW('q',2,char *)



dev_t dev = 0;
static struct cdev c_dev;
static int k_open (struct inode *, struct file *);
static int k_release (struct inode *, struct file *);
static ssize_t k_read (struct file *, char __user *, size_t, loff_t *);
static ssize_t k_write (struct file *, const char __user *, size_t, loff_t *);
static long k_ioctl (struct file *, unsigned int, unsigned long);

static struct file_operations  fop = {
    .owner = THIS_MODULE,
    .open = k_open,
    .release = k_release,
    .write = k_write,
    .read = k_read,
    .unlocked_ioctl = k_ioctl
};
static int k_open (struct inode *a, struct file *b){
    printk("Driver opened\n");
    return 0;
}
static int k_release (struct inode *a, struct file *b){
    printk("Driver closed\n");
    return 0;
}
static ssize_t k_read (struct file *a, char __user *b, size_t c, loff_t *d){
    printk("Driver read\n");
    return 0;
}
static ssize_t k_write (struct file *a, const char __user *b, size_t c, loff_t *d){
    printk("Driver written\n");
    return c;
}
static long k_ioctl (struct file *a, unsigned int b, unsigned long c){
    char kbuf[50];
    char hi[] = "hello yaswanth\n";
    switch(b){
        case i_s_m:
            copy_from_user(kbuf,(char *)c,sizeof(kbuf));
            printk("%s\n",kbuf);
            break;
        case 2:
            copy_to_user((char *)c,hi,sizeof(hi));
            break;
        default:
            printk("Bye\n");
    }
    return c;
}

static int __init ki_init(void){
    printk("In kernel\n");
    alloc_chrdev_region(&dev,0,1,"io_ytl");
    printk("Major Number: %d\n",MAJOR(dev));
    printk("Minor Number: %d\n",MINOR(dev));

    cdev_init(&c_dev,&fop);
    cdev_add(&c_dev,dev,1);

    return 0;
}

static void __exit ki_exit(void){
    cdev_del(&c_dev);
    unregister_chrdev_region(dev,1);
    printk("out of kernel\n");
}

module_init(ki_init);
module_exit(ki_exit);

MODULE_AUTHOR("cdac");
MODULE_LICENSE("GPL");





