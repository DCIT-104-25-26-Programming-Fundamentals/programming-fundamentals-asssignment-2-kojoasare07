// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================


#include <iostream>
#include <iomanip>
using namespace std;

void printTable(int baseNum)
{
    cout << "Multiplication Table for " << baseNum << ":" << endl;
    for (int factor = 1; factor <= 12; factor++)
    {
        cout << baseNum << " x " << setw(2) << factor << " = " << (baseNum * factor) << endl;
    }
}

void printTablesUpTo(int maxNum)
{
    for (int row = 1; row <= maxNum; row++)
    {
        printTable(row);
        if (row < maxNum)
        {
            cout << "---------------------------" << endl;
        }
    }
}

int main()
{
    int option;

    cout << "Multiplication Table Generator" << endl;
    cout << "1. Single Table" << endl;
    cout << "2. Tables from 1 to N" << endl;
    cout << "Enter your choice: ";
    cin >> option;
    cout << endl;

    if (option == 1)
    {
        int baseNum;
        cout << "Enter a number: ";
        cin >> baseNum;
        cout << endl;
        printTable(baseNum);
    }
    else if (option == 2)
    {
        int maxNum;
        cout << "Enter N: ";
        cin >> maxNum;
        cout << endl;

        if (maxNum <= 0)
        {
            cout << "Error: N must be a positive integer." << endl;
            return 0;
        }

        printTablesUpTo(maxNum);
    }
    else
    {
        cout << "Invalid choice." << endl;
    }

    return 0;
}
