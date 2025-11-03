#include <iostream> // Needed for input/output operations (like 'cout' and 'cin')
#include <iomanip>  // Included, but not used in the final version of the code
#include <math.h>   // Needed for mathematical functions (like 'floor') and the 'isspace' check
#include <cctype>   // Best practice to include for character checks like 'isspace' (often included by <math.h> or <iostream>)

using namespace std; // Allows us to use standard names like 'cout' and 'endl'
 
// Function prototype: Declares a function to check if a character is whitespace
bool isWhitespace(char ch);

// Function prototype: Declares a function to perform a specific numerical comparison
bool funcEx14(double x, double y, double z);

int main()
{
    char ch;           // Variable to store the single character input
    double first, second, third; // Variables to store the three numbers

    // --- Part 1: Character Check ---
    cout << "Enter a character: ";
    // cin.get(ch) reads the character, including spaces or the Enter key
    cin.get(ch);
    cout << endl;

    // Call the function and print the result
    if (isWhitespace(ch))
        cout << "The character you entered is a whitespace character." << endl;
    else
        cout << "The character you entered is not a whitespace character." << endl;

    // --- Part 2: Number Check ---
    cout << "Enter three numbers: ";
    cin >> first >> second >> third; // Reads the three numbers
    cout << endl;

    // Call the function and print the result
    if (funcEx14(first, second, third))
        cout << "The product of the first two numbers is equal"
             << " to the floor of the third number" << endl;
    else
        cout << "The product of the first two numbers is not equal" 
             << " to the floor of the third number" << endl;

    // Prints the values used for comparison to verify the result
    cout << first * second << ",  " << floor(third) << endl;

    return 0; // Signals successful execution
 }

// --- Function to check for whitespace ---
bool isWhitespace(char ch)
{
    // C++ standard library function (from <cctype> or <math.h>) that checks 
    // for space, tab, newline, etc.
    if (isspace(ch)) 
        return true;
    else
        return false;
}

// --- Function to compare product and floor value ---
// Compares the product of x and y against the whole number part (floor) of z.
bool funcEx14(double x, double y, double z)
{
    // The problem description implies that the product (x * y) should also be rounded down.
    // If the whole number part of the product is equal to the whole number part of the third number
    if (floor(x * y) == floor(z)) 
        return true;
    else
        return false;
}
