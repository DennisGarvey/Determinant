#include <stdio.h>
#include "determinant.h"
void setSubmatrix(int rows, int cols, int matrix[][cols], int i, int j, int subMatrix[rows-1][cols-1]);

int determinant(int rows, int cols, int matrix[][cols])
{
    if(rows==cols)
    {
        if(rows == 2)
        {
            return matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
        }
        else
        {
            int det = 0;
            int row = 0;
            for(int col = 0; col<cols; col++)
            {
                int submatrix[rows-1][cols-1];
                setSubmatrix(rows, cols, matrix, row, col, submatrix);
                int submatrixDet = determinant(rows-1, cols-1, submatrix);
                det += ((row+col)%2==0?1:-1) * matrix[row][col] * submatrixDet;
            }
            return det;
        }

    }
    else
    {
        printf("Cannot find the determinant of a nonsquare matrix.");
        return 0;
    }
}
void setSubmatrix(int rows, int cols, int matrix[][cols], int i, int j, int subMatrix[rows-1][cols-1])
{
    for(int row = 0; row<rows-1; row++)
    {
        for(int col = 0; col<cols-1; col++)
        {
            subMatrix[row][col]=matrix[row<i?row:row+1][col<j?col:col+1];
        }
    }
}

void printMatrix(int rows, int cols, int matrix[][cols])
{
    for(int row = 0; row<rows; row++)
    {
        for(int col = 0; col<cols; col++)
        {
            printf("%d\t", matrix[row][col]);
        }
        printf("\n");
    }
}