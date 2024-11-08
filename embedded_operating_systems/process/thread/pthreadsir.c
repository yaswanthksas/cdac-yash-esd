#include<stdio.h>
  #include <pthread.h>
typedef struct{
    int a;
    int b;
}var;
void *sum(void *v){
   int sum;
    var *x=(var*)v;
    sum = x->a + x->b;
    printf("sum: %d\n",sum);
    // return NULL;
}
void *sub(void *v){
    int sub;
    var *x=(var*)v;
    sub = x->a - x->b;
    printf("sub: %d\n",sub);
    // return NULL;
}
int main(){
    int a=5,b=6;
    pthread_t id1,id2;
    var v,w;
    v.a = 5;
    v.b = 6;
    w.a = 1;
    w.b = 4;
    pthread_create(&id1,NULL,sum,&v);
    pthread_create(&id2,NULL,sub,&w);
    pthread_join(id1,NULL);
    pthread_join(id2,NULL);
    return 0;
}