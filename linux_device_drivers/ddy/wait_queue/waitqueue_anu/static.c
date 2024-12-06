#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/uaccess.h>
#include<linux/err.h>
#include<linux/kdev_t.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include <linux/device.h>
#include<linux/wait.h>
#include<linux/kthread.h>



dev_t dev;
static struct cdev cd;
static int a;

DECLARE_WAIT_QUEUE_HEAD(wq);
static struct task_struct *wait_thread;
static int flag=0;

	

static int open(struct inode *in,struct file *fp)
{
	printk("File open\n");
	return 0;
}

static int release(struct inode *in,struct file *fp)
{
	printk("File released\n");
	return 0;
}
static ssize_t read(struct file *fp,char __user *buf,size_t len,loff_t *off)
{
	printk("File reading\n");
	flag=1;
	wake_up_interruptible(&wq);
	return 0;
}
static ssize_t write(struct file *fp,const char __user *buf,size_t len,loff_t *off)
{
	printk("File writing\n");
	return len;
}


static struct file_operations fops={

	.owner=THIS_MODULE,
	.release=release,
	.open=open,
	.read=read,
	.write=write,
};



static int wf(void *unused)
{	
	printk("in the sleep state\n");
	wait_event_interruptible(wq, flag != 0 );
	printk("woke up dude\n");
	return 0;
}

static int __init wait_init(void){
	if(alloc_chrdev_region(&dev,0,1,"w_driver")<0)
		pr_info("Cannot create major and minor number\n");
	else
		pr_info("Successfully created major:%d\n and minor number:%d\n\n",MAJOR(dev),MINOR(dev));
		
	cdev_init(&cd,&fops);
	
	a=cdev_add(&cd,dev,1);
	printk("%d\n",a);
	wait_thread = kthread_create(wf, NULL, "WaitThread");
	wake_up_process(wait_thread);
	return 0;
			
}

static void __exit wait_exit(void){
	cdev_del(&cd);
	unregister_chrdev_region(dev, 1);
}



module_init(wait_init);
module_exit(wait_exit);



MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anu");

