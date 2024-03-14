#include <stdio.h>

int a1[100],front=0;rear=0,top=5,d=1;

void enqueue(int element){
    if(rear-front==top) printf("\nQueue full\n***********");
    else{
        a1[rear]=element;
        rear++;
    }

}

void dequeue(){

    if(front<rear) front++;
    else if(front==rear) printf("\nQueue empty\n***********");
    else return;
}
void isFull(){
    if(rear==front) printf("Queue Full\n");
    else printf("Queue not full\n");
}
void isEmpty(){
    if(front-rear== top) printf("Queue Empty\n");
    else printf("Queue not Empty\n");
}
void print(){
    printf("{");
    int i=front;
    for(;i<rear;i++){
        printf("%d ",a1[i]);
    }
    printf("}\n");
    printf("front =%d,rear=%d\n");


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
                enqueue(d++);
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

