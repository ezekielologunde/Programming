#include <iostream>      // For standard input/output operations
#include <iomanip>       // For output formatting (like setprecision)
#include "houseType.h"   // Include the header file defining the houseType class

using namespace std;

int main()
{
    // Create a houseType object with given property details
    // Arguments: style, number of bedrooms, number of bathrooms,
    // number of floors, year built, garage size, price, and tax rate.
    houseType newHouse("split", 5, 3, 2, 2004, 2, 275000.00, 0.0125);

    cout << fixed << showpoint << setprecision(2);  // Format numeric output to show 2 decimal places

    cout << "House Information:" << endl;
    cout << "------------------" << endl;

    // Print the information about the house using the class's member function
    newHouse.print();

    cout << endl;
    return 0; // Indicate successful program execution
}
