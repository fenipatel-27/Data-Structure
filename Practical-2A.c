
#include <stdio.h>

int main()
{
    int x[10], i, n;
    int *p;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x[i]);
    }

    p = &x[0] + n - 1;

    printf("Array elements in reverse order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d", *p);
        p--;
    }

    return 0;
}