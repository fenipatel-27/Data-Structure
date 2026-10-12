#include <stdio.h>
int b_search(int p[], int l, int r, int k)
{
    int mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (k == p[mid])
            return mid;
        if (k < p[mid])
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
int main()
{
    int a[10], n, key, i, result;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements in sorted order:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    result = b_search(a, 0, n - 1, key);
    if (result != -1)
        printf("Element found at position %d", result + 1);
    else
        printf("Element not found");
    return 0;
}