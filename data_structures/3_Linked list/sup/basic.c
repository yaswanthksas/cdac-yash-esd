#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *l1 = NULL , *l2 = NULL , *l3 = NULL;
void createl1(){
    printf("Enter 1st lisked list node data \n");
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    scanf("%d",&temp->data);
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
        temp->next = NULL;
    }

}
void createl2(){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter 1st lisked list node data \n");
    scanf("%d",&temp->data);
    if(l2 == NULL){
        l2 = temp;
    }
    else{
        struct node *curr;
        curr = l2;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = NULL;
    }

}
struct node* merge(struct node *l1,struct node *l2){
    if(l1 == NULL){
        return l2;
    }
    if(l2 == NULL){
        return l1; 
    }
    while(l1 != NULL && l2 != NULL){

        if(l1->data < l2->data){
            l3->next = l1;
            l1=l1->next;
        }
        else{
            l3->next = l2;
            l2 = l2 -> next;
        }
        l3=l3->next;
    }
    while(l1 != NULL){
        l3->next = l1;
        l1=l1->next;
        l3 = l3->next;
    }
    while(l2 != NULL){
        l3->next = l1;
        l1 = l1->next;
        l3 = l3->next;
    }
    return l3;

}
void display1(){
    struct node *curr;
    curr = l1;
    while(curr != NULL){
        printf("%d",curr->data);
        curr = curr -> next;
    }
    printf("\n");
    printf("\n");
}
void display2(){
    struct node *curr;
    curr = l2;
    while(curr != NULL){
        printf("%d",curr->data);
        curr = curr -> next;
    }
     printf("\n");
    printf("\n");
}
int main(){
    int n,m;
    printf("Enter elements you want to insert in linked list 1 : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    createl1();
    }

    printf("Enter elements you want to insert in linked list 2 : ");
    scanf("%d",&m);
    for(int i=0;i<m;i++){
    createl2();
    }

    display1();
    display2();

    merge(l1,l2);

    return 0;
}