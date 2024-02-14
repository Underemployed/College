#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
int stack[100];
int top = -1;
void push(int x)
{
    stack[++top] = x;
}
int pop()
{
    if (top == -1)
        return 0;
    return stack[top--];
}
void postfix(char *exp)
{
    char curr, operator;
    int i = 0, A, B;
    for (; exp[i] != '\0'; i++)
    {
        curr = exp[i];

        if (isdigit(curr))
        {
            push(curr - '0');
        }
        else
        {
            operator= curr;
            B = pop();
            A = pop();
            switch (operator)
            {
            case '+':
                push(A + B);
                break;
            case '-':
                push(A - B);
                break;
            case '*':
                push(A * B);
                break;
            case '/':
                push(A / B);
                break;
            case '^':
                push(pow(A, B));
                break;
            default:
                printf("Invalid Expression");
                exit(1);
            }
        }
    }
    printf("%d", pop());
}
int main()
{
    char expression[100];

    scanf("%s", expression);
    postfix(&expression);
    return 0;
}