#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to get the precedence of an operator
int getPrecedence(char ch) {
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    char stack[MAX_SIZE];
    int top = -1;
    int i, j;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        // If the current character is an operand, add it to the postfix expression
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        // If the current character is an opening parenthesis, push it to the stack
        else if (infix[i] == '(') {
            stack[++top] = infix[i];
        }
        // If the current character is a closing parenthesis, pop operators from the stack and add them to the postfix expression until an opening parenthesis is encountered
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top == -1) {
                printf("Invalid infix expression\n");
                exit(1);
            }
            top--; // Discard the opening parenthesis
        }
        // If the current character is an operator
        else if (isOperator(infix[i])) {
            // Pop operators from the stack and add them to the postfix expression until an operator with lower precedence is encountered or the stack is empty
            while (top != -1 && stack[top] != '(' && getPrecedence(stack[top]) >= getPrecedence(infix[i])) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i]; // Push the current operator to the stack
        }
        else {
            printf("Invalid character in infix expression\n");
            exit(1);
        }
    }

    // Pop any remaining operators from the stack and add them to the postfix expression
    while (top != -1 && stack[top] != '(') {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    // Remove the trailing newline character from the input
    infix[strcspn(infix, "\n")] = '\0';

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
