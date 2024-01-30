#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->left = newnode->right = NULL;
    newnode->data = val;
    return newnode;
}
void preorder(struct node *node)
{ // root left right
    if (node == NULL)
        return;
    printf("%d", node->data);
    preorder(node->left);
    preorder(node->right);
}

void postorder(struct node *node)
{ // left right root
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%d", node->data);
}

void inorder(struct node *node)
{ // left root right
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%d", node->data);
    inorder(node->right);
}

void main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
}
