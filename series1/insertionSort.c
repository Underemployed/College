#include <stdio.h>
#include <stdlib.h>  

void swap(int *c, int *b) {
    int temp = *c;
    *c = *b;
    *b = temp;
}

void selectionSort(int *a, int n) {
    int i=1, j;
    while (i<n){
        j=i;
        while (j>0 && a[j-1]>a[j])
        {
            swap(&a[j-1],&a[j]);
            j--;
        }
        i++;
    }
}

int main() {
    int a[100], i = 0, n = 0;

    printf("No. of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }

    selectionSort(a, n);


    printf("\nSorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
