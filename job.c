#include <stdio.h>
#include <stdlib.h>


struct Job {
    int id;       
    int deadline; 
    int profit;   
};


int compare(const void *a, const void *b) {
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}


void job_sequence(struct Job jobs[], int n, int selected[]) {

    qsort(jobs, n, sizeof(struct Job), compare);


    int slots[n];
    for (int i = 0; i < n; i++) {
        slots[i] = 0;
    }


    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slots[j] == 0) {
                slots[j] = jobs[i].id;
                selected[i] = 1; 
                break;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    struct Job *jobs = malloc(n * sizeof(struct Job));
    int *selected = malloc(n * sizeof(int));


    for (int i = 0; i < n; i++) {
        printf("Enter job ID for job %d: ", i + 1);
        scanf("%d", &jobs[i].id);
        printf("Enter deadline for job %d: ", i + 1);
        scanf("%d", &jobs[i].deadline);
        printf("Enter profit for job %d: ", i + 1);
        scanf("%d", &jobs[i].profit);
    }

    job_sequence(jobs, n, selected);

    printf("Solution Vector: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", selected[i]);
    }
    printf("\n");

    free(jobs); 
    free(selected); 
    return 0;
}

