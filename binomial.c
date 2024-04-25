#include <stdio.h>
#include <time.h>

unsigned long long binomialCoefficient(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    else
        return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

int main() {
    int n, k;
    printf("Enter the values of n and k for binomial coefficient (n choose k): ");
    scanf("%d %d", &n, &k);

    clock_t start = clock(); 

    unsigned long long result = binomialCoefficient(n, k);

    clock_t end = clock(); 

    printf("Binomial Coefficient (%d choose %d) = %d\n", n, k, result);

    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("CPU Time used: %f seconds\n", cpu_time_used);

    return 0;
}

