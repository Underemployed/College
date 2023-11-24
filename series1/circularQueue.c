#include <stdio.h>
#include <stdlib.h>
int rear = -1, front = -1, top = 5, i = 0;
int a[5]; // Assuming the array size is 5
                         
void enqueue() {
    if ((rear + 1) % top == front) {
        printf("Queue is Full\n");
        return;
    } else if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % top;
    }
    a[rear] = i++;

}

void dequeue(){
    if(front==-1){
        printf("List empty"); return;
    }else if(front == rear){
        front=rear=-1;
        return;

    }
    a[front]=-1;
    front=(front+1)%top;
    return;
}

void print() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }
    int j = front;
    if(front>=0)
    {    
    while ((j)%top != rear 
    ) {
        printf("%d ", a[j]);
        j = (j + 1) % top;
    } 
    printf("%d ", a[j]);

    }
    printf("\nfront=%d;rear=%d\n",front,rear);
}

int main() {
    char choice;

    while(1) {
        print();
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print\n");
        printf("Any other input to exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                enqueue();
                break;
            case '3':
                print();
                break;
            case '2':        
                dequeue();     
                break;

            default:
                printf("Exiting Program\n");
                exit(1);
        }

    } 

    return 0;
}
