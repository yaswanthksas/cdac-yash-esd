#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;

struct node * insert_start(struct node *start,int num){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = start;
    // if(start == NULL){
    start = temp;
    // }
    return start;
}
int del_start(){
    struct node *temp;
    int x;
    if(start != NULL){

    temp = start;
    x = temp->data;
    start = start->next;
    temp->next = NULL;
    free(temp);
    temp = NULL;
    printf("Start %d\n",start->data);
    }
    else{
        printf("List is empty\n");
    }
    return x;
}
// int delf(){
//     int x=-999;
//     struct node *temp;
//     if(start != NULL){
//         temp = start;
//         x = temp->data;
//         start = temp->next;
//         free(temp);
//         return x;
//     }
//     else{
//         printf("List is empty\n");
//     }
// }
void display(struct node *start){
    struct node *curr;
    curr = start;
    while(curr != NULL)
    {
        printf("%d ",curr->data);
        curr=curr->next;
    }
        printf("\n");
}
int main(){
    start = insert_start(start,20);
    start = insert_start(start,40);
    display(start);

    int x;
    x = del_start();
    printf("\nDeleted: %d\n",x);
    //printf("\nDeleted: %d",start->data);
   display(start);
    return 0;
}