#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements in the array
void swap(int* b, int* c) {
    int temp = *b;
    *b = *c;
    *c = temp;
}

// Function to find the pivot element for QuickSort
// It partitions the array and returns the index of the pivot
int pivot(int *a, int left, int right) {
    int i = left - 1;
    int j = left;
    int pivot = right;

    while (j <= pivot) {
        if (a[j] < a[pivot]) {
            i++;
            swap(&a[i], &a[j]);
        }
        j++;
    }

    i++;
    swap(&a[i], &a[pivot]);// all values left of pivot small and similarly all values right of pivot is larger
    return i;// by doing this recursively and sorting by finding pivot ((all elements get sorted))

}

// Recursive function to perform QuickSort
void quickSort(int *a, int left, int right) {
    if (left < right) {
        // Find the pivot and partition the array
        int p = pivot(a, left, right);

        // Recursively sort the subarrays
        quickSort(a, left, p - 1);
        quickSort(a, p + 1, right);
    }
}

int main() {
    int a[100], i = 0, n = 0;

    printf("No. of elements: ");
    scanf("%d", &n);

    // Initialize array with random values
    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
        printf("%d ", a[i]);
    }

    // Perform QuickSort on the array
    quickSort(a, 0, n - 1);

    printf("\nSorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
