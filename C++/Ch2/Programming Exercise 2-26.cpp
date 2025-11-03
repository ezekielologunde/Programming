#include <iostream>

using namespace std;

// Named constant for the area one gallon of paint can cover, in square feet.
const double ONE_GALLON_PAINT_AREA = 120.00; 
  
int main()
{
    // Declare variables for the dimensions of various objects in the room.
    double doorLength;
    double doorWidth;
    double window1Length;
    double window1Width;
    double window2Length;
    double window2Width;
    double bookShelfLength;
    double bookShelfWidth;
    double roomLength;
    double roomWidth;
    double roomHeight;

    // Declare variables for calculated values.
    double paintArea;
    double amountOfPaintNeeded;
    
    // Prompt the user to enter the dimensions of the door.
    cout << "Enter the length and width of the door: ";
    cin >> doorLength >> doorWidth;
    cout << endl;

    // Prompt the user for the dimensions of the first window.
    cout << "Enter the length and width of the first window: ";
    cin >> window1Length >> window1Width;
    cout << endl;

    // Prompt the user for the dimensions of the second window.
    cout << "Enter the length and width of second window: ";
    cin >> window2Length >> window2Width;
    cout << endl;

    // Prompt the user for the dimensions of the bookshelf.
    cout << "Enter the length and width of the bookshelf: ";
    cin >> bookShelfLength >> bookShelfWidth;
    cout << endl;

    // Prompt the user for the dimensions of the room.
    cout << "Enter the length, width, and height of the room: ";
    cin >> roomLength >> roomWidth >> roomHeight;
    cout << endl;

    // Calculate the total area to be painted. This includes the area of the four walls
    // (2 * length * height + 2 * width * height) minus the areas of the door, windows, and bookshelf.
    paintArea = 2 * roomLength * roomHeight + 2 * roomWidth * roomHeight 
                - doorLength * doorWidth - window1Length * window1Width 
                - window2Length * window2Width - bookShelfLength * bookShelfWidth;

    // Calculate the total amount of paint needed by dividing the paintable area by the coverage of one gallon.
    amountOfPaintNeeded = paintArea / ONE_GALLON_PAINT_AREA;

    // Output the final result.
    cout << "The amount of paint needed to paint the room: "
         << amountOfPaintNeeded << " gallons." << endl;

    return 0;
}
