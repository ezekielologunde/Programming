#include <iostream>      // Includes the library for standard input/output (like 'cout')
#include "rectangleType.h" // Includes the header file containing the definition of the rectangleType class

using namespace std;     // Allows us to use standard names like 'cout' and 'endl'

int main()
{
    // --- Object Creation and Initialization ---
    
    // Creates rectangle1 using the constructor, setting length=10 and width=5
    rectangleType rectangle1(10, 5);
    
    // Creates rectangle2 using the constructor, setting length=8 and width=7
    rectangleType rectangle2(8, 7);
    
    // Creates rectangle3 and rectangle4 using the default constructor (likely setting length=0, width=0)
    rectangleType rectangle3;
    rectangleType rectangle4;

    // --- Output Operator Overloading (<<) ---
    
    // Prints rectangle1's dimensions and/or area using the overloaded << operator.
    cout << "rectangle1: " << rectangle1 << endl;

    // Prints rectangle2's dimensions and/or area.
    cout << "rectangle2: " << rectangle2  << endl;

    // --- Addition Operator Overloading (+) ---
    
    // Overloaded '+' operator: Defines how two rectangles are "added" (e.g., adding lengths and widths, or adding areas).
    rectangle3 = rectangle1 + rectangle2;

    // Prints the result of the addition (rectangle3).
    cout << "rectangle3: " << rectangle3 << endl;

    // --- Multiplication Operator Overloading (*) ---
    
    // Overloaded '*' operator: Defines how two rectangles are "multiplied" (e.g., multiplying areas).
    rectangle4 = rectangle1 * rectangle2;

    // Prints the result of the multiplication (rectangle4).
    cout << "rectangle4: " << rectangle4 << endl;

    // --- Relational Operator Overloading (>) ---
    
    // Overloaded '>' operator: Likely compares the rectangles based on their area.
    if (rectangle1 > rectangle2) {
        cout << "Area of rectangle1 is greater than the area "
             << "of rectangle2 ." << endl;
    } else {
        cout << "Area of rectangle1 is less than or equal to the area "
             << "of rectangle2 ." << endl;
    }

    // --- Post-Increment Operator Overloading (++) ---
    
    // Overloaded post-increment operator: Likely increments both the length and width of rectangle1 by one.
    rectangle1++;

    // Prints rectangle1 after the post-increment.
    cout << "After increment the length and width of "
         << "rectangle1 by one unit, \nrectangle1: "
         << rectangle1 << endl;

    // --- Pre-Increment Operator Overloading (++) ---
    
    // Overloaded pre-increment operator: Increments rectangle3 first, then assigns the new value to rectangle4.
    rectangle4 = ++rectangle3;

    // Prints the final dimensions of rectangle3 and rectangle4.
    cout << "New dimension of rectangle3: " << rectangle3 << endl;
    cout << "New dimension of rectangle4: " << rectangle4 << endl;

    return 0; // Signals successful execution
}
