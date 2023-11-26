#include <stdio.h>

int binarySearch(int a[], int r, int target)
{
    int l = 0, mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (a[mid] == target)
            return mid;
        else if (a[mid] < target)
            l = mid;
        else
            r = mid + 1;
    }
    return -1;
}

int main()
{
    int a[100], n = 0, target, i = 0, result;

    printf("no. of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n ", n);

    for (; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nTarget: ");
    scanf("%d", &target);
    result = binarySearch(a, n, target);
    if (result == -1)
        printf("Element not found in the list.\n");
    else
        printf("Element found at index %d\n", result);
}