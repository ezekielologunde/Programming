#include <iostream> // Needed for standard input/output operations (like 'cout' and 'cin')
#include <cmath>    // Needed for mathematical functions (like 'sqrt' and 'pow')
#include <iomanip>  // Needed for formatting output (like 'setprecision')
   
using namespace std; // Allows us to use standard names like 'cout' and 'endl'

// --- Global Constant ---
// Defines the constant value for Pi (π)
const double PI = 3.14159; 

int main()
{
    double r; // Variable to store the radius of the sphere

    // --- Output Formatting ---
    cout << fixed << showpoint << setprecision(2); 
    // Sets the output to always show two decimal places for neat currency/measurement display

    // --- Calculation 1: Square Root of Pi ---
    cout << " sqrt(PI) = " << sqrt(PI) << endl; 
    // Calls the 'sqrt' function (from <cmath>) to find the square root of PI

    // --- User Input ---
    cout << "Enter a value of r: ";
    cin >> r; // Reads the radius value from the user
    cout << endl;

    // --- Calculation 2: Surface Area of a Sphere ---
    // Formula: 4 * PI * r^2
    cout << "Surface area of the sphere: 4 * PI * " << r << " ^ 2 = "
         << 4.0 * PI * pow(r, 2) << endl; 
    // Calls the 'pow' function (from <cmath>) to calculate r squared (r^2)

    // --- Calculation 3: Volume of a Sphere ---
    // Formula: (4/3) * PI * r^3
    cout << "Volume of the sphere: 4 / 3 * PI * " << r << " ^ 3 = "
         << 4.0 / 3.0 * PI * pow(r, 3) << endl; 
    // Note: 4.0/3.0 is used for floating-point division to ensure the result is accurate.
    // Calls 'pow' to calculate r cubed (r^3)

    return 0; // Signals successful execution
}
