#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *l1 = NULL , *l2 = NULL , *l3 = NULL;
// void insert();
// //void mergenode(struct node *start,struct node *start2){
struct node * createl(struct node *start){
    printf("Enter 1st lisked list node data \n");
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    scanf("%d",&temp->data);
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
        temp->next = NULL;
    }
    return start;

}
// void createl1(){
//     printf("Enter 1st lisked list node data \n");
//     struct node *temp;
//     temp = (struct node *)malloc(sizeof(struct node));
//     scanf("%d",&temp->data);
//     if(l1 == NULL){
//         l1 = temp;
//     }
//     else{
//         struct node *curr;
//         curr = l1;
//         while(curr->next != NULL){
//             curr = curr->next;
//         }
//         curr->next = temp;
//         temp->next = NULL;
//     }

// }
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
// void display1(){
//     struct node *curr;
//     curr = l1;
//     while(curr != NULL){
//         printf("%d",curr->data);
//         curr = curr -> next;
//     }
//     printf("\n");
//     printf("\n");
// }
void display(struct node *curr){
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
    // scanf("%d",&m);
    printf("Enter elements you want to insert in linked list 1 : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    l1 = createl(l1);
    }

 printf("Enter elements you want to insert in linked list 2 : ");
    scanf("%d",&m);
    for(int i=0;i<m;i++){
    l2 = createl(l2);
    // createl2();
    }

    //createl2();
    // display1(l1);
    display(l2);
    display(l2);
    //display2();


    return 0;
}