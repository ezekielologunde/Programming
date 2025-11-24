#include <iostream>  // Needed for input/output functions
#include <cassert>   // Needed for the 'assert' function (used for checking conditions)
 
#include "rectangleType.h" // Includes the class definition (the blueprint) for rectangleType
 
using namespace std;   // Allows us to use standard names like 'cout', 'endl'

// --- 1. SETTER METHOD ---
// Sets the length and width, ensuring they are not negative.
void rectangleType::setDimension(double l, double w)
{
    if (l >= 0)
        length = l;
    else
        length = 0; // Default to 0 if length is negative

    if (w >= 0)
        width = w;
    else
        width = 0; // Default to 0 if width is negative
}

// --- 2. GETTER METHODS ---
// Functions to retrieve the private data members. 'const' means they don't change the object.
double rectangleType::getLength() const
{
    return length;
}

double rectangleType::getWidth()const
{
    return width;
}

// --- 3. CALCULATION METHODS ---
double rectangleType::area() const
{
    return length * width; // Calculates and returns the area
}

double rectangleType::perimeter() const
{
    return 2 * (length + width); // Calculates and returns the perimeter
}

// --- 4. CONSTRUCTORS ---
// Constructor that takes length (l) and width (w) as arguments.
rectangleType::rectangleType(double l, double w)
{
    setDimension(l, w); // Uses the safe setter function to initialize the object
}

// Default constructor: Initializes length and width to zero.
rectangleType::rectangleType()
{
    length = 0;
    width = 0;
}

// --- 5. UNARY OPERATOR OVERLOADING (Increment/Decrement) ---

// Overloaded Pre-Increment Operator (++rectangle)
rectangleType rectangleType::operator++()
{
    // Increment the length and width by 1
    ++length;
    ++width;

    // Return the object itself (*this) after it has been incremented
    return *this;
}

// Overloaded Post-Increment Operator (rectangle++)
rectangleType rectangleType::operator++(int u) // The 'int u' is just a dummy parameter to distinguish post-increment
{
    rectangleType temp = *this;  // Copy the original object's value before incrementing

    // Increment the length and width by 1
    length++;
    width++;

    // Return the copy of the original (unincremented) object
    return temp;
}

// Overloaded Pre-Decrement Operator (--rectangle)
rectangleType rectangleType::operator--()
{
    // Ensure dimensions are not 0 before decrementing (using assert to stop the program if the condition is false)
    assert(length != 0 && width != 0);
    
    // Decrement the length and width by 1
    --length;
    --width;

    // Return the decremented object
    return *this;
}

// Overloaded Post-Decrement Operator (rectangle--)
rectangleType rectangleType::operator--(int u)
{
    rectangleType temp = *this;  // Copy the original object's value

    // Ensure dimensions are not 0 before decrementing
    assert(length != 0 && width != 0);
    
    // Decrement the length and width by 1
    length--;
    width--;

    // Return the copy of the original (undecremented) object
    return temp;
}

// --- 6. BINARY ARITHMETIC OPERATOR OVERLOADING (+, -, *) ---

// Overloaded Addition Operator (rectangle1 + rectangle2)
// Creates a new rectangle where the length is the sum of the two lengths, and the width is the sum of the two widths.
rectangleType rectangleType::operator+ 
                          (const rectangleType& rectangle) const
{
    rectangleType tempRect; // New object to store the result

    tempRect.length = length + rectangle.length;
    tempRect.width = width + rectangle.width;

    return tempRect;
}

// Overloaded Subtraction Operator (rectangle1 - rectangle2)
// Creates a new rectangle by subtracting the dimensions.
rectangleType rectangleType::operator- 
                          (const rectangleType& rectangle) const
{
    rectangleType tempRect;

    // Ensure dimensions of the first rectangle are greater than the second before subtracting
    assert(length >= rectangle.length &&
           width >= rectangle.width);

    tempRect.length = length - rectangle.length;
    tempRect.width = width - rectangle.width;

    return tempRect;
}

// Overloaded Multiplication Operator (rectangle1 * rectangle2)
// Creates a new rectangle by multiplying the dimensions.
rectangleType rectangleType::operator*(const rectangleType& rectangle) const
{
    rectangleType tempRect;

    tempRect.length = length * rectangle.length;
    tempRect.width = width * rectangle.width;

    return tempRect;
}

// --- 7. RELATIONAL OPERATOR OVERLOADING (Comparison) ---
// All comparison operators are overloaded to compare the rectangles based on their AREA.

// Equality Check (==): Returns true if the areas are equal
bool rectangleType::operator== 
                      (const rectangleType& rectangle) const
{
    return (area() == rectangle.area());
}

// Inequality Check (!=): Returns true if the areas are not equal
bool rectangleType::operator!= 
                       (const rectangleType& rectangle) const
{
    return (area() != rectangle.area());
}

// Less than or Equal to (<=)
bool rectangleType::operator<= 
                       (const rectangleType& rectangle) const
{
    return (area() <= rectangle.area());
}

// Less than (<)
bool rectangleType::operator< 
                       (const rectangleType& rectangle) const
{
    return (area() < rectangle.area());
}

// Greater than or Equal to (>=)
bool rectangleType::operator>= 
                       (const rectangleType& rectangle) const
{
    return (area() >= rectangle.area());
}

// Greater than (>)
bool rectangleType::operator>
                       (const rectangleType& rectangle) const
{
    return (area() > rectangle.area());
}

// --- 8. I/O STREAM OPERATOR OVERLOADING (Non-Member Functions) ---
// Note: These are defined outside the class because the object (rectangle) is the right operand.

// Overloaded Output Operator (cout << rectangle)
// This function takes an output stream (osObject) and the rectangle object,
// prints the dimensions, and returns the stream.
ostream& operator<<(ostream& osObject, 
                      const rectangleType& rectangle)
{
    osObject << "Length = "  << rectangle.length 
             << "; Width = " << rectangle.width;

    return osObject; // Must return the stream object
}

// Overloaded Input Operator (cin >> rectangle)
// This function takes an input stream (isObject) and the rectangle object,
// reads the new length and width, and returns the stream.
istream& operator>>(istream& isObject, rectangleType& rectangle)
{
    // Read the length and width directly into the object's private members
    isObject >> rectangle.length >> rectangle.width;

    return isObject; // Must return the stream object
}
