#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *start = NULL;
struct node *insertTerm(struct node *start, int val);
struct node *Sort_insertTerm(struct node *start, int val);
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
    // if (start == NULL)
    // {
    //     int n, i;
    //     struct node *curr, *prev;
    //     curr = malloc(sizeof(struct node));
    //     curr->data = 1;
    //     printf("how many nodes do u want: ");
    //     scanf("%d", &n);
    //     start = curr;
    //     for (i = 2; i < n + 1; i++)
    //     {
    //         prev = curr;
    //         curr = malloc(sizeof(struct node));
    //         curr->data = i;
    //         prev->link = curr;
    //     }
    //     curr->link = NULL;
    //     traverse();
    // }

    int i = 0, n;
    printf("how many nodes do u want: ");
    scanf("%d", &n);
    while (i < n)
    {
        start = insertTerm(start, rand() % 30);
        // start = Sort_insertTerm(start, rand() % 20);
        i++;
    }
}
struct node *insertTerm(struct node *head, int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    newnode->data = val;
    newnode->link = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newnode;
    }
    return head;
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
struct node *Sort_insertTerm(struct node *head, int val)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    newnode->data = val;
    newnode->link = NULL;
    if (head == NULL || head->data > val)
    {
        newnode->link = head;
        head = newnode;
    }
    else
    {
        while (temp->link != NULL && temp->link->data < val)
        {
            temp = temp->link;
        }
        newnode->link = temp->link;
        temp->link = newnode;
    }
    return head;
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
    char choice;
    create();

    while (1)
    {

        printf("\n1. Traverse\n2. Insert\n3. Delete\n4. Reverse\nAny other input to Exit\n");
        traverse();
        printf("\nEnter your choice:");
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            traverse();
            break;
        case '2':
            insert();
            break;
        case '3':
            delete ();
            break;
        case '4':
            reverse(start);
            break;
        case '5':
            start = insertTerm(start, -999);
            break;
        default:
            printf("Exiting\n");
            exit(0);
        }
    }

    return 0;
}