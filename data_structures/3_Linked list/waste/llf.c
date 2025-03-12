#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *l1;
struct node * insert(struct node *l1,int num){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = NULL;
    if(l1 == NULL){
        l1 = temp;
    }
    else{
        struct node *curr;
        curr = l1;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
    }
    return l1;
}
void display(struct node *l1){
    struct node *curr;
    curr = l1;
    while(curr != NULL){
        printf("%d ",curr->data);
        curr = curr->next;
    }
}
int main(){

    l1 = insert(l1,5);
    l1 = insert(l1,6);
    l1 = insert(l1,7);
    display(l1);

    return 0;
}