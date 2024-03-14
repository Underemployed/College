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
// levelorder traversal
struct node *queue[100];
int front = -1, rear = -1;

void enqueue(struct node *element)
{
    if (rear == -1)
    {
        front = rear = 0;
        queue[rear] = element;
    }
    else
    {
        rear++;
        queue[rear] = element;
    }
}

struct node *dequeue()
{
    struct node *temp = NULL;
    if (front <= rear)
    {
        temp = queue[front];
        front++;
        if (front > rear) // reset when we've dequeued everything
        {
            front = rear = -1;
        }
    }
    return temp;
}
int isEmpty()
{
    if (front == -1)
        return 1;
    else
        return 0;
}

int size() { return rear - front + 1; }

// void levelordertraversal(struct node *root)
// {
//     if (root == NULL)
//         printf("Tree empty");
//     else
//     {
//         enqueue(root);
//         while (!isEmpty())
//         {
//             struct node *curr = dequeue();
//             if (curr != NULL)
//             {
//                 printf("%d ", curr->data);
//                 if (curr->left != NULL)
//                     enqueue(curr->left);

//                 if (curr->right != NULL)
//                     enqueue(curr->right);
//             }
//         }
//     }
// }

void levelordertraversal(struct node *root)
{ 
    if (root == NULL)
        printf("Tree empty");
    else
    {
        enqueue(root);
        while (!isEmpty())
        {
            int nodeCount = size(); // Get the number of nodes at the current level

            // Dequeue all nodes of this level and enqueue all nodes of the next level
            while (nodeCount > 0)
            {
                struct node *curr = dequeue();
                printf("%d ", curr->data);
                if (curr->left != NULL)
                    enqueue(curr->left);
                if (curr->right != NULL)
                    enqueue(curr->right);
                nodeCount--;
            }

            printf("\n");
        }
    }
}
int search(struct node *root, int x)
{
    if (root != NULL)
    {
        int left = search(root, x);

        int right = search(root, x);
        if (left || right)
            return 1;
    }
    return 0;
}

void main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    // root = insert(root, 7);
    // root = insert(root, 8);
    // root = delete (root, 7);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    levelordertraversal(root);
    if (search(root, 5))
    {
        printf("FOund\n");
    }
}
