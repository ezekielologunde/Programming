#include <iostream>
#include <cmath>

using namespace std;

// This constant converts cubic yards to cubic feet.
// A cubic yard is equal to 27 cubic feet.
const int cubicFeetInaYard = 27;
  
int main() {
    // Declare variables for the amount of concrete, patio dimensions, and ratio components.
    double concrete; // Stores the amount of premixed concrete in cubic yards.
    double width, thickness; // Stores the calculated width and user-input thickness.
    double x, y; // Stores the components of the length-to-width ratio.
    double lengthToWidthRatio; // Stores the calculated ratio.
        
    // Prompt the user to enter the amount of concrete ordered.
    cout << "Enter the amount of premixed concrete (in cubic yards) ordered: ";
    cin >> concrete;
    cout << endl;

    // Prompt the user for the patio's thickness in inches.
    cout << "Enter the thickness of patio (in inches): ";
    cin >> thickness;

    // Prompt the user for the length-to-width ratio (e.g., 3 2).
    cout << "Enter the ratio of length to width (If the ratio is 3 to 2, then enter 3 2): ";
    cin >> x >> y;
    cout << endl;

    // Calculate the single length-to-width ratio from the two input numbers.
    lengthToWidthRatio = x / y;

    // Calculate the width of the patio using the volume formula.
    // The formula is derived from Volume = Length * Width * Thickness, where
    // Length = ratio * Width.
    // So, Volume = (ratio * Width) * Width * Thickness, or Volume = ratio * Width^2 * Thickness.
    // Rearranging to solve for Width:
    // Width = sqrt(Volume / (ratio * Thickness))
    // The total volume is converted from cubic yards to cubic feet.
    // The thickness is converted from inches to feet by dividing by 12.
    width = sqrt(concrete * cubicFeetInaYard / (lengthToWidthRatio * thickness / 12));

    // Output the final calculated dimensions of the patio.
    // The length is found by multiplying the width by the ratio.
    cout << "The length, width, and thickness of the patio are: "
        << "Length = " << lengthToWidthRatio * width << " feet (foot), "
        << "Width = " << width << " feet (foot), "
        << "Thickness = " << thickness << " inche(s)." << endl;

    return 0;
}
// This program calculates the dimensions of a rectangular patio based on the amount of premixed concrete ordered,
// the desired thickness of the patio, and the length-to-width ratio provided by the user.
// It uses the formula for volume and rearranges it to solve for the width, then calculates the length using the ratio.
// The program assumes the user inputs valid numerical values and does not include error handling for invalid input.
// The program uses the C++17 standard for compilation.
