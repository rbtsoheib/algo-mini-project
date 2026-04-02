#include <stdio.h>

// Procedure: input matrix
void input(int rows, int columns, int A[rows][columns]) {
    printf("Enter the %d x %d matrix row by row:\n", rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            scanf("%d", &A[i][j]);
        }
    }
}

// Procedure: display matrix
void display(int rows, int columns, int A[rows][columns]) {
    printf("The matrix elements are:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d  ", A[i][j]);
        }
        printf("\n");
    }
}

// Function: sum of all elements
int sum(int rows, int columns, int A[rows][columns]) {
    int s = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            s += A[i][j];
        }
    }
    return s;
}

// Procedure: transpose A into B
// A is rows × columns, B must be columns × rows
void matrixtranspose(int rows, int columns,
                     int A[rows][columns],
                     int B[columns][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            B[j][i] = A[i][j];
        }
    }
}

// Procedure: display transpose matrix
void transposedisplay(int rowsT, int columnsT, int T[rowsT][columnsT]) {
    printf("The transpose matrix is:\n");
    for (int i = 0; i < rowsT; i++) {
        for (int j = 0; j < columnsT; j++) {
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N, M;
    printf("Enter the number of rows: ");
    scanf("%d", &N);
    printf("Enter the number of columns: ");
    scanf("%d", &M);

    int matrix[N][M];          // original N × M
    int transpose[M][N];       // transpose will be M × N

    input(N, M, matrix);
    display(N, M, matrix);

    int s = sum(N, M, matrix);
    printf("The sum of the elements is %d\n", s);

    matrixtranspose(N, M, matrix, transpose);
    transposedisplay(M, N, transpose);   // M rows, N columns

    return 0;
}