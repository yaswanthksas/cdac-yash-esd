#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start,*last;       //start = tos in stack
struct node * push(struct node *start,int num){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = NULL;
    if(start == NULL){
        start = temp;
        last = temp;
    }
    else{
        struct node *curr;
        curr = start;
        while(curr->next != NULL){
            curr = curr->next;
         }
    curr->next = temp;
    last = temp;
    
    }
        
    return start;
}
struct node * pop(struct node *start){
    struct node *curr;
    int x;
    if(start != NULL){
        if(start -> next == NULL){
            x = start ->data;
            free(start);
            start = NULL;
        }
        else{
            curr = start;
            while(curr->next->next != NULL){
                    curr = curr->next;
            }
            x = curr->next->data;
            free(curr->next);
            curr->next = NULL;
            last = curr;
        }
    }
    else{
        printf("list is empty\n");
    }
    return start;
}
void display(struct node *start){
    struct node *curr;
    curr = start;
    if(curr != NULL){
        while(curr != NULL){
        printf("%d ",curr->data);
        curr = curr->next;
    }

    }
    else{
        printf("Stack is empty\n");
    }
    
}
int main(){
    start = push(start,20);
    start = push(start,48);
    start = push(start,45);
    start = push(start,45);
    start = push(start,42);
    start = push(start,41);
    display(start);
    start = pop(start);

    printf("\n");
    display(start);
    printf("\n");
    printf("%d",last->data);


    return 0;
}