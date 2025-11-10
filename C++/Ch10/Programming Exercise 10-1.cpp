//Main program
    
#include <iostream> // Include the standard input/output stream library (for cin, cout).
#include <string>   // Include the string library (for using the string data type).
#include "studentType.h" // Include the custom header file defining the studentType class/struct.

using namespace std; // Use the standard namespace to simplify code.

// Main function where program execution begins.
int main()
{
    // Create a studentType object named 'student' using the default constructor (assuming one exists).
    studentType student;
    // Create a studentType object named 'newStudent' using a constructor that takes parameters
    // (First Name, Last Name, Grade, Test Score 1, Test Score 2, GPA).
    studentType newStudent("Brain", "Johnson", '*', 85, 95, 3.89);

    // Call the member function 'print' to display the details of the 'student' object.
    student.print();
    // Print a separator line.
    cout << "***************" << endl << endl;

    // Call the member function 'print' to display the details of the 'newStudent' object.
    newStudent.print();
    // Print a separator line.
    cout << "***************" << endl << endl;

    // Indicate that the program finished successfully.
    return 0;
}
