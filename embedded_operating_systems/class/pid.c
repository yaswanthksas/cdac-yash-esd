#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>

// pid_t getpid(void);
// pid_t getppid(void);
pid_t pid;
pid_t ppid;

int main(){
    pid = getpid();
    ppid = getppid();
    printf("current process is %d\n",pid);
    printf("current parent process is %d\n",ppid);

    return 0;
}
