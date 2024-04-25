#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1; 
    }

    int mid = (low + high) / 2;

    if (arr[mid] == target) {
        return mid; 
    } else if (arr[mid] < target) {
        return binarySearch(arr, mid + 1, high, target); 
    } else {
        return binarySearch(arr, low, mid - 1, target);
    }
}

int main() {
    int n, target;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    srand(time(NULL));
    printf("Generated random elements:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; 
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    clock_t start_time = clock(); 

    int index = binarySearch(arr, 0, n - 1, target);

    clock_t end_time = clock(); 

    if (index != -1) {
        printf("Element found at index %d\n", index);
    } else {
        printf("Element not found in the array\n");
    }
    double cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("CPU time taken: %f seconds\n", cpu_time_used);

    return 0;
}

