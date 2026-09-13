#include <stdio.h>
#include <stdlib.h>
#define s 5
int stk[s];
int tos = -1;
int empty()
{
    if (tos == -1)
        return 1;
    else
        return 0;
}
int full()
{
    if (tos == s-1)
        return 1;
    else
        return 0;
}
void push(int x)
{
    if (full())
        printf("\nStack is full\n");
    else
    {
        tos++;
        stk[tos] = x;
    }
}
void pop()
{
    int x;
    if (empty())
        printf("\nStack is Empty\n");
    else
    {
        x = stk[tos];
        tos--;
        printf("\nDeleted element = %d\n", x);
    }
}
void display()
{
    int i;
    if (empty())
        printf("\nStack is empty\n");
    else
    {
        printf("\nStack elements are:\n");
        for(i = tos; i >= 0; i--)
            printf("%d\n", stk[i]);
    }
}
int main()
{
    int ch, num;

    while(1)
    {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("Enter number: ");
                scanf("%d", &num);
                push(num);
                break;
            case 2:
                pop();
                break;
            case 3:
                if(empty())
                    printf("Stack is empty\n");
                else
                    printf("Top element = %d\n", stk[tos]);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}