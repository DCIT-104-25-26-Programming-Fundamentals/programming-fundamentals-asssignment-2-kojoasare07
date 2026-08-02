// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 2
// =============================================================================
//
// TASK: Student Grade System
//
// Write a C++ program that reads a student's score and outputs the
// corresponding letter grade based on the scale below.
//
// Grading Scale:
//   Score 80 – 100  →  Grade A
//   Score 70 – 79   →  Grade B
//   Score 60 – 69   →  Grade C
//   Score 50 – 59   →  Grade D
//   Score below 50  →  Grade F
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLES
// -----------------------------------------------------------------------------
//
//   Enter student score (0-100): 85
//   Grade: A
//
//   Enter student score (0-100): 73
//   Grade: B
//
//   Enter student score (0-100): 45
//   Grade: F
//
//   Enter student score (0-100): 110
//   Error: Score must be between 0 and 100.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST use functions (see scaffold below).
// - Validate the score inside getGrade(). If it is out of range, return '\0'
//   (null character) and let main() print the error message.
// - Use if / else if / else to determine the grade.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;


char calculateGrade(int marks)
{
    if (marks < 0 || marks > 100)
    {
        return '\0';
    }

    if (marks >= 80)
    {
        return 'A';
    }
    else if (marks >= 70)
    {
        return 'B';
    }
    else if (marks >= 60)
    {
        return 'C';
    }
    else if (marks >= 50)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}

int main()
{
    int studentMark;

    cout << "Input student's mark (0-100): ";
    cin >> studentMark;

    char result = calculateGrade(studentMark);

    if (result == '\0')
    {
        cout << "Invalid mark entered. Please enter a value from 0 to 100." << endl;
    }
    else
    {
        cout << "Student grade is: " << result << endl;
    }

    return 0;
}
