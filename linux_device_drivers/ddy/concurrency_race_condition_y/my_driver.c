#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/semaphore.h>
#include<linux/uaccess.h>

int op_result;  //shared resource.
static struct semaphore my_sema;
dev_t dev = 0;
static struct cdev c_dev;

static ssize_t d_read (struct file *, char __user *, size_t, loff_t *);
static ssize_t d_write (struct file *, const char __user *, size_t, loff_t *);
static int d_open (struct inode *, struct file *);
static int d_release (struct inode *, struct file *);

static struct file_operations fops={
    .owner = THIS_MODULE,
    .open = d_open,
    .release = d_release,
    .write = d_write,
    .read = d_read
};

static ssize_t d_read (struct file *a, char __user *b, size_t c, loff_t *d){
    int result;
    // ssize_t retval;
    printk("Driver read\n");
    printk("before sending the result to kernel : %d\n",op_result);
    result = copy_to_user((char *)b,(char *)&op_result,c);
    up(&my_sema);
    return c; 
}


static ssize_t d_write (struct file *a, const char __user *b, size_t c, loff_t *d){
    // down(&my_sema);
    down_interruptible(&my_sema);
    int kbuff[2],num1,num2,result;
    printk("Driver Write \n");
    // ssize_t retval;

    result = copy_from_user((char *)kbuff,( char *)b,c);
    num1 = kbuff[0];
    num2 = kbuff[1];
    op_result = num1 + num2;
    printk("data is %d and %d\n",num1,num2);
    printk("Result is %d\n",op_result);
    return c;
}

static int d_open (struct inode *a, struct file *b){
    printk("Driver is opened\n");
    return 0;
}
static int d_release (struct inode *a, struct file *b){
    printk("Driver is closed\n");
    return 0;
}

static int __init d_init(void){
    printk("In kernel\n");
    alloc_chrdev_region(&dev,0,3,"con_rc_dname");
    printk("Major : %d\n",MAJOR(dev));
    printk("Minor : %d\n",MINOR(dev));
    cdev_init(&c_dev,&fops);
    cdev_add(&c_dev,dev,3);

    sema_init(&my_sema,1);   //only one shared resource critical section which is result. 

    return 0;
}
static void __exit d_exit(void){
    cdev_del(&c_dev);
    unregister_chrdev_region(dev,3);
    printk("Out of Kernel\n");
}

MODULE_AUTHOR("cdac");
MODULE_LICENSE("GPL");

module_init(d_init);
module_exit(d_exit);
