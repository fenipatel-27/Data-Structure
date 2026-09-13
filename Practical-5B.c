#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

void enqueue()
{
    int value;

    if ((rear + 1) % SIZE == front)
        printf("Queue is Full\n");
    else
    {
        printf("Enter value: ");
        scanf("%d", &value);

        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % SIZE;

        queue[rear] = value;
        printf("Element inserted\n");
    }
}

void dequeue()
{
    if (front == -1)
        printf("Queue is Empty\n");
    else
    {
        printf("Deleted element: %d\n", queue[front]);

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }
}

void display()
{
    int i;

    if (front == -1)
        printf("Queue is Empty\n");
    else
    {
        printf("Queue elements: ");

        i = front;
        while (1)
        {
            printf("%d ", queue[i]);

            if (i == rear)
                break;

            i = (i + 1) % SIZE;
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
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: break;
            default: printf("Invalid choice\n");
        }
    } while(choice != 4);

    return 0;
}