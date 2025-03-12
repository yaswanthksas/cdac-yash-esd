#include<stdio.h>
#include<stdlib.h>
struct cque{
    int *c;
    int size;
    int front;
    int rear;
};
struct cque cq;
int overflow(){
    if((cq.rear+1)%cq.size == cq.front){
        return 1;
    }
    return 0;
}
int underflow(){
    if(cq.front==-1 && cq.rear == -1){
        return 1;
    }
    return 0;
}
void enque(int num){
    if(!overflow()){
        if(underflow()){
            cq.front++;
        }
        cq.rear = (cq.rear+1)%(cq.size);
        cq.c[cq.rear]=num;
         
    }
    else 
        printf("overflow");
}
int deque(){
    int x=-999;
    if(!underflow()){
        x = cq.c[cq.front];
        if(cq.front == cq.rear){
            cq.front = -1;
            cq.rear = -1;
        }
        cq.front = (cq.front+1)%cq.size;
    }
    return x;
}
void display(){
    int i;
    if(!underflow()){
       
       for(i = cq.front; i!=cq.rear;i=(i+1)%cq.size){
            printf("%d",cq.c[i]);
       } 
       printf("%d",cq.c[cq.rear]);
    }
}
int main(){
    printf("Enter length of circular queue to insert");
    scanf("%d",&cq.size);
    cq.c = (int *)malloc(sizeof(int)*cq.size);
    cq.front = -1;
    cq.rear = -1;
    enque(34);
    enque(25);
    display();
    
    // display();
    // enque(23);
    // deque();
    // deque();
    // display();
    // display();
    return 0;
}