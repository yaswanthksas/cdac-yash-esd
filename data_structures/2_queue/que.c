#include<stdio.h>
#include<stdlib.h>
struct que{
    int *qe;
    int size;
    int front;
    int rear;
};
struct que q;
int overflow(){
    if(q.rear == q.size-1){
        return 1;
    }
    return 0;
}
int underflow(){
    if(q.rear == -1 && q.front == -1){
        return 1;
    }
    return 0;
}
void enque(int num){
    if(!overflow()){
        if(underflow()){
            q.front++;
        }
        q.rear++;
        q.qe[q.rear] = num;
    }
    else{
        printf("Queue is full\n");
    }
}
int deque(){
    int x = -999;
    if(!underflow()){
        x = q.qe[q.front];
        if(q.front == q.rear){
            q.front=-1;
            q.rear = -1;
        }
        else{
            q.front++;
        }
    }
    else{
        printf("Queue is empty \n");
    }
    return x;
}
void display(){
    if(!underflow()){
        int i;
        for(i=q.front;i<=q.rear;i++){
            printf("%d",q.qe[i]);
        }
    }
    else{
        printf("queue is empty cannot display\n");
    }
}
int main(){
    printf("Enter size of queue\n");
    scanf("%d",&q.size);
    q.qe = (int *) malloc(sizeof(int)*q.size);
    q.front = -1;
    q.rear = -1;
    enque(5);
    enque(6);
    enque(7);
    enque(4);
    enque(8);
    // display();
    display();

    return 0;
}