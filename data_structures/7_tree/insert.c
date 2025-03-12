#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
void insert(int d){
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    t->data = d;
    t->left = NULL;
    t->right = NULL;
    if(root == NULL){
        root = t;
    }
    else{
        struct node *curr,*parent;
        curr = root;
        while(curr != NULL){
            parent = root;
            if(t->data > curr->data){
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        if(t->data > parent->data){
            parent->right = t;
        }
        else{
            parent->left = t;
        }
    }
}
int main(){
    insert(20);


    return 0;
}