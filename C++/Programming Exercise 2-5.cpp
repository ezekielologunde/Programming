#include <iostream>

using namespace std;

// A constant variable for the value of PI, used for calculations.
const double PI = 3.14;  

int main() {
    // Declare variables to store the radius and the calculated area and circumference.
    double radius;
    double area;
    double circumference;

    // Prompt the user to enter the radius of the circle.
    cout << "Enter the radius: ";
    cin >> radius;
    cout << endl;

    // Calculate the area of the circle using the formula: A = PI * r^2
    area = PI * radius * radius;
    
    // Calculate the circumference of the circle using the formula: C = 2 * PI * r
    circumference = 2 * PI * radius;
    
    // Output the calculated area and circumference to the console.
    cout << "Area = " << area << endl;
    cout << "Circumference = " << circumference << endl;

    // Return 0 to indicate successful program execution.
    return 0;
}
