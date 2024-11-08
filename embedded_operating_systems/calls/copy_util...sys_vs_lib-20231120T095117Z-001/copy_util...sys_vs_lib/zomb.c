#include<stdio.h>
#include <sys/types.h>
       #include <unistd.h>

int main()

{

pid_t  nemo;

printf("parent pid:%d\n",getpid());
printf("parent ppid:%d\n",getppid());

nemo=fork();

if(nemo==0)
{


printf("child pid:%d\n",getpid());
printf("child ppid:%d\n",getppid());

}
else

{

sleep(10);

printf("parent pid:%d\n",getpid());
printf("parent ppid:%d\n",getppid());
}
 return 0;
}
