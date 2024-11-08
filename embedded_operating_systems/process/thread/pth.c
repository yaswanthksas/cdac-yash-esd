#include<stdio.h>
   #include <pthread.h>
typedef struct{
    int a;
    int b;
}sname;
void *add(void *v){
    int sum = 0;
    sname *x = (sname*)v;
    sum = x->a + x->b;
    printf("SUM is: %d\n",sum);
}
int main(){
    int a=5,b=6;
    pthread_t p1;
    sname s1;
    s1.a = 5;
    s1.b = 6;
    pthread_create(&p1,NULL,add,&s1);
    pthread_join(p1,NULL);
    // printf("hello\n");
    return 0;
}