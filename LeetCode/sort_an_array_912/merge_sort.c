#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int left, int right, int mid) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    int i = 0, j = 0, k = left;

    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + j + 1];
    }

    i = 0;
    j = 0;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(int* arr, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, right, mid);
    }
}

int main() {
    int inputArray[] = {5, 1, 1, 2, 0, 0};
    int size = sizeof(inputArray) / sizeof(inputArray[0]);

    mergeSort(inputArray, 0, size - 1);

    for (int i = 0; i < size; i++) {
        printf("%d ", inputArray[i]);
    }

    return 0;
}
