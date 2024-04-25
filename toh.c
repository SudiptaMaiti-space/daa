#include <stdio.h>
#include <time.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from_rod, to_rod);
        return; 
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from %c to %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    clock_t start = clock(); 

    towerOfHanoi(n, 'A', 'C', 'B');

    clock_t end = clock(); 

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("CPU Time used: %f seconds\n", cpu_time_used);

    return 0;
}

