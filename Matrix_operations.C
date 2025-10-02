#include <stdio.h>

#define SIZE 3

void addMatrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]) {
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            result[i][j] = a[i][j] + b[i][j];
}

void multiplyMatrix(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE]) {
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++) {
            result[i][j] = 0;
            for(int k=0;k<SIZE;k++)
                result[i][j] += a[i][k]*b[k][j];
        }
}

void transposeMatrix(int a[SIZE][SIZE], int result[SIZE][SIZE]) {
    for(int i=0;i<SIZE;i++)
        for(int j=0;j<SIZE;j++)
            result[j][i] = a[i][j];
}

void printMatrix(int m[SIZE][SIZE]) {
    for(int i=0;i<SIZE;i++) {
        for(int j=0;j<SIZE;j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}

int main() {
    int a[SIZE][SIZE] = {{1,2,3},{4,5,6},{7,8,9}};
    int b[SIZE][SIZE] = {{9,8,7},{6,5,4},{3,2,1}};
    int result[SIZE][SIZE];

    printf("Addition:\n");
    addMatrix(a,b,result);
    printMatrix(result);

    printf("\nMultiplication:\n");
    multiplyMatrix(a,b,result);
    printMatrix(result);

    printf("\nTranspose of A:\n");
    transposeMatrix(a,result);
    printMatrix(result);

    return 0;
}
