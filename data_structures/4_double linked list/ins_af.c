#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *start;
void insert_end(int num){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->prev = NULL;
    temp->next = NULL;
    if(start == NULL){
        start = temp;
    }
    else{
        struct node *curr;
        curr = start;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
        temp->prev = curr;
    }
    
}
void insert_after(int sele,int ele){
    struct node *temp,*curr;
    curr = start;
    if(start != NULL){
        while(curr!= NULL && curr->data != sele){
        curr = curr->next;
        }
        // if(curr != NULL){

        // }
        if(curr != NULL){
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = ele;
            temp->next = curr->next;
            temp->prev = curr;
            if(curr->next != NULL){
                curr->next->prev = temp;
            }
            curr->next = temp;
        }
        else{
            printf("element not found\n");
        }
    }
    else{
        printf("list is empty\n");
    }
}
void insert_before(int sele,int num){
    struct node *temp,*curr;
    curr = start;
    if(start != NULL){
            while(curr != NULL && curr->data != sele){
            curr = curr->next;
        }
        if(curr != NULL){
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = num;
            temp->prev = curr->prev;
            temp->next = curr;
           // if(curr->prev != NULL){
                curr->prev->next = temp;
           // }
            // else{
            //     start = temp;
            // }
            curr->prev = temp;
        }
        else{
            printf("Element not found\n");
        }


        }
    else{
        printf("List is empty\n");
    }    

}

int del_beg(){
    struct node *temp;
    //temp = start;
    int x=-999;
    if(start != NULL){
        temp = start;  
        x = temp->data;
        start = temp->next;
        //if(start != NULL){
            start->prev = NULL;
        //}
        free(temp);
    }
    else{
        printf("list is empty\n");
    }
    return x;
}

int del_end(){
    struct node *temp,*curr;
    curr = start;
    while(curr->next != NULL){
        curr = curr->next;
    }
    int x;
    x = curr->data;
    curr->prev->next = NULL;
    
    return x;
}

void del_sel(int sele){
    if(start != NULL){
        struct node *temp,*curr;
        curr = start;
        while(curr!= NULL && curr->data != sele){
            curr = curr->next;
        }
        if(curr != NULL){
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev; 
        } 
    }
    else{
        printf("list is empty\n");
    }
}
void travel_backward(){
    struct node *curr;
    if(start != NULL){
        curr = start;
        while(curr->next != NULL){
            curr = curr->next;
        }
        while(curr != NULL){
            printf("%d ",curr->data);
            curr = curr->prev;
        }
        printf("\n");
    }
    else{
        printf("list is empty\n");
    }
}

void display(){
    struct node *curr;
    curr = start;
    while(curr != NULL){
        printf("%d ",curr->data);
        curr = curr->next;
    }
    printf("\n");
}
int main(){
    insert_end(20);
    insert_end(40);
    insert_end(80);
    insert_end(15);
    display();
    insert_after(40,34);
    display();

    insert_before(80,22);
    display();
    int x = del_beg();
    display();

    int y = del_end();
    display();

    del_sel(22);
    display();

printf("\n");
// printf("\n");
// printf("\n");
// printf("\n");
    travel_backward();
    display();


    return 0;
}