#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int deg;
    struct node *link;
};

struct node *start1 = NULL;
struct node *start2 = NULL;
struct node *sum_start = NULL;

// Function to insert a term into the linked list
void insertTerm(struct node **start, int data, int deg)
{
    struct node *new, *last;

    new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->deg = deg;
    new->link = NULL;

    if (*start == NULL)
    {
        *start = new;
    }
    else
    {
        last = *start;
        while (last->link != NULL)
        {
            last = last->link; // traverse to last node
        }
        last->link = new; // link node
    }
}

// Function to add two polynomials
void addPolynomials(struct node *poly1, struct node *poly2)
{

    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->deg > poly2->deg)
        {
            insertTerm(&sum_start, poly1->data, poly1->deg);
            poly1 = poly1->link;
        }
        else if (poly1->deg == poly2->deg)
        {
            insertTerm(&sum_start, poly1->data + poly2->data, poly1->deg);
            poly1 = poly1->link;
            poly2 = poly2->link;
        }
        else
        {
            insertTerm(&sum_start, poly2->data, poly1->deg);
            poly2 = poly2->link;
        }
    }
    struct node *temp = sum_start;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = poly1;
    temp = sum_start;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = poly2;
}

// Function to display a polynomial
void displayPolynomial(struct node *start)
{
    if (start != NULL)
    {
        struct node *curr = start;
        while (curr != NULL)
        {
            printf("%dx^%d", curr->data, curr->deg);
            curr = curr->link;
            if (curr != NULL)
            {
                printf(" + ");
            }
        }
        printf("\n");
    }
}

int main()
{
    // Example: 3x^3 + 4x^2 + 5x^1
    insertTerm(&start1, 3, 3);
    insertTerm(&start1, 4, 2);
    insertTerm(&start1, 5, 1);

    // Example: 2x^3 + 3x^2 + 1x^0
    insertTerm(&start2, 2, 3);
    insertTerm(&start2, 3, 2);
    insertTerm(&start2, 1, 0);

    // Display the polynomials
    printf("Polynomial 1: ");
    displayPolynomial(start1);
    printf("Polynomial 2: ");
    displayPolynomial(start2);

    // Add the polynomials
    addPolynomials(start1, start2);

    // Display the result
    printf("Sum of Polynomials: ");
    displayPolynomial(sum_start);

    return 0;
}
