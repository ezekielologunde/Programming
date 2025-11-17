//The user program that uses the class clockType
 
#include <iostream> // Include the standard input/output stream library (for cin, cout).
#include <iomanip>  // Include the I/O manipulator library (for formatting, like setprecision).
#include "temporary.h" // Include the custom header file defining the temporary class.
 
using namespace std; // Use the standard namespace.

// Main function where program execution begins.
int main()
{
    temporary myObject; // Create a 'temporary' object using the default constructor.
    // Create a 'temporary' object using a parameterized constructor: ("rectangle", dimension 1, dimension 2).
    temporary newObject("rectangle", 8.5, 3.9);

    string objectName; // Variable to store the user-input name of the object (e.g., "rectangle").
    double num1, num2; // Variables to store the two numerical dimensions input by the user.

    // Set output formatting: fixed decimal, show point, 2 decimal places (for dimensions/results).
    cout << fixed << showpoint << setprecision(2);

    // Print the initial state of the objects created by the constructors.
    myObject.print();
    newObject.print();

    // Prompt the user to enter the type of object.
    cout << "Enter object name (rectangle, circle, sphere, or cylinder: ";
    // Read the object name from the user.
    cin >> objectName;
    cout << endl;

    // Provide detailed instructions for the user on how to enter the two required dimensions.
    cout << "Enter object's dimensions: " << endl
         << "      rectangle (length and width) " << endl
         << "      circle (radius and 0) " << endl
         << "      sphere (radius and 0) " << endl
         << "      cylinder (base radius and height) " << endl;

    // Read the two numerical dimensions from the user.
    cin >> num1 >> num2;
    cout << endl;

    // Use the setter function 'set' to update 'myObject' with the user's input.
    myObject.set(objectName, num1, num2);

    // Announce the subsequent output.
    cout << endl << "After setting myObject: " << endl;
    // Print the updated state of 'myObject' using the new user-defined values.
    myObject.print();
    cout << endl;

    // Indicate that the program finished successfully.
    return 0;
}//end main
