#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *start;
void insertb(int num){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->prev = NULL;
    temp->next = NULL;
    if(start == NULL){
        start = temp;
    }
    else if(start != NULL){
        temp->next = start;
        start->prev = temp; 
        start = temp;
    }
}
void display(){
    struct node *curr;
    while(curr != NULL){
        printf("%d",curr->data);
        curr = curr->next;
    }

}
int main(){
    insertb(20);
    insertb(10);
    display();

    return 0;
}
