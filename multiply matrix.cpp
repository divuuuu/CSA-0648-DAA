#include <stdio.h>


void multiplyMatrices(int firstMatrix[][10], int secondMatrix[][10], int result[][10], int rowFirst, int columnFirst, int rowSecond, int columnSecond) {
    
    for (int i = 0; i < rowFirst; ++i) {
        for (int j = 0; j < columnSecond; ++j) {
            result[i][j] = 0;
        }
    }

    
    for (int i = 0; i < rowFirst; ++i) {
        for (int j = 0; j < columnSecond; ++j) {
            for (int k = 0; k < columnFirst; ++k) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}


void display(int matrix[][10], int row, int column) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            printf("%d  ", matrix[i][j]);
            if (j == column - 1)
                printf("\n");
        }
    }
}


int main() {
    int firstMatrix[10][10], secondMatrix[10][10], result[10][10];
    int rowFirst, columnFirst, rowSecond, columnSecond;

    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &rowFirst, &columnFirst);

    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &rowSecond, &columnSecond);

    
    while (columnFirst != rowSecond) {
        printf("Error! Column of the first matrix is not equal to row of the second matrix.\n");

        printf("Enter rows and columns for the first matrix: ");
        scanf("%d %d", &rowFirst, &columnFirst);

        printf("Enter rows and columns for the second matrix: ");
        scanf("%d %d", &rowSecond, &columnSecond);
    }

   
    printf("\nEnter elements of the first matrix:\n");
    for (int i = 0; i < rowFirst; ++i) {
        for (int j = 0; j < columnFirst; ++j) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &firstMatrix[i][j]);
        }
    }

    
    printf("\nEnter elements of the second matrix:\n");
    for (int i = 0; i < rowSecond; ++i) {
        for (int j = 0; j < columnSecond; ++j) {
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &secondMatrix[i][j]);
        }
    }

    
    multiplyMatrices(firstMatrix, secondMatrix, result, rowFirst, columnFirst, rowSecond, columnSecond);

   
    printf("\nOutput Matrix:\n");
    display(result, rowFirst, columnSecond);

    return 0;
}

