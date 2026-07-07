#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;

} node;

node *createNode(int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

node *insert(node *root, int data)
{
    node *newnode = createNode(data);
    if (root == NULL)
    {
        return newnode;
    }
    node *current = root;
    node *parent = NULL;

    while (current != NULL)
    {
        parent = current;
        if (data < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    if (data < parent->data)
    {
        parent->left = newnode;
    }
    else
    {
        parent->right = newnode;
    }

    return root;
}
void display(node *root)
{
    if (root == NULL)
    {
        return;
    }
    display(root->left);
    printf("%d ", root->data);
    display(root->right);
}
// node* create(node* root , int data){
//     if(root == NULL){
//         return NULL;
//     }
// }

// node* insert(node* root, int data,node* left, node* right){
//     node* newnode = (node*)malloc(sizeof(node));
//     if(root == NULL){
//         return NULL;
//     }
//     while(root != NULL){
//         if(newnode -> data  < root){
//             newnode->data = left;
//         }
//         else{
//             newnode -> data = right;
//         }
//     }

// }
int main()
{
    node *root = NULL;
    int data;
    printf("Enter data to insert in the tree: ");
    while (1)
    {
        scanf("%d", &data);
        if (data == -1)
        {
            break;
        }
        root = insert(root, data);
    }
    display(root);
    return 0;
}