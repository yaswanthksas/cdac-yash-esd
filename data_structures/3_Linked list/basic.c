#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start;
void display(){
    struct node *temp;
    //temp = (struct node *)malloc(sizeof(struct node));
    temp = start;
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
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
    first->data = 12;
    first->next = second;

    second->data = 34;
    second->next = third;

    third->data = 45;
    third->next = NULL;
    
    display();
    return 0;
}