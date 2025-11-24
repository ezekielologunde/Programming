#include <iostream>      // Needed for standard input/output (like 'cin' and 'cout')
#include <iomanip>       // Needed for output formatting (like 'setprecision')
#include <string>        // Needed for using the string data type (for the input error message)
#include "divisionByZero.h" // Includes the custom exception class for handling division by zero

using namespace std;

int main()
{
    int num1, num2;      // Variables to store the two numbers
    char opr;            // Variable to store the arithmetic operator
    bool done = false;   // Flag to control the inner loop for division

    // String used as the exception message for non-numeric input
    string str = "Invalid input. You must enter numbers.";

    // Set output formatting to show two decimal places
    cout << fixed << showpoint << setprecision(2);

    // --- OUTER TRY BLOCK: Handles initial input and general stream errors ---
    try
    {
        // Get the two numbers
        cout << "Enter two numbers: ";
        cin >> num1 >> num2;
        cout << endl;

        // Check for non-numeric input (stream failure)
        if (!cin)
                // Throw a string exception if the input stream failed
                throw str;

        // Get the operator
        cout << "Enter operator: + (addition), - (subtraction),"
             << " * (multiplication), / (division): ";
        cin >> opr;
        cout << endl;

        cout << num1 << " " << opr << " " << num2 << " = ";

        // --- Perform the Calculation ---
        switch (opr)
        {
        case '+':
            cout << num1 + num2 << endl;
            break;
        case '-':
            cout << num1 - num2 << endl;
            break;
        case '*':
            cout << num1 * num2 << endl;
            break;
            
        case '/':
            // --- INNER LOOP/TRY BLOCK: Specifically handles division by zero ---
            do
            {
                try
                {
                    // Check if the divisor (num2) is zero
                    if (num2 == 0)
                        // Throw the custom exception object
                        throw divisionByZero();

                    // If division is safe, perform the calculation
                    cout << num1 / num2 << endl;
                    done = true; // Mark as successful to exit the loop
                }
                // Catch the custom divisionByZero exception
                catch (divisionByZero divByZeroObj)
                {
                    // Print the error message from the exception object (likely "Division by zero!")
                    cout << divByZeroObj.what() << endl; 
                    
                    // Clear the input stream's error state and flush the buffer
                    cin.clear();
                    cin.ignore(100, '\n'); 
                    
                    // Prompt the user for a new, valid divisor
                    cout << "Enter the divisor: ";
                    cin >> num2;
                    cout << endl;

                    // Re-print the equation with the new divisor
                    cout << num1 << " " << opr << " " << num2 << " = ";
                }
            }
            while (!done); // Keep looping until the division is successful (done = true)

            break; // End of the '/' case

        default:
            cout << "Illegal operation" << endl;
        }
    }
    // --- OUTER CATCH BLOCK: Handles the string exception (non-numeric input) ---
    catch (string messageStr)
    {
        cout << messageStr << endl;
        cout << "Program terminates!!" << endl; // Terminate if initial input failed
    }

    return 0; // Signals successful execution
}
