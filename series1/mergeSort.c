#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    int i = 0, j = 0, k = left;
    while (i < n1)  L[i++] = arr[left + i];
    while (j < n2)  R[j++] = arr[mid + 1 + j];
    i = j = 0;
    while (i < n1 && j < n2)    if (L[i] <= R[j])   arr[k++] = L[i++];  else    arr[k++] = R[j++];
    while (i < n1)  arr[k++] = L[i++];
    while (j < n2)  arr[k++] = R[j++];
}
void mergeSort(int *arr, int left, int right){
    if (left < right){
        int mid = (right + left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
void main(){
    int arr[100], i = 0, n = 0;
    printf("No. of elements: ");    scanf("%d", &n);
    printf("Orginal Array: ");
    for (i = 0; i < n; i++){
        arr[i] = rand() % 100;// random integers
        printf("%d ", arr[i]);
    }
    mergeSort(arr, 0, n - 1);
    printf("\nSorted array: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
}
