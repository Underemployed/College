#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* insertatEnd(struct node* head, int val) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node)); // newnode allocate address
    struct node* temp = head;
    newnode->data = val;
    newnode->next = NULL;
    // new node data set and next null
    if (head == NULL) {
        head = newnode;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        } // traverse last node
        temp->next = newnode; // last node points to new node
    }
    return head;
}

struct node* create(struct node* head, int n) {
    int i = 0;
    while (i < n) { // Changed to i < n to create n nodes
        head = insertatEnd(head, rand() % 30); // head and value
        i++;
    }
    return head;
}

void traverse(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void search(struct node* head, int val) {
    struct node* temp = head;
    while (temp != NULL) { 
        if (temp->data == val) {
            printf("found\n");
            return;
        }
        temp = temp->next;
    }
    printf("not found\n");
}

struct node* merge(struct node* head1, struct node* head2) {
    struct node* result = NULL;
    struct node* i = head1;
    struct node* j = head2;
    int count = 0;
    while (i != NULL && j != NULL) {
        if (count % 2 == 0) {
            result = insertatEnd(result, i->data);
            i = i->next;
        } else {
            result = insertatEnd(result, j->data);
            j = j->next;
        }
        count++;
    }
    // travel to the end of the list
    struct node* temp = result;
    while (temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    // if not null rest linked to result
    if (i != NULL) {
            temp->next = i;
    
    } 
    if (j!=NULL) {
            temp->next = j;

    }
    return result;
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    head1 = create(head1, 5);
    head2 = create(head2, 3);
    traverse(head1);
    traverse(head2);
    struct node* head = merge(head1, head2);
    traverse(head);
    return 0;
}