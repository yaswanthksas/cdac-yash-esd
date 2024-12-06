#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/kdev_t.h>
#include<linux/types.h>

#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/kthread.h>
#include<linux/wait.h>
MODULE_AUTHOR("cdac");
MODULE_LICENSE("GPL");


wait_queue_head_t wh;  //declaring the waitqueue
static struct task_struct *wait_thread;
static int flag=0;

dev_t dev;
static struct cdev cd;


static int y_open(struct inode *in, struct file *filp)
{
        pr_info("Device File Opened...!!!\n");
        return 0;
}


static int y_release(struct inode *in, struct file *filp)
{
        pr_info("Device File Closed...!!!\n");
        return 0;
}

static ssize_t y_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
	printk("reading from the kernel\n");
	flag=1;
	wake_up_interruptible(&wh);
	return 0;
}

static ssize_t y_write(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
       printk("wiriting from the kernel\n");
       return 0;
}

static struct file_operations fops =
{
        .owner          = THIS_MODULE,
        .read           = y_read,
        .write          = y_write,
        .open           = y_open,
        .release        = y_release,
};

static int wf(void *unused)
{
	printk("device is in the sleep state\n");
	wait_event_interruptible(wh,flag!=0);
	printk("padukundi chalu ley inka\n");
	return 0;
}


static int __init dw_init(void){
    alloc_chrdev_region(&dev,0,1,"ANU");
	printk("MAJOR:%d\n MINOR:%d\n",MAJOR(dev),MINOR(dev));
	
    cdev_init(&cd,&fops);
	cdev_add(&cd,dev,1);
	
    init_waitqueue_head(&wh);  //initialization

    wait_thread=kthread_create(wf,NULL,"wait thread");
	wake_up_process(wait_thread);
	
	printk("hi bro bye");
	
    return 0;
}

static void __exit dw_exit(void){
    
    unregister_chrdev_region(dev,1);
	cdev_del(&cd);
	printk("remove from the Kernel\n");
}

module_init(dw_init);
module_exit(dw_exit);
