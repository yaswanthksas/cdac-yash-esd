#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/cdev.h>
// #include<linux/ioctl.h>
#include<linux/slab.h>
#include<linux/uaccess.h>
dev_t dev = 0;

// #define serial_magic 'k'
#define wr_value _IOW('a',0,int)
#define rd_value _IOR('a',1,int)
// #define serial_reset __IO(serial_magic,0)
// #define serial_bset __IOW(serial_magic,1,int);
// #define serial_status __IOR(serial_magic,2,char);
// #define serial_control __IOWR(serial_magic,3,char);

static struct cdev c_dev;

static ssize_t i_read (struct file *, char __user *, size_t, loff_t *);
static ssize_t i_write (struct file *, const char __user *, size_t, loff_t *);
static int i_open (struct inode *, struct file *);
static int i_release (struct inode *, struct file *);
static long int i_ioctl(struct file *file,unsigned int cmd,unsigned long arg);

static struct file_operations fops ={
    .owner = THIS_MODULE,
    .read = i_read,
    .write = i_write,
    .release = i_release,
    .open = i_open,
    .unlocked_ioctl = i_ioctl,
};
static long int i_ioctl(struct file *file,unsigned int cmd,unsigned long arg){
    printk("entered to ioctl\n");
    switch(cmd){
        case wr_value:
            
            printk("this is write\n");
            break;
        case rd_value:
            printk("this is read\n");
            break;
        default:
            printk("invalid\n");
            break;
    }

    return 0;
}

static ssize_t i_read (struct file *a, char __user *b, size_t c, loff_t *d){
    printk("Driver read\n");
    return c;
}
static ssize_t i_write (struct file *a, const char __user  *b, size_t c, loff_t *d){
    printk("Driver written\n");

    return c;
}
static int i_open (struct inode *a, struct file *b){
    printk("Driver opened\n");
    return 0;
}
static int i_release (struct inode *a, struct file *b){
    printk("Driver closed\n");
    return 0;
}


static int __init i_init(void){
    printk("In the kernel space\n");
    alloc_chrdev_region(&dev,0,1,"ioctl_prog");
    printk("MAJOR: %d\n",MAJOR(dev));
    printk("Minor: %d\n",MINOR(dev));

    /*registering charater device*/
    cdev_init(&c_dev,&fops);
    cdev_add(&c_dev,dev,1);

    return 0;
}
static void __exit i_exit(void){

    cdev_del(&c_dev);
    unregister_chrdev_region(dev,1);
    printk("Exiting from kernel\n");
}

module_init(i_init);
module_exit(i_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("cdac");










