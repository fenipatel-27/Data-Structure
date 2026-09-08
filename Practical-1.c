#include <stdio.h>
int main()
{
    int a[10], n, choice, i, pos, value, search;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    do
    {
        printf("\n\n1. Traversal");
        printf("\n2. Insertion");
        printf("\n3. Deletion");
        printf("\n4. Search");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Array: ");
                for(i = 0; i < n; i++)
                    printf("%d ", a[i]);
                break;
            case 2:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);
                for(i = n; i >= pos; i--)
                    a[i] = a[i-1];
                a[pos-1] = value;
                n++;
                printf("Element inserted.");
                break;
            case 3:
                printf("Enter position: ");
                scanf("%d", &pos);
                for(i = pos-1; i < n-1; i++)
                    a[i] = a[i+1];
                n--;
                printf("Element deleted.");
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &search);
                for(i = 0; i < n; i++)
                {
                    if(a[i] == search)
                    {
                        printf("Element found at position %d", i+1);
                        break;
                    }
                }
                if(i == n)
                    printf("Element not found.");
                break;
            case 5:
                printf("Exit");
                break;
            default:
                printf("Invalid choice.");
        }
    } while(choice != 5);
    return 0;
}