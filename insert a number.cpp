#include <stdio.h>
#define MAX_SIZE 10
int main() {
    int list[MAX_SIZE]; 
    int size = 0; 
    for (int i = 0; i < MAX_SIZE; i++) {
        list[i] = 0;
    }
    printf("Enter numbers (enter -1 to stop): ");
    int num;
    while (1) {
        scanf("%d", &num);
        if (num == -1) break;
        if (size < MAX_SIZE) {
            list[size] = num;
            size++;
        } else {
            printf("List is full. Cannot insert more numbers.\n");
            break;
        }
    }
    int new_num;
    printf("Enter a number to insert: ");
    scanf("%d", &new_num);
    int pos = 0;
    while (pos < size && list[pos] < new_num) {
        pos++;
    }
    for (int i = size; i > pos; i--) {
        list[i] = list[i - 1];
    }
    list[pos] = new_num;
    size++;
    printf("Updated list: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
    return 0;
}
