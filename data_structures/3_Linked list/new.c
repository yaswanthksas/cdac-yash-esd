#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start,*curr;
void display(){
    curr=start;
    while(curr != NULL){
        printf("%d",curr->data);
        curr = curr->next;
    }
}
int main(){
    struct node *first;
    struct node *second;
    struct node *third;
    
    first = (struct node *) malloc(sizeof(struct node));
    second = (struct node *) malloc(sizeof(struct node));
    third = (struct node *) malloc(sizeof(struct node));
    start = first;
    first->data = 10;
    first->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;
    display();


    return 0;
}