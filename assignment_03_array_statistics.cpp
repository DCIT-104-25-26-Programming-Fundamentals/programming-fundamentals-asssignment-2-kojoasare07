// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;


int calculateTotal(int values[], int size)
{
    int total = 0;

    for (int i = 0; i < size; i++)
    {
        total += values[i];
    }

    return total;
}

double calculateMean(int values[], int size)
{
    return (double)calculateTotal(values, size) / size;
}

int findLargest(int values[], int size)
{
    int largest = values[0];

    for (int i = 1; i < size; i++)
    {
        if (values[i] > largest)
        {
            largest = values[i];
        }
    }

    return largest;
}

int findSmallest(int values[], int size)
{
    int smallest = values[0];

    for (int i = 1; i < size; i++)
    {
        if (values[i] < smallest)
        {
            smallest = values[i];
        }
    }

    return smallest;
}

int main()
{
    int amount;

    cout << "Enter the number of values: ";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid input. Number of values must be greater than zero." << endl;
        return 0;
    }

    int values[amount];

    for (int i = 0; i < amount; i++)
    {
        cout << "Enter value " << i + 1 << ": ";
        cin >> values[i];
    }

    cout << endl;
    cout << "Calculation Results:" << endl;
    cout << "Total:    " << calculateTotal(values, amount) << endl;
    cout << "Mean:     " << calculateMean(values, amount) << endl;
    cout << "Largest:  " << findLargest(values, amount) << endl;
    cout << "Smallest: " << findSmallest(values, amount) << endl;

    return 0;
}
