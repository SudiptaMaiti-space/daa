#include <stdio.h>
#include <stdlib.h>

struct Activity {
    int start;
    int finish;
};

int compare(const void *a, const void *b) {
    return ((struct Activity *)a)->finish - ((struct Activity *)b)->finish;
}

void activity_selection(struct Activity activities[], int n, int selected[]) {

    qsort(activities, n, sizeof(struct Activity), compare);

    selected[0] = 1; 

    int prev_finish = activities[0].finish;
    int index = 1;


    for (int i = 1; i < n; i++) {
        if (activities[i].start >= prev_finish) {
            selected[index++] = 1;
            prev_finish = activities[i].finish;
        } else {
            selected[index++] = 0;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    struct Activity *activities = malloc(n * sizeof(struct Activity));
    int *selected = malloc(n * sizeof(int));

    // Input start and finish times of activities
    for (int i = 0; i < n; i++) {
        printf("Enter start time for activity %d: ", i + 1);
        scanf("%d", &activities[i].start);
        printf("Enter finish time for activity %d: ", i + 1);
        scanf("%d", &activities[i].finish);
    }

    activity_selection(activities, n, selected);

    printf("Solution Vector: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", selected[i]);
    }
    printf("\n");

    free(activities); 
    free(selected);  
    return 0;
}

