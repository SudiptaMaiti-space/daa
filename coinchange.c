#include <stdio.h>
#include <stdlib.h>

int coin_change(int coins[], int n, int amount, int selected[]) {
    int coin_count = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (coins[j] < coins[j + 1]) {
                int temp = coins[j];
                coins[j] = coins[j + 1];
                coins[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        selected[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            selected[i]++;
            amount -= coins[i];
            coin_count++;
        }
    }

    return coin_count;
}

int main() {
    int n, amount;
    printf("Enter the number of coin denominations: ");
    scanf("%d", &n);

    int *coins = malloc(n * sizeof(int));
    int *selected = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("Enter denomination for coin %d: ", i + 1);
        scanf("%d", &coins[i]);
    }

    printf("Enter the amount for which to make change: ");
    scanf("%d", &amount);

    int min_coins = coin_change(coins, n, amount, selected);

    printf("Minimum number of coins needed: %d\n", min_coins);
    printf("Solution Vector: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", selected[i] > 0 ? 1 : 0);
    }
    printf("\n");

    free(coins); 
    free(selected); 
    return 0;
}

