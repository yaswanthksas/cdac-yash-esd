#include<stdio.h>
#include"dec.h"
int isempty()
{
    if(s.tos == -1){
        return 1;
    }
    return 0;
}
int isfull(){
    if(s.tos == s.size-1){
        return 1;
    }
    return 0;
}
void push(int num){
    if(isfull()){
        printf("Stack is full\n");
    }
    else{
        s.tos++;
        s.c[s.tos] = num;
    }
}
int pop(){
    int x;
    if(isempty()){
        printf("Stack is empty\n");
    }
    else{
        x = s.c[s.tos];
        s.tos--;
    }
    return x;
}
int peep()
{
    int x;
    if(isempty()){
        printf("stack is empty\n");
    }
    else{
        x = s.c[s.tos];
    }
}