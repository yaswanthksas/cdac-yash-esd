#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start;
//start = NULL;
void insert_beg(int num){
    struct node *temp;
    temp = (struct node *) malloc(sizeof(struct node));
    temp->data = num;
    temp->next = start;
    start = temp;
}
// void insert_end(int num){
//     struct node *temp,*curr;
//     temp = (struct node *) malloc(sizeof(struct node));
//     temp->data = num;
//     temp->next = NULL;
//     if(start == NULL){
//         start = temp;
//     }
//     else{
//         curr = start;
//         while(curr->next != NULL){
//             curr = curr->next;
//         }
//         curr->next = temp;
//     }
// }
void display(){
    struct node *curr;
    curr = start;
    while(curr != NULL){
            printf("%d ",curr->data);
            curr = curr->next;
    }
}
int main(){
    insert_beg(10);
    insert_beg(10);
    insert_beg(10);
    insert_beg(10);
    insert_beg(10);
    display();

}