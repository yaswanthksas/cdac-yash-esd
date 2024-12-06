/***************************************************************************//**
*  \file       driver.c
*
*  \details    Simple linux driver (Waitqueue Static method)
*
*  \author     Harin Chandu
*
*
*******************************************************************************/
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/slab.h>                 //kmalloc()
#include <linux/uaccess.h>              //copy_to/from_user()
#include <linux/kthread.h>
#include <linux/wait.h>                 // Required for the wait queues
 
 
static struct task_struct *wait_thread;
 
DECLARE_WAIT_QUEUE_HEAD(wait_queue_hcwq);
 
dev_t dev = 0;
static struct class *dev_class;
static struct cdev hcwq_cdev;
int wait_queue_flag = 0;
uint32_t read_count = 0;
/*
** Function Prototypes
*/
static int      __init hcwq_driver_init(void);
static void     __exit hcwq_driver_exit(void);
 
/*************** Driver functions **********************/
static int      hcwq_open(struct inode *inode, struct file *file);
static int      hcwq_release(struct inode *inode, struct file *file);
static ssize_t  hcwq_read(struct file *filp, char __user *buf, size_t len,loff_t * off);
static ssize_t  hcwq_write(struct file *filp, const char *buf, size_t len, loff_t * off);

/*
** File operation sturcture
*/
static struct file_operations fops =
{
        .owner          = THIS_MODULE,
        .read           = hcwq_read,
        .write          = hcwq_write,
        .open           = hcwq_open,
        .release        = hcwq_release,
};

/*
** Thread function
*/
static int wait_function(void *unused)
{
        while(1) {
                pr_info("Waiting For Event...\n");
                wait_event_interruptible(wait_queue_hcwq, wait_queue_flag != 0 );

                if(wait_queue_flag == 2) {
                        pr_info("Event Came From Exit Function\n");
                        return 0;
                }
		if(wait_queue_flag == 1) {
                pr_info("Event Came From Read Function - %d\n", ++read_count);
                wait_queue_flag = 0;
		}
	}
        do_exit(0);
        return 0;
}

/*
** This function will be called when we open the Device file
*/
static int hcwq_open(struct inode *inode, struct file *file)
{
        pr_info("Device File Opened...!!!\n");
        return 0;
}

/*
** This function will be called when we close the Device file
*/
static int hcwq_release(struct inode *inode, struct file *file)
{
        pr_info("Device File Closed...!!!\n");
        return 0;
}

/*
** This function will be called when we read the Device file
*/
static ssize_t hcwq_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
        pr_info("Read Function\n");
        wait_queue_flag = 1;
        wake_up_interruptible(&wait_queue_hcwq);
        return 0;
}

/*
** This function will be called when we write the Device file
*/
static ssize_t hcwq_write(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
        pr_info("Write function\n");
        return len;
}
 
/*
** Module Init function
*/
static int __init hcwq_driver_init(void)
{
        /*Allocating Major number*/
        if((alloc_chrdev_region(&dev, 0, 1, "hcwq_Dev")) <0){
                pr_info("Cannot allocate major number\n");
                return -1;
        }
        pr_info("Major = %d Minor = %d \n",MAJOR(dev), MINOR(dev));
 
        /*Creating cdev structure*/
        cdev_init(&hcwq_cdev,&fops);
        hcwq_cdev.owner = THIS_MODULE;
        hcwq_cdev.ops = &fops;
 
        /*Adding character device to the system*/
        if((cdev_add(&hcwq_cdev,dev,1)) < 0){
            pr_info("Cannot add the device to the system\n");
            goto r_class;
        }
 
        /*Creating struct class*/
        if((dev_class = class_create(THIS_MODULE,"hcwq_class")) == NULL){
            pr_info("Cannot create the struct class\n");
            goto r_class;
        }
 
        /*Creating device*/
        if((device_create(dev_class,NULL,dev,NULL,"hcwq_device")) == NULL){
            pr_info("Cannot create the Device 1\n");
            goto r_device;
        }
 
        //Create the kernel thread with name 'mythread'
        wait_thread = kthread_create(wait_function, NULL, "WaitThread");
        if (wait_thread) {
                pr_info("Thread Created successfully\n");
                wake_up_process(wait_thread);
        } else
                pr_info("Thread creation failed\n");
 
        pr_info("Device Driver Insert...Done!!!\n");
        return 0;
 
r_device:
        class_destroy(dev_class);
r_class:
        unregister_chrdev_region(dev,1);
        return -1;
}

/*
** Module exit function
*/ 
static void __exit hcwq_driver_exit(void)
{
        wait_queue_flag = 2;
        wake_up_interruptible(&wait_queue_hcwq);
        device_destroy(dev_class,dev);
        class_destroy(dev_class);
        cdev_del(&hcwq_cdev);
        unregister_chrdev_region(dev, 1);
        pr_info("Device Driver Remove...Done!!!\n");
}
 
module_init(hcwq_driver_init);
module_exit(hcwq_driver_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Harin Chandu rharin@cdac.in");
MODULE_DESCRIPTION("Simple linux driver (Waitqueue Static method)");
MODULE_VERSION("1.7");
