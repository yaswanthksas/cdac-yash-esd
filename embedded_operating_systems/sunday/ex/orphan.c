#include<stdio.h>
 #include <sys/types.h>
       #include <unistd.h>


int main(){
    pid_t ven;
    printf("process id: %d\n",getpid());
    printf("parent pid : %d\n\n",getppid());

    ven = fork();
    if(ven == 0){
        sleep(10);
        printf("child pid: %d\n",getpid());
        printf("child ppid: %d\n\n",getppid());
    }
    else{
          printf("process id: %d\n",getpid());
         printf("parent pid : %d\n\n",getppid());
    }

    return 0;
}