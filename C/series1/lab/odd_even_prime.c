#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void inserTerm(struct node **head, int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    newnode->data = data;
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
        struct node *temp = *head;
        // traverse to end
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void create(struct node **head)
{
    int n, input;
    printf("Enter no. of nodes required: ");
    scanf("%d", &n);
    printf("Enter %d nodes:\n", n);
    while (n--)
    {
        scanf("%d", &input);
        inserTerm(head, input);
    }
}

void traverse(struct node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int isPrime(int a)
{
    if (a <= 1)
        return 0;

    int i = 2;
    for (i; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    struct node *head = NULL, *prime = NULL, *notprime = NULL, *temp;
    create(&head);
    traverse(head);
    temp = head;
    while (temp != NULL)
    {

        if (isPrime(temp->data))
            inserTerm(&prime, temp->data);
        else
            inserTerm(&notprime, temp->data);
        temp = temp->next;
    }
    printf("Prime Numbers: ");
    traverse(prime);
    printf("Non-Prime Numbers: ");
    traverse(notprime);
    prime = notprime = NULL;
    temp = head;
    while (temp != NULL)
    {

        if (temp->data % 2 == 0)
            inserTerm(&prime, temp->data);
        else
            inserTerm(&notprime, temp->data);
        temp = temp->next;
    }
    printf("EVEN Numbers: ");
    traverse(prime);
    printf("ODD Numbers: ");
    traverse(notprime);

    return 0;
}

// OUTPUT
// Enter no. of nodes required: 5
// Enter 5 nodes:
// 1 2 3 4 5
// 1 -> 2 -> 3 -> 4 -> 5 -> NULL
// Prime Numbers: 2 -> 3 -> 5 -> NULL
// Non-Prime Numbers: 1 -> 4 -> NULL
// EVEN Numbers: 2 -> 4 -> NULL
// ODD Numbers: 1 -> 3 -> 5 -> NULL