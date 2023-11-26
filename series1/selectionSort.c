#include <stdio.h>
#include <stdlib.h>

void swap(int *c, int *b)
{
    int temp = *c;
    *c = *b;
    *b = temp;
}

void selectionSort(int *a, int n)
{
    int i = 0, j, minIdx;
    while (i < n - 1)
    {
        minIdx = i;
        j = i + 1;
        while (j < n)
        {
            if (a[minIdx] > a[j])
                minIdx = j;
            j++;
        }
        swap(&a[i], &a[minIdx]);
        i++;
    }
}

int main()
{
    int a[100], i = 0, n = 0;

    printf("No. of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }

    selectionSort(a, n);

    printf("\nSorted array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
