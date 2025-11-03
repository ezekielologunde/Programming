#include <iostream>

using namespace std; 

int main() 
{ 
    // Declare a double variable to store the user's input.
    double number; 

    // Prompt the user to enter a decimal number.
    cout << "Enter a decimal number: ";
    cin >> number;
    cout << endl;

    // Calculate and print the nearest integer.
    // The expression 'static_cast<int>(number + 0.5)' adds 0.5 to the number
    // and then truncates the decimal part, effectively rounding it to the nearest integer.
    cout << "The integer nearest to " << number << " = "
         << static_cast<int>(number + 0.5) << endl;

    // Return 0 to indicate successful program execution.
    return 0;
}
