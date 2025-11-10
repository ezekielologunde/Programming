#include <iostream> // Include the standard input/output stream library (for cin, cout).
#include <fstream>  // Include the file stream library (for file input/output).
#include <iomanip>  // Include the I/O manipulator library (for formatting output, like setprecision).
#include <string>   // Include the string library (for using the string data type).

using namespace std; // Use the standard namespace to simplify code.

const int NO_OF_ITEMS = 8; // Constant defining the maximum number of items on the menu.

// Define a structure to hold the data for a single menu item.
struct menuItemType
{
    string menuItem; // Name/description of the menu item.
    double menuPrice; // Price of the menu item.
};

// Function prototypes (declarations)
// Reads menu items and prices from the input file into the menu array.
void getData(ifstream& inFile, menuItemType mList[], int listSize);
// Displays the menu to the console.
void showMenu(menuItemType mList[], int listSize);
// Calculates and prints the total bill (check), including tax.
void printCheck(menuItemType mList[], int listSize, 
                int cList[], int cListLength);
// Allows the user to select items from the menu.
void makeSelection(int listSize, 
                   int cList[], int& cListLength);
// Checks if a specific item number has already been selected by the user.
bool isItemSelected(int cList[], int cListLength, int itemNo);

// Main function where program execution begins.
int main()
{
    menuItemType menuList[NO_OF_ITEMS]; // Array to store all 8 menu items (name and price).
    int choiceList[NO_OF_ITEMS]; // Array to store the array index (0-7) of the items selected by the user.
    int choiceListLength; // Variable to track the actual number of items the user selected.

    ifstream inFile; // Declare an input file stream object.

    // Set output formatting for prices: fixed decimal, show point, 2 decimal places.
    cout << fixed << showpoint << setprecision(2);

    // Attempt to open the input data file.
    inFile.open("Ch9_Ex4Data.txt");

    // Check if the input file failed to open.
    if (!inFile)
    {
        // Output an error message and terminate the program with an error code.
        cout << "Cannot open the input file. Program Terminates!"
             << endl;
        return 1;
    }

    // Call function to read menu data from the file into the menuList array.
    getData(inFile, menuList, NO_OF_ITEMS);
    // Call function to display the menu to the user.
    showMenu(menuList, NO_OF_ITEMS);
    // Call function to handle the user's item selection.
    makeSelection(NO_OF_ITEMS, 
                  choiceList, choiceListLength);
    // Call function to calculate and display the final check/bill.
    printCheck(menuList, NO_OF_ITEMS, 
               choiceList, choiceListLength);

    // Indicate that the program finished successfully.
    return 0;
}

// Function definition: Reads menu data from the input file.
void getData(ifstream& inFile, menuItemType mList[], int listSize)
{
    char ch; // Temporary character to consume the newline character.
    // Loop through the array size to read each item.
    for (int i = 0; i < listSize; i++)
    {
        // Read the item name (which may contain spaces) until the newline.
        getline(inFile, mList[i].menuItem);
        // Read the item price (a double).
        inFile >> mList[i].menuPrice;
