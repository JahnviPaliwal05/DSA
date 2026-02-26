#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*left;
    struct node*right;
}node;

// create a new node

node* createnode(int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode -> data = data;
    newnode -> left = newnode -> right = NULL;
    return newnode;
}

// to insert a new node 

node* insert(node*root, int data){
    if(root == NULL){
        return createnode(data);
    }
    if(data < root -> data){
        root -> left = insert(root -> left, data);
    } else{  
        root -> right = insert(root -> right,data);
    }
    return root;
}


