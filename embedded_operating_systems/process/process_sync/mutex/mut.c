#include <stdio.h>
#include <pthread.h>
int count = 0;
pthread_mutex_t m1;
void *dec(void *b)
{
    while (1)
    {
        pthread_mutex_lock(&m1);
        count--;
        printf("Decrement: %d\n", count);
        // pthread_mutex_lock(&m1);
        // pthread_mutex_unlock(&m1);
        pthread_mutex_unlock(&m1);
    }
}
void *inc(void *a)
{
    while (1)
    {
        pthread_mutex_lock(&m1);
        count++;
        printf("Increment: %d\n", count);
        pthread_mutex_unlock(&m1);
    }
}
int main()
{
    pthread_t id1, id2;
    pthread_mutex_init(&m1, NULL);
    pthread_create(&id1, NULL, inc, NULL);
    pthread_create(&id2, NULL, dec, NULL);
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    pthread_mutex_destroy(&m1);
    return 0;
}