#include<stdio.h>
#include"yah.h"
struct stack{
    char *c;
    int size;
    int tos;
};
struct stack s;
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
void push(char num)
{   if(!isfull()){

    s.tos++;
    s.c[s.tos] = num;

}
else{
    printf("Stack is full");
}
}
int pop(){
    int x;
    if(!isempty()){
        x = s.c[s.tos];
        s.tos--;
    }
    else{
        printf("Empty");
    }
    return x;
}
int peep(){
    int x;
    if(!isempty()){
        x = s.c[s.tos];
        
    }
    else{
        printf("Empty");
    }
    return x;
}
