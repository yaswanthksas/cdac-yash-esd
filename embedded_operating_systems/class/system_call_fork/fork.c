 #include <sys/types.h>
       #include <unistd.h>
//  The child does not inherit its parent's memory locks (mlock(2), mlockall(2)).

//        *  Process resource utilizations (getrusage(2)) and CPU time counters (times(2)) are reset to zero in the child.
//  pid_t pid;

#include<stdio.h>
int main(){
    printf("Before Fork\n");
    printf("pid: %d\n",getpid());
    printf("ppid: %d\n",getppid());
    printf("\n---------------------------\n");
    fork();
    printf("After fork\n");
   printf("pid: %d\n",getpid());
   printf("ppid: %d\n",getppid());
   printf("\n---------------------------\n");
    
    return 0;
}