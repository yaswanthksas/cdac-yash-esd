#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("CDAC");


static int a = 10;
static int b = 20;

module_param(a,int,S_IRUGO);
module_param(b,int,S_IRUGO);


