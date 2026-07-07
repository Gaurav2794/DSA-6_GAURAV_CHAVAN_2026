//create a BST and count total number of node in the tree
/*
        100
    50       120

20    75         150


1.create
2.insert
3.display
 inorder
 preorder
 postorder
4.count node
5.find min
6.find max
7. search node
8. height of tree

*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create Node
struct node* createnode(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Insert Node
struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createnode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Inorder Traversal
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder Traversal
void preorder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Count Total Nodes
int countNodes(struct node* root) {
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Find Minimum
struct node* findMin(struct node* root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

// Find Maximum
struct node* findMax(struct node* root) {
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

// Search Node
struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

// Height of Tree
int height(struct node* root) {
    if (root == NULL)
        return -1;   // Height in terms of edges

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

int main() {

    struct node* root = NULL;

    // Creating the BST
    root = insert(root, 100);
    root = insert(root, 50);
    root = insert(root, 20);
    root = insert(root, 75);
    root = insert(root, 120);
    root = insert(root, 150);

    printf("Inorder Traversal : ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n\nTotal Nodes = %d", countNodes(root));

    struct node* min = findMin(root);
    printf("\nMinimum Node = %d", min->data);

    struct node* max = findMax(root);
    printf("\nMaximum Node = %d", max->data);

    int key;
    printf("\nEnter node to search: ");
    scanf("%d", &key);

    if (search(root, key))
        printf("%d Found in BST", key);
    else
        printf("%d Not Found in BST", key);

    printf("\nHeight of Tree = %d", height(root));

    return 0;
}