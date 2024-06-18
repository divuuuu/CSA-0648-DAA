#include <stdio.h>
#define MAX_ITEMS 10
#define MAX_WEIGHT 100
int main() {
    int n; 
    printf("Enter the number of items: ");
    scanf("%d", &n);
    if (n > MAX_ITEMS) {
        printf("Maximum number of items exceeded. Please try again.\n");
        return 1;
    }
    int weights[n];
    int values[n]; 
    printf("Enter the weights and values of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weights[i], &values[i]);
    }
    int W; 
    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &W);
    if (W > MAX_WEIGHT) {
        printf("Maximum weight capacity exceeded. Please try again.\n");
        return 1;
    }
    int dp[n+1][W+1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (weights[i-1] <= j) {
                dp[i][j] = values[i-1] + dp[i-1][j-weights[i-1]];
                if (dp[i-1][j] > dp[i][j]) {
                    dp[i][j] = dp[i-1][j];
                }
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    printf("Optimal cost: %d\n", dp[n][W]);
    return 0;
}
