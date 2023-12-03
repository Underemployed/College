#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traverse(struct node *head)
{
    struct node *temp = head;
    if (head != NULL)
    {
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
    }
    printf("NULL\n");
}

struct node *create()
{
    struct node *start;
    int n, i;
    struct node *curr, *prev;

    start = NULL;

    printf("How many nodes do you want: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        curr = malloc(sizeof(struct node));
        curr->data = rand() % 20;

        if (start == NULL)
        {
            start = curr;
        }
        else
        {
            prev->next = curr;
        }

        prev = curr;
    }
    curr->next = NULL;

    if (start != NULL)
    {
    }

    return start;
}

struct node *insert(struct node *head, int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL || value < head->data)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        struct node *curr = head;
        while (curr->next != NULL && curr->next->data < value)
        {
            curr = curr->next;
        }
        newnode->next = curr->next;
        curr->next = newnode;
    }
    return head;
}

struct node *merge(struct node *head1, struct node *head2)
{
    struct node *merge = head1;
    struct node *temp = merge;
    while (temp != NULL && temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp != NULL)
    {
        temp->next = head2;
    }
    else
    {
    }

    return merge;
}

struct node *sort(struct node *org)
{
    struct node *temp = org;
    struct node *head = NULL;
    while (temp != NULL)
    {
        head = insert(head, temp->data);
        temp = temp->next;
    }
    return head;
}

int main()
{
    struct node *head1 = create();
    struct node *head2 = create();
    traverse(head1);
    traverse(head2);

    struct node *merged = merge(head1, head2);
    traverse(merged);

    merged = sort(merged);
    traverse(merged);

    return 0;
}
