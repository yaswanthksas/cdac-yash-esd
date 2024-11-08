#include<stdio.h>
 #include <sys/types.h>
       #include <unistd.h>

int main(){
    pid_t id;
    printf("Before fork \n");
    printf("pid: %d\n",getpid());
    printf("ppid : %d\n",getppid());
    printf("\n ------------------------\n");
    id = fork(); //child created 
    // if(id == 0){
    //     printf("child pid: %d\n ppid: %d\n",getpid(),getppid());
    // }
    // else{
    //     printf("parent pid : %d\n ppid : %d\n",getpid(),getppid());
    // }
    
    if(id != 0){
        printf("parent pid : %d\n ppid : %d\n",getpid(),getppid());
    }
    else{
        printf("child pid: %d\n ppid: %d\n",getpid(),getppid());
    }
    


    return 0;
}