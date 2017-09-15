/*You are given a 2D matrix, a, of dimension MxN and a positive integer R. You have to rotate the matrix R times and print the resultant matrix. 
Rotation should be in anti-clockwise direction.
Rotation of a 4x5 matrix is represented by the following figure. Note that in one rotation, you have to shift elements by one step only.
matrix-rotation
It is guaranteed that the minimum of M and N will be even.
Input Format 
First line contains three space separated integers, M, N and R, where M is the number of rows,
N is number of columns in matrix, and R is the number of times the matrix has to be rotated. 
Then M lines follow, where each line contains N space separated positive integers. These M lines represent the matrix.
Constraints 
2 <= M, N <= 300 
1 <= R <= 109 
min(M, N) % 2 == 0 
1 <= aij <= 108, where i ? [1..M] & j ? [1..N]
Output Format 
Print the rotated matrix.*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int rows,cols,rot;
    scanf("%d%d%d",&rows,&cols,&rot);
    int arr[rows][cols];
    int result[rows][cols];
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            scanf("%d", &arr[r][c]);
        }
    }

    rows--;
    cols--;
    for (int r = 0; r <= rows; r++) {
        for (int c = 0; c <= cols; c++) {
            int x = r < rows - r ? r : rows - r; //setting front approach row
            int y = c < cols - c ? c : cols - c;
            int min = x < y ? x : y; //approach minimum of row/column
            int maxRow = rows - min;  //get max row available
            int maxCol = cols - min;
            int parameter = (maxRow + maxCol) * 2 - min * 4; //set-up rotn parameter
            int row = r;
            int col = c;
            for (int a = 0; a < rot%parameter; a++) {
                if (col == min && row < maxRow) {
                    row++;
                }
                else if (row == maxRow && col < maxCol) {
                    col++;
                }
                else if (row > min && col == maxCol) {
                    row--;
                }
                else if (row == min && col > min) {
                    col--;
                }
            }
            result[row][col] = arr[r][c];
        }
    }


    for (int r = 0; r <= rows; r++) {
        for (int c = 0; c <= cols; c++) {
            printf("%d ", result[r][c]);
        }
        printf("\n");
    }
}