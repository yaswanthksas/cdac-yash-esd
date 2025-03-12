#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *start;
void insert(int num){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = NULL;
    temp->prev = NULL;
    if(start == NULL){
        start = temp;
    } 
    else{
        struct node *curr;
        curr = start;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }
}
void display(){
    struct node *curr;
    curr = start;
    while(curr != NULL){
        printf("%d ",curr->data);
        curr = curr->next;
    }
}
int main(){
    insert(20);
    insert(40);    
    display();

    return 0;
}