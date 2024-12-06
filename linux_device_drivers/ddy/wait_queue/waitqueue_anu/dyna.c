#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/uaccess.h>
#include<linux/kdev_t.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include <linux/device.h>
#include<linux/wait.h>
#include<linux/kthread.h>
#include<linux/slab.h>


static struct task_struct *wait_thread;

dev_t dev;
static struct cdev cd;
wait_queue_head_t wh;


int flag = 0;


static int open(struct inode *in, struct file *filp)
{
        pr_info("Device File Opened...!!!\n");
        return 0;
}


static int release(struct inode *in, struct file *filp)
{
        pr_info("Device File Closed...!!!\n");
        return 0;
}


static ssize_t read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
	printk("reading from the kernel\n");
	flag=1;
	wake_up_interruptible(&wh);
	return 0;
      
}


static ssize_t write(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
       printk("wiriting from the kernel\n");
       return 0;
}


static struct file_operations fops =
{
        .owner          = THIS_MODULE,
        .read           = read,
        .write          = write,
        .open           = open,
        .release        = release,
};

static int wf(void *unused)
{
	printk("device is in the sleep state\n");
	wait_event_interruptible(wh,flag!=0);
	printk("padukundi chalu ley inka\n");
	return 0;
}

static int __init start(void)
{
	alloc_chrdev_region(&dev,0,1,"ANU");
	printk("MAJOR:%d\n MINOR:%d\n",MAJOR(dev),MINOR(dev));
	
	cdev_init(&cd,&fops);
	cdev_add(&cd,dev,1);
	
	init_waitqueue_head(&wh);
	
	wait_thread=kthread_create(wf,NULL,"wait thread");
	wake_up_process(wait_thread);
	return 0;
}

static void __exit end(void)
{
	flag=2;
	wake_up_interruptible(&wh);
	unregister_chrdev_region(dev,1);
	cdev_del(&cd);
	printk("remove from the Kernel\n");
	
}

module_init(start);
module_exit(end);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("JAY");
MODULE_DESCRIPTION("Simple linux driver (Waitqueue Dynamic method)");
MODULE_VERSION("1.8");

