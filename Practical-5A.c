#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue()
{
    int value;

    if(rear == SIZE-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        printf("Enter value : ");
        scanf("%d",&value);

        if(front == -1)
            front = 0;

        rear++;
        queue[rear] = value;

        printf("Element inserted\n");
    }
}

void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Deleted element : %d\n", queue[front]);

        front++;

        if(front > rear)
            front = rear = -1;
    }
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements:\n");

        for(i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                break;

            default:
                printf("Invalid choice\n");
        }

    }while(choice != 4);

    return 0;
}