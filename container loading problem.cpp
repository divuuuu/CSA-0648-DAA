#include <stdio.h>
#define MAX_CONTAINERS 10
#define MAX_ITEMS 10
int main() {
    int num_containers;
    printf("Enter the number of containers: ");
    scanf("%d", &num_containers);
    int num_items; 
    printf("Enter the number of items: ");
    scanf("%d", &num_items);
    int weights[MAX_ITEMS]; 
    printf("Enter the weights of items:\n");
    for (int i = 0; i < num_items; i++) {
        scanf("%d", &weights[i]);
    }
    int capacities[MAX_CONTAINERS]; 
    printf("Enter the capacities of containers:\n");
    for (int i = 0; i < num_containers; i++) {
        scanf("%d", &capacities[i]);
    }
    int x[MAX_CONTAINERS][MAX_ITEMS]; 
    for (int i = 0; i < num_containers; i++) {
        for (int j = 0; j < num_items; j++) {
            x[i][j] = 0; 
        }
    }
    int total_weight = 0; 
    int i = 0;
    int j = 0; 
    while (i < num_containers && j < num_items) {
        if (weights[j] <= capacities[i]) {
            x[i][j] = 1;
            total_weight += weights[j];
            capacities[i] -= weights[j];
            j++; 
        } else {
            i++; 
        }
    }
    printf("Assignment of items to containers:\n");
    for (int i = 0; i < num_containers; i++) {
        for (int j = 0; j < num_items; j++) {
            printf("%d ", x[i][j]);
        }
        printf("\n");
    }

    printf("Total weight of items assigned to containers: %d\n", total_weight);

    return 0;
}
