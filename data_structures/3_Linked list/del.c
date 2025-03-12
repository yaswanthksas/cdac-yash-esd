#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start;
void begin(int num){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = start;
    start = temp;
}
void display(){
    struct node *curr;
    curr = start;
    while(curr != NULL){
        printf("%d",curr->data);
        curr = curr->next;
    }
}
int delf(){
    int x=-999;
    struct node *temp;
    if(start != NULL){
        temp = start;
        x = temp->data;
        start = temp->next;
        free(temp);
        return x;
    }
    else{
        printf("List is empty\n");
    }
}
int main(){
    begin(10);
    begin(20);
    delf();
    display();


    return 0;
}