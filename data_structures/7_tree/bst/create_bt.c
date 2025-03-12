#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
struct node* getnewnode(int data){
    struct node* newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}
struct node * insert(struct node *root,int data){
    if(root == NULL){
        root = getnewnode(data);
    }
    else if(data <= root->data){
        root->left = insert(root->left,data);
    }
    else{
        root->right = insert(root->right , data);
    }
    return root;

}
int main(){
    root = insert(root,15);
    root = insert(root,20);
    root = insert(root,30);

    return 0;
}