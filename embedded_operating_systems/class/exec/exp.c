#include<stdio.h>
#include <unistd.h>
 #include <sys/types.h>
      //  #include <unistd.h>

int main(){
   pid_t id;
    // int x;
    printf("Before exec \n");
    printf("Addition is : \n");
    id=fork();
    if(id == 0){
       execl("/home/l1-pc22/Desktop/eos/class/exec/ya","",NULL);
    }
else{
    printf("\n\nafter exec why not executing ");
    printf("finish\n");

}

    //   execl("/home/l1-pc22/Desktop/eos/class/exec/ya","",NULL);
    //   printf("\n\nafter exec why not executing ");
    // printf("finish\n");
    

    return 0;
}