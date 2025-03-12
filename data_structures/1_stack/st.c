#include<stdio.h>
#include<stdlib.h>
struct __stack{
    int size;
    int *a;
    int tos;
};
struct __stack sta;
int isfull(){
    if(sta.tos == sta.size-1){
        return 1;
    }
    return 0;
}
int isempty(){
    if(sta.tos == -1){
        return 1;
    }
    return 0;
}
void push(int ele){
    if(!isfull()){
        sta.tos++;
        sta.a[sta.tos] = ele;
    }
    else{
        printf("Stack is full");
    }
}
int pop(){
    int x = -999;
    if(!isempty()){
        x = sta.a[sta.tos];
        sta.tos--;
    }
    else{
        printf("stack is nepop");
    }
}
void display(){

    for(int i=0;i<=sta.tos;i++){
        printf("%d",sta.a[i]);
    }
}
int main(){
    scanf("%d",&sta.size);
    sta.a = (int *) malloc(sta.size * sizeof(int));
    sta.tos = -1;
    // push(1);
    // push(2);
    // push(3);
    // push(4);
    // push(1);
    // push(2);
    // push(3);
    // push(4);
    for(int i=0;i<sta.size;i++){
        sta.tos++;
        scanf("%d",&sta.a[i]);
    }
    display();
    // push(4);
    // push(4);

    return 0;
}