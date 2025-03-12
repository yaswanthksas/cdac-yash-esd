#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start;
void insert_before(int sele,int ele){
    if(start != NULL){
        struct node *curr,*temp;
        curr = start;
        if(curr->data == sele){
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = ele;
            temp->next = start;
            start = temp;
        }
        else{
            while(curr->next != NULL && curr->next->data != sele){
                curr = curr -> next;
            }
            if(curr->next != NULL){
                temp = (struct node *)malloc(sizeof(struct node));
                temp->data = ele;
                temp->next = curr->next;
                curr->next = temp;

            }
            else{
                printf("Element not found");
            }
        }
    }
    else{
        printf("List is empty");
    }
}
int main(){
    
    return 0;
}