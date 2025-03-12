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

struct node * insertf(struct node *l1,int num){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    if(l1 == NULL){
        l1 = temp;
    }
    else{
        temp->next = l1;
        l1 = temp;
    }
    return l1;
}

struct node * insert_after(struct node *start,int ele,int num){
    struct node *temp,*curr;
    curr = start;
    if(start != NULL){
        while(curr != NULL && curr->data != ele){
            curr = curr->next;
        }
        if(curr != NULL){
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = num;
            temp->next = curr->next;
            curr->next = temp;
        }
        else{
            printf("Element not found\n");
        }
    }
    else{
        printf("List is empty \n");
    }
    return start;
}
int delete_end(struct node *l1){
    struct node *temp;
    temp = l1;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    int x;
    x = temp->next->data; 
    free(temp->next);
    temp->next = NULL;

    return x;
}
struct node * del_start(struct node *l1){
    struct node *temp;
    temp = l1;
    int x;
    x = temp->data;
    printf("%d",x);
    l1 = temp->next;
    free(temp);
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
    //display(l1);

    l1 = insertf(l1,12);
    l1 = insert_after(l1,12,50);
    display(l1);
    printf("\n");
    int y;
    y = delete_end(l1);
    printf("%d",y);
    printf("\n");
    display(l1);
    printf("\n");
    int x;
    // x = del_start(l1);
    l1 = del_start(l1);
    //printf("%d",x);
    printf("\n");
    display(l1);
    return 0;
}