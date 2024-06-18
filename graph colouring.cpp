#include <stdio.h>
int n, k;
int adj[10][10];
int color[10];
int isSafe(int v, int c) {
    for (int i = 0; i < n; i++)
        if (adj[v][i] && color[i] == c)
            return 0;
    return 1;
}
int graphColoringUtil(int m) {
    if (m >= n)
        return 1;
    for (int c = 1; c <= k; c++) {
        if (isSafe(m, c)) {
            color[m] = c;
            if (graphColoringUtil(m + 1))
                return 1;
            color[m] = 0;
        }
    }
    return 0;
}
int graphColoring() {
    int m = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (adj[i][j])
                m++;
    if (m < k)
        return 0;
    return graphColoringUtil(0);
}
int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the maximum number of colors: ");
    scanf("%d", &k);
    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    if (graphColoring())
        printf("The graph can be colored with %d colors\n", k);
    else
        printf("The graph cannot be colored with %d colors\n", k);

    return 0;
}
