#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start;
void insert_after(int sea,int ele){
    struct node *temp,*curr;
    if(start != NULL){
        curr = start;
        while(curr != NULL && curr->data != sea){
            curr = curr->next;
        }
        if(curr != NULL){
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = ele;
            temp->next = curr->next;
            curr->next = temp;

        }
        else{
            printf("Element not found");
        }

    }
    else{
        printf("List is empty\n");
    }
}


int main(){
    

    return 0;
}