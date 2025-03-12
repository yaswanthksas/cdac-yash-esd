#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start;
void inserts(int num){
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    // curr = start;
    temp->data = num;
    temp->next = start;
    start = temp;
}
void display(){
    struct node *curr;
    curr = start;
    while(curr != NULL){
        printf("%d",curr->data);
        curr=curr->next;
    }
    printf("\n");
}
void delete_first(){
    int x=-999;
    struct node *temp;
    if(start != NULL){
        temp = start;
        x = temp->data;
        start = temp->next;
        free(temp);
    }
    else{
        printf("list is empty");
    }
}
void delete_spec(int sel){
    struct node *curr,*temp;
    if(start != NULL){
        curr = start;
        if(curr->data == sel){
            start = temp->next;
            free(curr);
        }
        else{
            while(curr->next != NULL && curr->next->data != sel){
                curr=curr->next;
            }
            if(curr->next != NULL){
                temp = curr->next;
                curr->next = temp->next;
                free(temp);
            }
            else{
                printf("Element not found");
            }
        }
    }
    else{
        printf("LIst is empty");
    }
}
void print_fun(struct node *curr){
    if(curr == NULL){
        return ;
    }
    print_fun(curr->next);
    printf("%d",curr->data);
    
}
void travel_backward(){
    if(start != NULL){
        print_fun(start);

    }
    else{
        print_fun("list is empty");
    }

}
int main(){
    inserts(20);
    inserts(13);
  //  display();
  // delete_first();
  //  display();
    inserts(66);
    travel_backward();
    display();

    return 0;
}