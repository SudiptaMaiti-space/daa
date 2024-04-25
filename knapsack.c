#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};

int compare(const void *a, const void *b) {
    double ratio_a = ((double)((struct Item *)a)->value) / ((struct Item *)a)->weight;
    double ratio_b = ((double)((struct Item *)b)->value) / ((struct Item *)b)->weight;
    return ratio_b - ratio_a > 0 ? 1 : -1;
}


double fractional_knapsack(struct Item items[], int n, int capacity, int selected[]) {

    qsort(items, n, sizeof(struct Item), compare);

    double total_value = 0.0;
    int current_weight = 0;


    for (int i = 0; i < n; i++) {
        selected[i] = 0;
    }

    int index = 0;
    while (current_weight < capacity && index < n) {
        if (current_weight + items[index].weight <= capacity) {
            selected[index] = 1;
            current_weight += items[index].weight;
            total_value += items[index].value;
        } else {

            double fraction = (double)(capacity - current_weight) / items[index].weight;
            selected[index] = fraction > 0 ? 1 : 0;
            current_weight += items[index].weight * fraction;
            total_value += items[index].value * fraction;
        }
        index++;
    }

    return total_value;
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct Item *items = malloc(n * sizeof(struct Item));
    int *selected = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Enter value for item %d: ", i + 1);
        scanf("%d", &items[i].value);
        printf("Enter weight for item %d: ", i + 1);
        scanf("%d", &items[i].weight);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    double total_value = fractional_knapsack(items, n, capacity, selected);

    printf("Total value in knapsack: %.2f\n", total_value);
    printf("Solution Vector: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", selected[i]);
    }
    printf("\n");

    free(items);
    free(selected);
    return 0;
}

