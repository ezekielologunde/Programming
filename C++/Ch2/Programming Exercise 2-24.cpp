#include <iostream>

using namespace std; 
  
int main()
{
    // Declare variables for the length of the wire and the calculated width of the frame.
    double wireLength;
    double width;
    
    // Prompt the user to enter the total length of the wire.
    cout << "Enter the length of the wire: ";
    cin >> wireLength;
    cout << endl;

    // Calculate the width of the frame.
    // The perimeter is equal to the wire length.
    // The problem states that the length is 1.5 times the width, so the perimeter is
    // 2 * (length + width) = 2 * (1.5 * width + width) = 2 * (2.5 * width) = 5.0 * width.
    // Therefore, width = perimeter / 5.0.
    width = wireLength / 5.0;

    // Output the calculated length and width of the picture frame.
    cout << "Frame length: " << 1.5 * width << endl;
    cout << "Frame width: " << width << endl;

    return 0;
}
