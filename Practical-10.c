#include <stdio.h>

void bubbleSort(int a[], int n)
{
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int a[], int n)
{
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void display(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
}

int main()
{
    int a[100], b[100], n, i, ch;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    printf("\n1. Bubble Sort");
    printf("\n2. Selection Sort");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);

    if (ch == 1)
    {
        bubbleSort(a, n);
        printf("Bubble Sort: ");
        display(a, n);
    }
    else if (ch == 2)
    {
        selectionSort(b, n);
        printf("Selection Sort: ");
        display(b, n);
    }
    else
    {
        printf("Invalid choice");
    }

    return 0;
}