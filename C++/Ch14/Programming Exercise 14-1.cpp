#include <iostream> // Needed for standard input/output (like 'cin' and 'cout')
#include <string>   // Needed for using the string data type (used in the exception message)
#include <iomanip>  // Needed for formatting output (like 'setprecision')
  
using namespace std; 

// --- Global Constants ---
const double conversion = 2.54;   // Conversion factor: 1 inch = 2.54 cm
const int inchesInFoot = 12;      // Conversion factor: 1 foot = 12 inches

// Function prototype: Declares a function to safely get a length value from the user
double getLength();

int main ()
{
    double feet;           // Variable to store the length in feet
    double inches;         // Variable to store the length in inches
    double centimeters;    // Variable to store the converted length in centimeters       

    // Set output formatting to show two decimal places
    cout << fixed << showpoint << setprecision(2);

    // --- Input Phase ---
    cout << "Feet: ";
    // Calls the safe input function to get the value for feet
    feet = getLength();
    cout << endl;

    cout << "Inches: ";
    // Calls the safe input function to get the value for inches
    inches = getLength();
    cout << endl;

    // --- Calculation Phase ---
    // 1. Convert feet to total inches (inchesInFoot * feet)
    // 2. Add the remaining inches
    // 3. Convert total inches to centimeters (multiply by conversion factor)
    centimeters = (inchesInFoot * feet + inches ) * conversion;

    // --- Output Phase ---
    cout << "Centimeter: " << centimeters << endl;
    
    return 0; // Signals successful execution
}

// --- Function to safely read a nonnegative number from the user ---
double getLength()
{
    bool done = false; // Flag to control the do-while loop (true when valid input is received)
    double number = 0; // Variable to store the user input

    // String used as the error message for stream failure
    string str = 
         "The input stream is in the fail state.";   

    do // Start of the loop that repeats until valid input is received
    {
        try // Block where exceptions might occur
        {
            cout << "Enter a nonnegative number: ";     
            cin >> number;                           
            cout << endl;    

            // --- Exception 1: Logical Error (Negative Number) ---
            if (number < 0)
                throw -1; // Throws an integer exception if the number is negative
     
            // --- Exception 2: Stream Error (Non-numeric Input) ---
            if (!cin) // Checks if the stream failed (e.g., user entered "abc")
                throw str; // Throws the string exception if the input failed

            done = true; // If no exception was thrown, mark as complete
        }    
        catch (int) // Handles the integer exception (negative number)
        {
            cout << "A non positive number is entered" << endl;
            number = 0; // Resets the number to 0
        }
        catch (string messageStr) // Handles the string exception (stream failure)
        {
            cout << messageStr << endl << "Restoring the input stream."
                 << endl;
            cin.clear(); // Clears the fail state flags on the input stream
            // Ignores and discards up to 100 characters or until a newline is found
            cin.ignore(100, '\n');
        }
    } 
    while (!done); // Loop continues if 'done' is false (meaning an exception occurred)

    return number; // Returns the valid, nonnegative number
}
