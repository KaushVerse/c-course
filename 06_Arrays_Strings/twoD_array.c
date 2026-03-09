#include <stdio.h>

int main() {

    // 2D array declaration and initialization
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Accessing specific element
    printf("Element at matrix[1][2]: %d\n\n", matrix[1][2]); // 6

    // Printing the 2D array using nested loops
    printf("Matrix elements:\n");

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}