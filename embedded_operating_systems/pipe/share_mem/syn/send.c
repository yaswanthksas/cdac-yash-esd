#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h> /* For mode constants */
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <semaphore.h>

int main()
{
      sem_t t1;
      int fd;
      fd = shm_open("/r_share", O_CREAT | O_RDWR, S_IRWXU);
      ftruncate(fd, (10 * sizeof(char)));
      char *count;
      count = (char *)mmap(NULL, 10 * sizeof(char), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

      sem_open("/smem", O_CREAT | O_RDWR, S_IRWXU);
      sem_init(&t1, 1, 1);

      sem_wait(&t1);
      char cnt[10] = "yashwanth";
      count = cnt;
      write(fd, count, sizeof(count));
      sem_post(&t1);
      //     printf("%s",count);

      sem_destroy(&t1);
      return 0;
}