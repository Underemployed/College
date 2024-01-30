#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *a, int n){
    int i, j, temp, k;
    for (i = 0; i < n; i++){
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]){
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }  
    }
}

void main()
{
    int a[100], i = 0, n = 0;
    printf("No. of elements: ");scanf("%d", &n);
    printf("Orginal Array: ");
    for (i = 0; i < n; i++){
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }
    bubbleSort(a, n);
    printf("\nSorted array: ");
    for (i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}
