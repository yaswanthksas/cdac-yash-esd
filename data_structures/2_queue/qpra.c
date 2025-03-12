#include<stdio.h>
#include<stdlib.h>

struct queue{
    int *que;
    int size;
    int front;
    int rear;
};
struct queue q;
int overflow(){
    //rear anedi end of list lo vunnapudu
    if(q.rear == q.size-1){
        return 1;
    }
    return 0;
}
int underflow(){
    if(q.front == -1 && q.rear == -1){  // ante queue lo first ga vunnapudu inka start kanapudu
        return 1;
    }
    return 0;
}
void enque(int num){        // add element ante rear++ cheyadam
                        //not full 
    if(!overflow()){
        if(underflow()){
            q.front++;
        }
        q.rear++;
        q.que[q.rear]=num;
    }
    else{
        printf("que is full\n");
    }
}
int deque(){            //front pointer ni increse  cheyadam  apudu aa element scope lo nundi pothadi
    int x = -999;       //x ni return cheyadam ante delete chesedani 
    if(!underflow()){  //empty lenapude manam lopaliki iterate avuthamu
        x = q.que[q.front];
        if(q.front == q.rear ){    //rendu oke element deggara vunte
            q.front=q.rear=-1;
        }
        q.front++;
    }
    else{
        printf("que is empty\n");
    }
    return x;
}
void display(){ //not empty ayithe ne display chey 
    int i;
    for(i=q.front;i<=q.rear;i++){
        printf("%d",q.que[i]);
    }
}
int main(){
    printf("Enter size of queue you want\n");
    scanf("%d",&q.size);
    q.que = (int *) malloc(sizeof(int)*q.size);
    q.front = -1;
    q.rear = -1;
    enque(24);          //add elements to que idi podhi 
    enque(22);          //add elements to que idi kuda podhi 
    enque(21);          //add elements to que
    enque(6);          //add elements to que
    deque();
    deque();
    display();
    return 0;
}