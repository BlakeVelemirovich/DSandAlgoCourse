#include <iostream>
using namespace std;

int sumMatrix(int matrix[][100], int row, int col, int n) {
    // Base case: when all rows and columns are traversed, n being the final index + 1
    if (row == n) {
        return 0;
    }
    // Move to the next row when the current row is fully traversed
    if (col == n) {
        return sumMatrix(matrix, row + 1, 0, n);
    }
    // Add the current element and move to the next column
    return matrix[row][col] + sumMatrix(matrix, row, col + 1, n);
}

int main() {
    int n;
    cout << "Enter the size of the matrix (n x n): ";
    cin >> n;

    int matrix[100][100]; 
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Sum up all of the elements.
    int totalSum = sumMatrix(matrix, 0, 0, n);
    cout << "Sum of all elements in the matrix: " << totalSum << endl;

    return 0;
}
