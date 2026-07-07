#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

// Create Node
node *createnode(int value)
{
    node *newnode = (node *)malloc(sizeof(node));

    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

// Insert
node *insert(node *root, int value)
{
    if (root == NULL)
        return createnode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Search
node *search(node *root, int key)
{
    while (root != NULL)
    {
        if (key == root->data)
            return root;

        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return key;
}

// Inorder Traversal
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder Traversal
void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder Traversal
void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Find Minimum
node *findmin(node *root)
{
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

// Find Maximum
node *findmax(node *root)
{
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

// Count Nodes
int countnodes(node *root)
{
    if (root == NULL)
        return 0;

    return 1 + countnodes(root->left) + countnodes(root->right);
}

// Height of Tree
int height(node *root)
{
    if (root == NULL)
        return -1;

    int lh = height(root->left);
    int rh = height(root->right);

    return (lh > rh) ? lh + 1 : rh + 1;
}

// delete node
node *deleteNode(node *root, int value)
{
    struct node *temp;
    if (root == NULL)
    {
        return root;
    }
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        temp = findmin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// INORDER SUCCESSOR
node *inordersuccessor(node *node)
{
    return findmin(node->right);
}
// INORDER SUCCESSOR
node *inorderpredecessor(node *node)
{
    return findmax(node->left);
}

// Display (Inorder)
void display(node *root)
{
    if (root != NULL)
    {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}
int main(void)
{
    int key;
    node *root = NULL;
    root = insert(root, 2);
    root = insert(root, 15);
    root = insert(root, 18);
    root = insert(root, 20);
    root = insert(root, 25);
    root = insert(root, 30);
    root = insert(root, 45);
    printf("\n    === BST ===\n");
    display(root);

    printf("\nINORDER TRAVERSAL\n");
    inorder(root);
    printf("\nPREORDER TRAVERSAL\n");
    preorder(root);
    printf("\nPOSTORDER TRAVERSAL\n");
    postorder(root);
    // root = search(root, key);
    deleteNode(root, key);
}
