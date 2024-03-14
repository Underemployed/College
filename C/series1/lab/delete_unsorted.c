#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *next;
    int data;
};

struct node *insertNode(struct node *head, int num)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node)),
                *temp = head;
    newnode->data = num;
    newnode->next = NULL; // to prevent infinite traverse
    while (temp != NULL && temp->next != NULL)
    {
        temp = temp->next;
    }
    if (temp == NULL)
        head = newnode;
    else
    {
        temp->next = newnode;
    }
    return head;
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
void main()
{
    struct node *head = NULL;

    printf("Enter elements: \n");
    int input;
    while (input != -999)
    {

        scanf("%d", &input);
        if (input == -999)
            break; // stop input on -999
        head = insertNode(head, input);
    }

    printf("Original List:\n");
    traverse(head);
    int no_unsorted = 1;
    struct node *i = head;

    while (i != NULL && i->next != NULL) // checking if i or i-> next is NULL....
    {
        if (i->data > i->next->data) // never forget check values u compare otherwise error here i need to check i and i->next are null or not
        {
            i->next = i->next->next;
            no_unsorted = 0;
            // head = i; no need i guess...
            continue;
            // set to false....
        }
        i = i->next;
    }

    if (no_unsorted)
        printf("List already sorted\n");
    else
        printf("List after deleting unsorted elements:\n");
    traverse(head);
}