#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/uaccess.h>

int final_result;

dev_t dev = 0;
static struct cdev c_dev;
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .write = d_write,
    .read = d_read,
    .open = d_open,
    .release = d_release
};

static ssize_t d_read (struct file *, char __user *, size_t, loff_t *);
static ssize_t d_write (struct file *, const char __user *, size_t, loff_t *);
static int d_open (struct inode *, struct file *);
static int d_release (struct inode *, struct file *);


static ssize_t d_read (struct file *a, char __user *b, size_t c, loff_t *d){
    
    printk("Before sending result to kernel %d\n",final_result);
    int result;
    result = copy_to_user((char *)b,(char *)&final_result,c);
    return c;
}
static ssize_t d_write (struct file *a, const char __user *b, size_t c, loff_t *d){
    int kbuff[2],n1,n2,result;
    result = copy_from_user((char *)kbuff,(const char *)b,c);
    n1 = kbuff[0];
    n2 = kbuff[1];
    final_result = n1+n2;
    printf("Result is %d\n",final_result);
    return c;
}
static int d_open (struct inode *a, struct file *b){
    printk("Driver is open\n");
    return 0;
}
static int d_release (struct inode *a, struct file *b){
    printk("Driver is closed\n");
    return 0;
}

static int __init m_init(void){
    printk("Entered the kernel\n");
    alloc_chrdev_region(&dev,0,3,"spin_df");
    printk("Major: %d\n",MAJOR(dev));
    printk("Minor: %d\n",MINOR(dev));

    cdev_init(&c_dev,&fops);
    cdev_add(&c_dev,dev,3);
    return 0;
}

static void __exit m_exit(void){
    cdev_del(&c_dev);
    unregister_chrdev_region(dev,1);
    printk("Out of kernel\n");
}

module_init(m_init);
module_exit(m_exit);

MODULE_AUTHOR("cdac");
MODULE_LICENSE("GPL");

