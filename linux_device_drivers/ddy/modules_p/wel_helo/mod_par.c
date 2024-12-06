// headers to include for the kernel 
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

//macros 
MODULE_LICENSE("GPL"); //gnu general public licence 
MODULE_AUTHOR("CDAC"); //who created this module 

//write __init,__exit functions 
static int __init mod_init(void){    
//static implies this static function 
//resticts to this file only outside to this it is not working 
    printk("Welcome to kernel space\n");
    return 0;
}

static void __exit mod_exit(void){
    printk("Bye to kernel\n");

}

//initialization and exiting functions 
module_init(mod_init);
module_exit(mod_exit);


