#include <stdio.h>
#include <ctype.h>
int isOperator(char c)
{
    return c == '^' || c == '*' || c == '/' || c == '+' || c == '-';
}
int precedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '^')
        return 3;
    else
        return -1;
}
void infixtopostfix(char *infix, char *postfix)
{
    int i, j, stack[100], top = -1;
    char c;

    for (i = 0, j = 0; infix[i] != '\0'; i++)
    {
        c = infix[i];
        if (c == '\n' || c == ' ')
            continue;
        if (isalnum(c))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            stack[++top] = c;
        }
        else if (c == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = stack[top];
                top--;
            }
            top--; // poping '('
        }
        else if (isOperator)
        {
            while (top >= 0 && precedence(stack[top]) >= precedence(c))
            {
                postfix[j++] = stack[top--];
            }
            stack[++top] = c; // pushing character
        }
    }
    while (top >= 0)
        postfix[j++] = stack[top--];
    postfix[j++] = '\0';
}
int main()
{
    char infix[100], postfix[100];
    printf("Enter postfix expression: ");
    scanf("%s", infix);
    infixtopostfix(infix, postfix);
    printf("%s", postfix);
}