#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Pair {
    int min;
    int max;
};

struct Pair find_max_min(int arr[], int low, int high) {
    struct Pair result, left, right;
    int mid;


    if (low == high) {
        result.min = arr[low];
        result.max = arr[low];
        return result;
    }


    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            result.min = arr[low];
            result.max = arr[high];
        } else {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }


    mid = (low + high) / 2;
    left = find_max_min(arr, low, mid);
    right = find_max_min(arr, mid + 1, high);


    if (left.min < right.min)
        result.min = left.min;
    else
        result.min = right.min;

    if (left.max > right.max)
        result.max = left.max;
    else
        result.max = right.max;

    return result;
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

    clock_t start_time = clock();

    struct Pair result = find_max_min(arr, 0, n - 1);

    clock_t end_time = clock();

    printf("Maximum element: %d\n", result.max);
    printf("Minimum element: %d\n", result.min);

    double cpu_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("CPU Time taken: %.6f seconds\n", cpu_time);

    return 0;
}

