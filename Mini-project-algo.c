#include <stdio.h> 

#define MAX_SIZE    100   // maximum elements for 1D array
#define MAX_ROWS     10   // maximum rows for matrix
#define MAX_COLS     10   // maximum columns for matrix

// 1D Array Procedures & Functions

// Procedure: fill array with user input
void inputArray(int arr[], int *n) {
    do {
        printf("Number of elements (1..%d): ", MAX_SIZE);
        scanf("%d", n);
        if (*n < 1 || *n > MAX_SIZE)
            printf("Invalid size. Please try again.\n");
    } while (*n < 1 || *n > MAX_SIZE);

    printf("Enter %d integers:\n", *n);
    for (int i = 0; i < *n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
}

// Procedure: display the array
void displayArray(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty. Please enter data first.\n");
        return;
    }
    printf("Array elements: [");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

// Function: sum of all elements
int sumArray(int arr[], int n) {
    int s = 0;
    for (int i = 0; i < n; i++)
        s += arr[i];
    return s;
}

// Function: average (as double)
double averageArray(int arr[], int n) {
    if (n == 0) return 0.0;
    return (double)sumArray(arr, n) / n;
}

// Function: maximum element
int maxArray(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}

// Function: minimum element
int minArray(int arr[], int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < min) min = arr[i];
    return min;
}

// 2D Array (Matrix) Procedures & Functions

// Procedure: fill matrix with user input
void inputMatrix(int mat[][MAX_COLS], int *rows, int *cols) {
    do {
        printf("Number of rows (1..%d): ", MAX_ROWS);
        scanf("%d", rows);
        printf("Number of columns (1..%d): ", MAX_COLS);
        scanf("%d", cols);
        if (*rows < 1 || *rows > MAX_ROWS || *cols < 1 || *cols > MAX_COLS)
            printf("Invalid dimensions. Please try again.\n");
    } while (*rows < 1 || *rows > MAX_ROWS || *cols < 1 || *cols > MAX_COLS);

    printf("Enter the %d x %d matrix row by row:\n", *rows, *cols);
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            printf("mat[%d][%d] = ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

// Procedure: display the matrix
void displayMatrix(int mat[][MAX_COLS], int rows, int cols) {
    if (rows == 0 || cols == 0) {
        printf("Matrix is empty. Please enter data first.\n");
        return;
    }
    printf("Matrix (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Function: sum of all matrix elements
int sumMatrix(int mat[][MAX_COLS], int rows, int cols) {
    int s = 0;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            s += mat[i][j];
    return s;
}

// Function: average of matrix elements
double averageMatrix(int mat[][MAX_COLS], int rows, int cols) {
    if (rows == 0 || cols == 0) return 0.0;
    int total = rows * cols;
    return (double)sumMatrix(mat, rows, cols) / total;
}

// Function: maximum element in matrix
int maxMatrix(int mat[][MAX_COLS], int rows, int cols) {
    int max = mat[0][0];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (mat[i][j] > max) max = mat[i][j];
    return max;
}

// Function: minimum element in matrix
int minMatrix(int mat[][MAX_COLS], int rows, int cols) {
    int min = mat[0][0];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (mat[i][j] < min) min = mat[i][j];
    return min;
}

/* ========== MENU HANDLING ========== */

// Submenu for 1D array operations
void menu1D() {
    int arr[MAX_SIZE];
    int n = 0;          // current size (0 = empty)
    int choice;

    do {
        printf("\n===== 1D ARRAY MENU =====\n");
        printf("1. Enter array\n");
        printf("2. Display array\n");
        printf("3. Sum of elements\n");
        printf("4. Average of elements\n");
        printf("5. Minimum & Maximum\n");
        printf("6. Return to main menu\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputArray(arr, &n);
                break;
            case 2:
                displayArray(arr, n);
                break;
            case 3:
                if (n == 0)
                    printf("Array is empty. Enter data first (option 1).\n");
                else
                    printf("Sum = %d\n", sumArray(arr, n));
                break;
            case 4:
                if (n == 0)
                    printf("Array is empty. Enter data first (option 1).\n");
                else
                    printf("Average = %.2f\n", averageArray(arr, n));
                break;
            case 5:
                if (n == 0)
                    printf("Array is empty. Enter data first (option 1).\n");
                else
                    printf("Minimum = %d, Maximum = %d\n",
                           minArray(arr, n), maxArray(arr, n));
                break;
            case 6:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}

// Submenu for 2D matrix operations
void menu2D() {
    int mat[MAX_ROWS][MAX_COLS];
    int rows = 0, cols = 0;
    int choice;

    do {
        printf("\n===== 2D MATRIX MENU =====\n");
        printf("1. Enter matrix\n");
        printf("2. Display matrix\n");
        printf("3. Sum of all elements\n");
        printf("4. Average of all elements\n");
        printf("5. Minimum & Maximum\n");
        printf("6. Return to main menu\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputMatrix(mat, &rows, &cols);
                break;
            case 2:
                displayMatrix(mat, rows, cols);
                break;
            case 3:
                if (rows == 0 || cols == 0)
                    printf("Matrix is empty. Enter data first (option 1).\n");
                else
                    printf("Sum = %d\n", sumMatrix(mat, rows, cols));
                break;
            case 4:
                if (rows == 0 || cols == 0)
                    printf("Matrix is empty. Enter data first (option 1).\n");
                else
                    printf("Average = %.2f\n", averageMatrix(mat, rows, cols));
                break;
            case 5:
                if (rows == 0 || cols == 0)
                    printf("Matrix is empty. Enter data first (option 1).\n");
                else
                    printf("Minimum = %d, Maximum = %d\n",
                           minMatrix(mat, rows, cols), maxMatrix(mat, rows, cols));
                break;
            case 6:
                printf("Returning to main menu...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
}

// Main menu
int main() {
    int mainChoice;

    do {
        printf("\n========== MAIN MENU ==========\n");
        printf("1. Work with 1D array\n");
        printf("2. Work with 2D matrix\n");
        printf("0. Exit program\n");
        printf("Your choice: ");
        scanf("%d", &mainChoice);

        switch (mainChoice) {
            case 1:
                menu1D();
                break;
            case 2:
                menu2D();
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter 0, 1 or 2.\n");
        }
    } while (mainChoice != 0);

    return 0;
}