#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start;
void display(){
    struct node *temp;
    temp = start;
    while(temp != NULL){
    printf("%d",temp->data);
    temp=temp->next;
    }
        
}
int main(){
    struct node *first;
    struct node *second;
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));

    start = first;
    first->data = 13;
    first->next = second;
    
    second->data =67;
    second->next = NULL;
    display();

    return 0;
}