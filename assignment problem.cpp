#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 4
void findMinCost(int cost[N][N], int path[], int n);
void recurse(int level, int current_cost, int visited[], int current_path[], int cost[N][N], int n, int *min_cost, int min_path[]);
void findMinCost(int cost[N][N], int path[], int n) {
    int min_cost = INT_MAX;
    int min_path[N];
    for (int i = 0; i < n; i++) {
        min_path[i] = -1;
}
    int visited[N] = {0};
    int current_path[N];
    recurse(0, 0, visited, current_path, cost, n, &min_cost, min_path);
    printf("Minimum cost: %d\n", min_cost);
    printf("Assignment: ");
    for (int i = 0; i < n; i++) {
        printf("Job %d -> Worker %d, ", i + 1, min_path[i] + 1);
    }
    printf("\n");
}
void recurse(int level, int current_cost, int visited[], int current_path[], int cost[N][N], int n, int *min_cost, int min_path[]) {
    if (level == n) {
        if (current_cost < *min_cost) {
            *min_cost = current_cost;
            for (int i = 0; i < n; i++) {
                min_path[i] = current_path[i];
            }
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            current_path[level] = i;
            recurse(level + 1, current_cost + cost[level][i], visited, current_path, cost, n, min_cost, min_path);
            visited[i] = 0;
        }
    }
}
int main() {
    int cost[N][N] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };
    int path[N];
    findMinCost(cost, path, N);
    return 0;
}
