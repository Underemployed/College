#include <stdio.h>
int linearSearch(int *arr, int target, int size) {
    for (int i = 0; i < size; i++) if (arr[i] == target) return i;
    return -1;
}
void main() {
    int arr[100], n, target;
    printf("No. of elements: "); scanf("%d", &n);
    printf("Array: "); for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    printf("Target: "); scanf("%d", &target);
    int result = linearSearch(arr, target, n);
    printf(result != -1 ? "Target found at index %d\n" : "Target not found\n", result);
}
