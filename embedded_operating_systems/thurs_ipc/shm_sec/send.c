#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h> /* For mode constants */
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <semaphore.h>

int main()
{
    sem_t s1;
    int fd;

    fd = shm_open("kil", O_CREAT | O_RDWR, S_IRWXU);
    ftruncate(fd, sizeof(int));

    int *count;
    count = (int *)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    sem_open("/smr", O_CREAT | O_RDWR, S_IRWXU);
    sem_init(&s1, 1, 1);

    sem_wait(&s1);

    *count = "yas";

    // printf("%s", count);
    // write(fd,"yash",4);

    sem_post(&s1);

    return 0;
}