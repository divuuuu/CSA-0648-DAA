#include <stdio.h>
#include <limits.h>
#include <float.h>
int main() {
	printf("Ravi,192210455\n");
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);
    float keys[n];
    printf("Enter the keys (float or integer): ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &keys[i]);
    }
    float freq[n];
    printf("Enter the frequencies of the keys (float or integer): ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &freq[i]);
    }
    float sum_freq[n];
    sum_freq[0] = freq[0];
    for (int i = 1; i < n; i++) {
        sum_freq[i] = sum_freq[i-1] + freq[i];
    }
    float cost[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i][j] = FLT_MAX;
        }
    }
    for (int L = 1; L <= n; L++) {
        for (int i = 0; i < n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = FLT_MAX;
            for (int r = i; r <= j; r++) {
                float c = (r == i)? 0 : cost[i][r-1];
                c += (r == j)? 0 : cost[r+1][j];
                c += (i == 0)? sum_freq[j] : sum_freq[j] - sum_freq[i-1];
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }
    printf("Minimum cost of OBST: %f\n", cost[0][n-1]);
    return 0;
}
