#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front = NULL,*rear = NULL;
void display(){
    struct node *curr;
    curr = front;
    if(front != NULL){
        while(curr != NULL){
            printf("%d ",curr->data);
            curr = curr->next;
        }
    }
    else{
        printf("list is empty\n");
    }
}
int isempty(){
    if(front == NULL && rear == NULL){
        return 1;
    }
    return 0; 
}
void insert(int num){
    if(front != NULL){


    }
    else{
        printf("List is empty\n");
    }

}
