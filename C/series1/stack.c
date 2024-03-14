#include <stdio.h>
#include <stdlib.h>

int stack[200], top = 100, n = 0;

void print()
{
    printf("{");
    char c;
    for (int i = 0; i < n; i++)
    {
        c = (i < n - 1) ? ',' : '}\n';
        printf("%d%c", stack[i], c);
    }
}

void push(int element)
{
    if (n < top)
        stack[n++] = element;
    else
        printf("Stack Full\n");
}

void isEmpty()
{
    if (n == 0)
        printf("Empty\n");
    else
        printf("Is not Empty\n");
}

void isFull()
{
    if (n == top)
        printf("Full\n");
    else
        printf("Is not Full\n");
}

void pop()
{
    if (n == 0)
        printf("Stack is Empty\n");
    else
        n--;
}

int main()
{
    char choice;
    int element;

    printf("Enter the size of stack: ");
    scanf("%d", &top);

    while (1)
    {
        printf("\nStack Operations\n");
        printf("1. Print\n");
        printf("2. Push\n");
        printf("3. Pop\n");
        printf("4. Check if Empty\n");
        printf("5. Check if Full\n");
        printf("Any other number to Exit\n");
        print();

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1':
            print();
            break;
        case '2':
            printf("Enter element to push: ");
            scanf("%d", &element);
            push(element);
            break;
        case '3':
            pop();
            break;
        case '4':
            isEmpty();
            break;
        case '5':
            isFull();
            break;
        default:
            printf("Exiting...\n");
            exit(1);
        }
    }

    return 0;
}
