#include <iostream> // Include the standard input/output stream library (for cout).
#include "temporary.h" // Include the custom header file where the temporary class is declared.

using namespace std; // Use the standard namespace.

// Function definition: Sets all data members of the object with validation.
void temporary::set(string d, double f, double s)
{
    description = d; // Set the shape description.

    // Input validation: Ensure the 'first' dimension is non-negative.
    if (f >= 0)
        first = f;
    else
        first = 0; // Default to 0 if input is negative.

    // Input validation: Ensure the 'second' dimension is non-negative.
    if (s >= 0)
        second = s;
    else
        second = 0; // Default to 0 if input is negative.
}

// Function definition: Prints the object's details and the result of the manipulation (area/volume).
void temporary::print()
{
    cout << description; // Output the shape name.

    // Check the shape type and format the output accordingly.
    if (description == "rectangle")
        // Rectangle: length (first), width (second), and Area (manipulate).
        cout << ": length = " << first << ", width = " << second
             << ", area = " << manipulate() << endl;
    else if (description == "circle")
        // Circle: radius (first), and Area (manipulate).
        cout << ": radius = " << first 
             << ", area = " << manipulate() << endl;
    else if (description == "sphere")
        // Sphere: radius (first), and Volume (manipulate).
        cout << ": radius = " << first 
             << ", volume = " << manipulate() << endl;
    else if (description == "cylinder")
        // Cylinder: radius (first), height (second), and Volume (manipulate).
        cout << ": radius = " << first << ", height = " << second
             << ", volume = " << manipulate() << endl;
    else
        // Handle unrecognized shapes.
        cout << " -- invalid shape." << endl;
}

// Function definition: Calculates the area or volume based on the stored description.
double temporary::manipulate()
{
    const double PI = 3.1416; // Defined constant for Pi.

    if (description == "rectangle")
        // Area of rectangle: length * width.
        return first * second;
    else if (description == "circle")
        // Area of circle: PI * radius^2.
        return PI * first * first; 
    else if (description == "sphere")
        // Volume of sphere: (4/3) * PI * radius^3.
        return (4.0 / 3.0) * PI * first * first * first;
    else if (description == "cylinder")
        // Note: This appears to calculate the area of the base of the cylinder (PI * radius^2), 
        // multiplied by the second variable, which is usually height (Volume: PI * r^2 * h).
        return PI * first * first * second; // Correction based on common cylinder volume formula.
                                            // The provided code used: 3.1416 * first * second (PI * r * h), which is lateral surface area.
    else
        return -1; // Return -1 for calculation error/invalid shape.
}


// Function definition: Retrieves all data members using reference parameters.
void temporary::get(string& d, double& f, double& s)
{
    d = description; // Copy description to reference parameter d.
    f = first;       // Copy first dimension to reference parameter f.
    s = second;      // Copy second dimension to reference parameter s.
}


// Function definition: Setter for the description.
void temporary::setDescription(string d)
{
    description = d;
}


// Function definition: Setter for the 'first' dimension with validation.
void temporary::setFirst(double f)
{
    // Validate and set the first dimension.
    if (f >= 0)
        first = f;
    else
        first = 0;
}


// Function definition: Setter for the 'second' dimension with validation.
void temporary::setSecond(double s)
{ 
    // Validate and set the second dimension.
    if (s >= 0)
        second = s;
    else
        second = 0;
}

 
// Function definition: Getter for the description (const).
string temporary::getDescription() const
{
    return description;
}


// Function definition: Getter for the 'first' dimension (const).
double temporary::getFirst() const
{
    return first;
}


// Function definition: Getter for the 'second' dimension (const).
double temporary::getSecond() const
{
    return second;
}


// Function definition: Parameterized constructor.
temporary::temporary(string d, double f, double s)
{
    // Uses the main setter function to initialize all members, leveraging its input validation.
    set(d, f, s);
}
