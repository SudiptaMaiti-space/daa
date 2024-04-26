#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linear_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  
        }
    }
    return -1; 
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

  
    srand(time(0));

    printf("Generated random array:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;  
        printf("%d ", arr[i]);
    }
    printf("\n");

    int key;
    printf("Enter the element to search for: ");
    scanf("%d", &key);

   
    clock_t start_time = clock();

    int index = linear_search(arr, n, key);

    clock_t end_time = clock();

    if (index != -1) {
        printf("Element %d found at index %d.\n", key, index);
    } else {
        printf("Element %d not found in the array.\n", key);
    }

    double cpu_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("CPU Time taken: %.6f seconds\n", cpu_time);

    return 0;
}

