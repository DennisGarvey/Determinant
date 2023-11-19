#include <stdio.h>
#include "determinant.h"

int main()
{
    printf("Enter Row Count: ");
    int rows;
    scanf("%d", &rows);
    int cols = rows;
    int input[rows][rows];
    printf("Enter matrix: \n");
    for(int row = 0; row<rows; row++)
    {
        for(int col = 0; col<cols; col++)
        {
            scanf("%d", &input[row][col]);
        }
    }

    printf("\n Matrix:\n");
    printMatrix(rows, cols, input);
    printf("Determinant: %d\n", determinant(rows, cols, input));

}

