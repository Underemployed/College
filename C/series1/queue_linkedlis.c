#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

struct node *start;
int n, actual;
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
        printf("front =%d,rear=%d");

    }
}
void create()
{
    if (start == NULL)
    {
        int i;
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

void dequeue()
{
    if (start != NULL)
    {

        struct node *curr = start;
        if (actual == 1)
        {
            start = NULL;
            return;
        }

        struct node *prev;
        while (curr->link != NULL)
        {
            prev = curr;
            curr = curr->link;
        }
        prev->link = curr->link;
    }
    else
    {
        printf("\nQueue is Empty*********\n\n");
    }
    traverse();
}
void length()
{
    actual = 0;
    struct node *curr = start;
    while (curr != NULL)
    {
        curr = curr->link;
        actual++;
    }
}
void push()
{
    if (actual < n)
    {
                int data;
        printf("Enter value: ");
        scanf("%d", &data);

        struct node *curr = start, *newnode;
        newnode = malloc(sizeof(struct node));
        newnode->data = data;
        if (actual <=0) {
            start = newnode;
            newnode->link=NULL;
        }


        struct node *prev;
        while (curr != NULL)
        {
            prev = curr;
            curr = curr->link;
        }
        newnode->link = prev->link;
        prev->link = newnode;
        newnode->link=NULL;
    }
    else
    {
        printf("\nQueue Full*********\n\n");
    }
    traverse();
}

int main()
{
    char choice;
    create();
    while (1)
    {
        length();
        printf("\n1. Traverse\n2. Push\n3. pop\nAny other input to Exit\n");
        printf("Enter your choice:");
        scanf(" %c", &choice);



        switch (choice)
        {
        case '1':
            traverse();
            break;
        case '2':
            push();
            break;
        case '3':
            dequeue();
            break;
        default:
            printf("Exiting\n");
            exit(0);
        }
    }

    return 0;
}