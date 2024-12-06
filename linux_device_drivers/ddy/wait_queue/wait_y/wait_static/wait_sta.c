#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

#include <linux/kdev_t.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

#include <linux/wait.h>
#include <linux/kthread.h>

dev_t dev = 0;
static struct cdev c_dev;
// static int a;

DECLARE_WAIT_QUEUE_HEAD(wq);  // 1
static struct task_struct *wait_thread; //2
static int flag = 0;  //3

static int a_open(struct inode *inode, struct file *file);
static int a_release(struct inode *inode, struct file *file);
static ssize_t a_read(struct file *filp, char __user *buf, size_t len, loff_t *off);
static ssize_t a_write(struct file *filp, const char *buf, size_t len, loff_t *off);

static struct cdev c_dev;
static int a_open(struct inode *inode, struct file *file)
{
    printk("Driver is opened\n");
    return 0;
}
static int a_release(struct inode *inode, struct file *file)
{
    printk("Driver is closed\n");
    return 0;
}
static ssize_t a_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
    printk("Read function\n");
    flag = 1;
    wake_up_interruptible(&wq);
    return 0;
}
static ssize_t a_write(struct file *filp, const char *buf, size_t len, loff_t *off)
{
    printk("write function\n");
    return len;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .read = a_read,
    .write = a_write,
    .open = a_open,
    .release = a_release
};

static int wait_function(void *unused)
{
    // while(1){
    //     printk("waiting\n");

    // }
    printk("In the sleep state\n");
    wait_event_interruptible(wq, flag != 0);
    printk("wake up dude\n");
    return 0;
}

static int __init w_init(void)
{
    alloc_chrdev_region(&dev, 0, 1, "d_name");
    printk("Major: %d\n", MAJOR(dev));
    printk("Minor: %d\n", MINOR(dev));

    /*cdev registration*/
    cdev_init(&c_dev, &fops);

    cdev_add(&c_dev, dev, 1);

    wait_thread = kthread_create(wait_function, NULL, "wait_thread");
    wake_up_process(wait_thread);
    // if(wait_thread){
    //     printk("Thread created successfully\n");
    // }
    // printk("Device driver inserted \n");
    printk("")
    return 0;
}

static void __exit w_exit(void)
{
    // wake_up_interruptible(&wq_hc);
    cdev_del(&c_dev);
    unregister_chrdev_region(dev, 1);
    printk("Device driver removed\n");
}

module_init(w_init);
module_exit(w_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("yaswanthkuna03072002@gmail.com");
