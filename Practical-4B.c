#include "stack.h"
#include <stdio.h>
#include <ctype.h>

int calc(char op, int op1, int op2);

void main()
{
    char post[50];
    int p1, p2, r, i = 0;

    printf("Enter postfix expression: ");
    gets(post);

    while (post[i] != '\0')
    {
        if (isdigit(post[i]))
        {
            push(post[i] - '0');
        }
        else
        {
            p1 = pop();
            p2 = pop();
            r = calc(post[i], p2, p1);
            push(r);
        }
        i++;
    }

    r = pop();

    printf("Result = %d", r);
}

int calc(char op, int op1, int op2)
{
    int r = 0;

    switch(op)
    {
        case '+':
            r = op2 + op1;
            break;

        case '-':
            r = op2 - op1;
            break;

        case '*':
            r = op2 * op1;
            break;

        case '/':
            r = op2 / op1;
            break;

        default:
            r = 0;
    }
    return r;
}