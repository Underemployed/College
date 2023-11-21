#include <stdio.h>
#include <stdlib.h>

int a[100], top = 100, front=0;rear=0;

void create() {
    printf("Enter the max top for stack: ");
    scanf("%d", &top);
}

int isFull() {
    if (rear == top ) {
        printf("Queue is full\n");
        return 1;
    }
    return 0;
}

void print() {
    int i = 0;
    char ch;
    printf("\n{");
    for (i = front; i < rear; i++) {

        printf("%d,", a[i]);
    }
    printf("}\n");
}

int enqueue() {
    if (isFull()) {
        return 0;
    }
    int b;
    printf("Element: ");
    scanf("%d", &b);
    a[rear++] = b;
    print();
    return 0;
}

int isNULL() {
    if (rear == front) {
        printf("No elements in List\n");
        return 1;
    }
    return 0;
}

int dequeue() {
    if (isNULL()) {
        return 0;
    }
    a[front] = 0;
    front++;
    print();
    return 0;
}

int main() {
    int choice;
    create();

    while (1) {
        printf("1 To see list\n");
        printf("2 For push\n");
        printf("3 For delete\n");
        printf("4 To check if list is empty\n");
        printf("5 To check if list is full\n");
        printf("6 To exit\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                print();
                break;
            case 2:
                enqueue();
                break;
            case 3:
                dequeue();
                break;
            case 4:
                isNULL();
                break;
            case 5:
                isFull();
                break;
            case 6:
                exit(1);
                break;
            default:
                printf("Incorrect Choice\n");
        }
    }

    return 0;
}
