#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int value){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode-> data = value;
    newnode-> left = NULL;
    newnode-> right = NULL;
}
struct node* insert(struct node* root , int value){
    if(root == NULL){
        return createnode(value);
    }
    if(value < root -> data){
        root-> left = insert(root-> left,value);
    }
    else if(value > root -> data){
        root -> right = insert(root-> right , value);
    }
    return root;
}
void inorder(struct node* root){
    if(root != NULL){
        inorder(root -> left);
        printf("%d ",root-> data);
        inorder(root -> right);
    }
}

void preorder(struct node* root){
    if(root != NULL){
        printf("%d ",root-> data);
        inorder(root -> left);
        inorder(root -> right);
    }
}
void postorder(struct node* root){
    if(root != NULL){
        
        inorder(root -> left);
        inorder(root -> right);
        printf("%d ",root-> data);
    }
}


int main(){
    
    struct node* root = NULL;
    root = insert(root , 20);
    root = insert(root , 30);
    root = insert(root , 15);
    root = insert(root , 45);
    root = insert(root , 2);
    root = insert(root , 50);
    root = insert(root , 18);
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    printf("Postorder: ");
    postorder(root);
    printf("\n");


}


//Tree Printing

//inorder
// void inorder(struct node* root){
//     if(root != NULL){
//         inorder(root -> left);
//         printf("%d ",root-> data);
//         inorder(root -> right);
//     }
// }

//Preorder
// void preorder(struct node* root){
//     if(root != NULL){
//         printf("%d ",root-> data);
//         inorder(root -> left);
//         inorder(root -> right);
//     }
// }

//Postorder
// void postorder(struct node* root){
//     if(root != NULL){
        
//         inorder(root -> left);
//         inorder(root -> right);
//         printf("%d ",root-> data);
//     }
// }

