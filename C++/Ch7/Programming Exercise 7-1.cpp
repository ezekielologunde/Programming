#include <iostream> // Includes the library for input and output operations (like 'cin' and 'cout')

using namespace std; // Allows us to use standard names like 'cout' and 'endl'

// --- Defines a new data type called 'enum' (enumeration) ---
// This lets us use descriptive words instead of simple integers (0, 1, 2, 3) 
enum triangleType{scalene, isosceles, equilateral, noTriangle};

// Function prototype: Declares a function that determines the triangle type
// It returns a value of the 'triangleType' enumeration.
triangleType triangleShape(double side1, double side2, double side3);

// Function prototype: Declares a function that prints the name of the triangle type
void printShape(triangleType triangle);

int main()
{
    // Variables to store the lengths of the three sides, using 'double' for precision
    double lenSide1, lenSide2, lenSide3;

    // Prompts the user to enter the side lengths
    cout << "Enter the lengths of the three sides of a triangle."
         << endl;
         
    // Reads the three lengths from the user
    cin >> lenSide1 >> lenSide2 >> lenSide3;
    cout << endl;

    // Prints a message and then calls the two main functions:
    // 1. triangleShape determines the type.
    // 2. printShape displays the result.
    cout << "The shape of the triangle is: ";
    printShape(triangleShape(lenSide1, lenSide2, lenSide3));
    cout << endl;

    // Signals that the program executed successfully
    return 0;
}

// --- Function to determine the shape of the triangle ---
// Takes the three side lengths as input
triangleType triangleShape(double side1, double side2, double side3)
{
    // Check 1: If all three sides are equal, it's an equilateral triangle.
    if (side1 == side2 && side2 == side3)
        return equilateral;
        
    // Check 2: The Triangle Inequality Theorem must be true for a triangle to exist.
    // (The sum of the lengths of any two sides must be greater than the length of the third side.)
    else if ((side1 +
