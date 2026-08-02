// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;


struct StudentInfo
{
    string studentName;
    int studentNumber;
    vector<double> marks;
};

double findAverage(const vector<double> &marks)
{
    double sum = 0;

    for (int i = 0; i < (int)marks.size(); i++)
    {
        sum += marks[i];
    }

    return sum / marks.size();
}

void registerStudent(vector<StudentInfo> &records)
{
    StudentInfo newStudent;

    cin.ignore();

    cout << "Enter student name: ";
    getline(cin, newStudent.studentName);

    cout << "Enter student number: ";
    cin >> newStudent.studentNumber;

    int totalMarks;
    cout << "Enter number of marks: ";
    cin >> totalMarks;

    for (int i = 0; i < totalMarks; i++)
    {
        double scoreValue;

        cout << "Input mark " << i + 1 << ": ";
        cin >> scoreValue;

        newStudent.marks.push_back(scoreValue);
    }

    records.push_back(newStudent);

    cout << newStudent.studentName << " has been registered successfully." << endl;
}

void showStudents(const vector<StudentInfo> &records)
{
    if (records.empty())
    {
        cout << "Student list is currently empty." << endl;
        return;
    }

    cout << fixed << setprecision(2);

    for (int i = 0; i < (int)records.size(); i++)
    {
        const StudentInfo &student = records[i];

        cout << "Student Name: " << student.studentName << endl;
        cout << "Student Number: " << student.studentNumber << endl;

        cout << "Marks: ";

        for (int j = 0; j < (int)student.marks.size(); j++)
        {
            cout << student.marks[j];

            if (j != (int)student.marks.size() - 1)
            {
                cout << ", ";
            }
        }

        cout << endl;
        cout << "Average Mark: " << findAverage(student.marks) << endl;
        cout << "============================" << endl;
    }
}

void searchAverage(const vector<StudentInfo> &records)
{
    int searchId;

    cout << "Enter student number to search: ";
    cin >> searchId;

    for (int i = 0; i < (int)records.size(); i++)
    {
        if (records[i].studentNumber == searchId)
        {
            cout << fixed << setprecision(2);

            cout << records[i].studentName 
                 << "'s average mark is: "
                 << findAverage(records[i].marks) << endl;

            return;
        }
    }

    cout << "Student record not found for number "
         << searchId << "." << endl;
}

void displayMenu()
{
    cout << "================================" << endl;
    cout << "      STUDENT MANAGEMENT MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Register Student" << endl;
    cout << "2. View Students" << endl;
    cout << "3. Find Student Average" << endl;
    cout << "4. Exit Program" << endl;
    cout << "Choose an option (1-4): ";
}

int main()
{
    vector<StudentInfo> records;

    int choice;
    bool running = true;

    while (running)
    {
        displayMenu();

        cin >> choice;
        cout << endl;

        switch(choice)
        {
            case 1:
                registerStudent(records);
                break;

            case 2:
                showStudents(records);
                break;

            case 3:
                searchAverage(records);
                break;

            case 4:
                cout << "Program terminated." << endl;
                running = false;
                break;

            default:
                cout << "Invalid option. Select between 1 and 4." << endl;
        }

        cout << endl;
    }

    return 0;
}
