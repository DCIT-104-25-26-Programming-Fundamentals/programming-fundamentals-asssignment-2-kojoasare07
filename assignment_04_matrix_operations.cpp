// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


void inputMatrix(int data[10][10], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "Enter value at position [" << i << "][" << j << "]: ";
            cin >> data[i][j];
        }
    }
}

void displayMatrix(int data[10][10], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << setw(5) << data[i][j];
        }
        cout << endl;
    }
}

void findTranspose(int original[10][10], int rows, int columns, int result[10][10])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            result[j][i] = original[i][j];
        }
    }
}

void sumMatrices(int first[10][10], int second[10][10], int answer[10][10], int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            answer[i][j] = first[i][j] + second[i][j];
        }
    }
}

void productMatrices(int first[10][10], int second[10][10], int answer[10][10], int rowsFirst, int columnsFirst, int columnsSecond)
{
    for (int i = 0; i < rowsFirst; i++)
    {
        for (int j = 0; j < columnsSecond; j++)
        {
            answer[i][j] = 0;

            for (int k = 0; k < columnsFirst; k++)
            {
                answer[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

void transposeOperation()
{
    int matrix[10][10], result[10][10];
    int rows, columns;

    cout << "Enter rows of matrix: ";
    cin >> rows;

    cout << "Enter columns of matrix: ";
    cin >> columns;

    inputMatrix(matrix, rows, columns);
    findTranspose(matrix, rows, columns, result);

    cout << "\nGiven Matrix:" << endl;
    displayMatrix(matrix, rows, columns);

    cout << "\nTranspose Matrix:" << endl;
    displayMatrix(result, columns, rows);
}

void additionOperation()
{
    int firstMatrix[10][10], secondMatrix[10][10], result[10][10];
    int rows, columns;

    cout << "Enter rows of matrices: ";
    cin >> rows;

    cout << "Enter columns of matrices: ";
    cin >> columns;

    cout << "\nEnter first matrix values:" << endl;
    inputMatrix(firstMatrix, rows, columns);

    cout << "\nEnter second matrix values:" << endl;
    inputMatrix(secondMatrix, rows, columns);

    sumMatrices(firstMatrix, secondMatrix, result, rows, columns);

    cout << "\nFirst Matrix:" << endl;
    displayMatrix(firstMatrix, rows, columns);

    cout << "\nSecond Matrix:" << endl;
    displayMatrix(secondMatrix, rows, columns);

    cout << "\nAdded Matrix:" << endl;
    displayMatrix(result, rows, columns);
}

void multiplicationOperation()
{
    int matrixOne[10][10], matrixTwo[10][10], result[10][10];
    int rowOne, columnOne, columnTwo;

    cout << "Enter rows of first matrix: ";
    cin >> rowOne;

    cout << "Enter columns of first matrix: ";
    cin >> columnOne;

    cout << "\nEnter first matrix values:" << endl;
    inputMatrix(matrixOne, rowOne, columnOne);

    int rowTwo = columnOne;

    cout << "\nThe second matrix requires " << rowTwo << " rows." << endl;
    cout << "Enter columns of second matrix: ";
    cin >> columnTwo;

    cout << "\nEnter second matrix values:" << endl;
    inputMatrix(matrixTwo, rowTwo, columnTwo);

    productMatrices(matrixOne, matrixTwo, result, rowOne, columnOne, columnTwo);

    cout << "\nFirst Matrix:" << endl;
    displayMatrix(matrixOne, rowOne, columnOne);

    cout << "\nSecond Matrix:" << endl;
    displayMatrix(matrixTwo, rowTwo, columnTwo);

    cout << "\nResult of Multiplication:" << endl;
    displayMatrix(result, rowOne, columnTwo);
}

int main()
{
    int option;

    cout << "MATRIX CALCULATOR" << endl;
    cout << "1. Find Transpose" << endl;
    cout << "2. Add Matrices" << endl;
    cout << "3. Multiply Matrices" << endl;
    cout << "Select an option: ";
    cin >> option;

    cout << endl;

    switch(option)
    {
        case 1:
            transposeOperation();
            break;

        case 2:
            additionOperation();
            break;

        case 3:
            multiplicationOperation();
            break;

        default:
            cout << "Wrong option selected." << endl;
    }

    return 0;
}
