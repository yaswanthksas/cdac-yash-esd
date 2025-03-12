#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *start;
void append(){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter node data \n");
    scanf("%d",&temp->data);
    temp->prev = NULL;
    temp->next = NULL;
    if(start == NULL){
        start = temp;
    }
    else{
        struct node *curr;
        curr = start;
        while(curr->next != NULL){
            curr=curr->next;
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
    append();
    append();
    append();
    display();
    return 0;
}