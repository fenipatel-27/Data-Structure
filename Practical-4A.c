#include <stdio.h>
char stack[50];
int top = -1;
void push(char x)
{
    stack[++top] = x;
}
char pop()
{
    return stack[top--];
}
int priority(char x)
{
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return 0;
}
void main()
{
    char infix[50], postfix[50];
    int i = 0, j = 0;
    char x;
    printf("Enter infix expression: ");
    gets(infix);
    while (infix[i] != '\0')
    {
        x = infix[i];
        if (isalnum(x))
        {
            postfix[j++] = x;
        }
        else if (x == '(')
        {
            push(x);
        }
        else if (x == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            pop();
        }
        else
        {
            while (top != -1 && priority(stack[top]) >= priority(x))
            {
                postfix[j++] = pop();
            }
            push(x);
        }
        i++;
    }
    while (top != -1)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    printf("Postfix expression = %s", postfix);
}