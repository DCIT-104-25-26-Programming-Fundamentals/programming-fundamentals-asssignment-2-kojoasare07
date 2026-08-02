// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;


void createTask(vector<string> &tasks)
{
    cin.ignore();

    string description;

    cout << "Enter a new task: ";
    getline(cin, description);

    tasks.push_back(description);

    cout << "Added task: \"" << description << "\"" << endl;
}

void showTasks(const vector<string> &tasks)
{
    if (tasks.empty())
    {
        cout << "No tasks available." << endl;
        return;
    }

    cout << "Current Task List:" << endl;

    for (int i = 0; i < (int)tasks.size(); i++)
    {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

void removeTask(vector<string> &tasks)
{
    if (tasks.empty())
    {
        cout << "There are no tasks to remove." << endl;
        return;
    }

    showTasks(tasks);

    int choice;

    cout << "Select task number to remove: ";
    cin >> choice;

    if (choice < 1 || choice > (int)tasks.size())
    {
        cout << "Invalid task selection." << endl;
        return;
    }

    string removed = tasks[choice - 1];

    tasks.erase(tasks.begin() + choice - 1);

    cout << "Removed task: \"" << removed << "\"" << endl;
}

void displayMenu()
{
    cout << "============================" << endl;
    cout << "       TASK MANAGER" << endl;
    cout << "============================" << endl;
    cout << "1. Create Task" << endl;
    cout << "2. Display Tasks" << endl;
    cout << "3. Remove Task" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an option (1-4): ";
}

int main()
{
    vector<string> tasks;

    int selection;
    bool running = true;

    while (running)
    {
        displayMenu();

        cin >> selection;
        cout << endl;

        switch(selection)
        {
            case 1:
                createTask(tasks);
                break;

            case 2:
                showTasks(tasks);
                break;

            case 3:
                removeTask(tasks);
                break;

            case 4:
                cout << "Closing task manager..." << endl;
                running = false;
                break;

            default:
                cout << "Invalid option. Please select 1 to 4." << endl;
        }

        cout << endl;
    }

    return 0;
}
