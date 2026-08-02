// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

def addition(x, y):
    return x + y


def subtraction(x, y):
    return x - y


def multiplication(x, y):
    return x * y


def division(x, y):
    if y == 0:
        return None
    return round(x / y, 2)


def remainder(x, y):
    if y == 0:
        return None
    return x % y


def power(x, y):
    return x ** y


def convert_number(value):
    if isinstance(value, float) and value.is_integer():
        return str(int(value))
    return str(value)


def show_options():
    print('============================')
    print('       CALCULATOR APP')
    print('============================')
    print('1. Add')
    print('2. Subtract')
    print('3. Multiply')
    print('4. Divide')
    print('5. Find Remainder')
    print('6. Raise to Power')
    print('7. Exit')


def calculator():
    choices = {
        '1': ('+', addition),
        '2': ('-', subtraction),
        '3': ('*', multiplication),
        '4': ('/', division),
        '5': ('%', remainder),
        '6': ('**', power)
    }

    while True:
        show_options()

        option = input('Choose an option (1-7): ')

        if option == '7':
            print('Calculator closed.')
            break

        if option not in choices:
            print('Invalid selection. Choose a value between 1 and 7.')
            print()
            continue

        sign, calculation = choices[option]

        first = float(input('Enter the first value: '))
        second = float(input('Enter the second value: '))

        answer = calculation(first, second)

        if answer is None:
            print('Error: Division by zero is not allowed.')
        else:
            print(
                f'Answer: {convert_number(first)} {sign} '
                f'{convert_number(second)} = {convert_number(answer)}'
            )

        print()
