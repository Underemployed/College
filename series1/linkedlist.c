#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *start;

void traverse()
{
    int i = 1;
    if (start != NULL)
    {
        struct node *curr = start;
        while (curr != NULL)
        {
            printf("%d)%d ", i, curr->data);
            curr = curr->link;
            i++;
        }
    }
}
void create()
{
    if (start == NULL)
    {
        int n, i;
        struct node *curr, *prev;
        curr = malloc(sizeof(struct node));
        curr->data = 1;
        printf("how many nodes do u want: ");
        scanf("%d", &n);
        start = curr;
        for (i = 2; i < n + 1; i++)
        {
            prev = curr;
            curr = malloc(sizeof(struct node));
            curr->data = i;
            prev->link = curr;
        }
        curr->link = NULL;
        traverse();
    }
}

void delete()
{
    int pos, i = 1;
    printf("Enter index to be deleted: ");
    scanf("%d", &pos);
    struct node *curr = start;
    if (pos <= 1)
    {
        curr = curr->link;
        start = curr;
    }
    else
    {
        struct node *prev;
        while (i < pos && curr->link != NULL)
        {
            prev = curr;
            curr = curr->link;
            i++;
        }
        prev->link = curr->link;
    }
    traverse();
}
void insert()
{
    int pos, data, i = 1;
    printf("Enter index to be inserted: ");
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &data);

    struct node *curr = start, *newnode;
    newnode = malloc(sizeof(struct node));
    newnode->data = data;

    if (pos <= 1)
    {
        newnode->link = start;
        start = newnode;
    }
    else
    {
        struct node *prev;
        while (i < pos && curr->link != NULL)
        {
            prev = curr;
            curr = curr->link;
            i++;
        }
        newnode->link = prev->link;
        prev->link = newnode;
    }
    traverse();
}
void reverse(struct node *head)
{
    if (head == NULL)
        return;
    reverse(head->link);
    printf("%d\n", head->data);
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Traverse\n3. Insert\n4. Delete\n5. Reverse\n6. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            traverse();
            break;
        case 3:
            insert();
            break;
        case 4:
            delete ();
            break;
        case 5:
            reverse(start);
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
        printf("\n");
    }

    return 0;
}