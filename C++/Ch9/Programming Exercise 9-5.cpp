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
// Reads menu items and prices from the input file.
void getData(ifstream& inFile, menuItemType mList[], int listSize);
// Displays the menu to the console.
void showMenu(menuItemType mList[], int listSize);
// Calculates and prints the total bill (check) based on quantities, including tax.
void printCheck(menuItemType mList[], int listSize, 
                int cList[][2], int cListLength);
// Allows the user to select items and specify the quantity for each.
void makeSelection(menuItemType mList[], int listSize, 
                   int cList[][2], int& cListLength);

// Main function where program execution begins.
int main()
{
    menuItemType menuList[NO_OF_ITEMS]; // Array to store all 8 menu items (name and price).
    // 2D Array: choiceList[i][0] = menu index, choiceList[i][1] = quantity ordered.
    int choiceList[NO_OF_ITEMS][2];
    int choiceListLength; // Tracks the number of *unique* items selected so far.

    ifstream inFile; // Declare an input file stream object.

    // Set output formatting for prices: fixed decimal, show point, 2 decimal places.
    cout << fixed << showpoint << setprecision(2);

    // Attempt to open the input data file.
    inFile.open("Ch9_Ex5Data.txt");

    // Check if the input file failed to open.
    if (!inFile)
    {
        // Output an error message and terminate the program with an error code.
        cout << "Cannot open the input file. Program Terminates!"
             << endl;
        return 1;
    }

    // Read menu data from the file into the menuList array.
    getData(inFile, menuList, NO_OF_ITEMS);
    // Display the menu to the user.
    showMenu(menuList, NO_OF_ITEMS);
    // Handle the user's item selection and quantities.
    makeSelection(menuList, NO_OF_ITEMS, choiceList, choiceListLength);
    // Calculate and display the final check/bill.
    printCheck(menuList, NO_OF_ITEMS, choiceList, choiceListLength);

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
        // Read and discard the newline character left after reading the price.
        inFile.get(ch);
    }
}

// Function definition: Displays the menu to the user.
void showMenu(menuItemType mList[], int listSize)
{
    cout << "Welcome to Johnny's Resturant" << endl;
    cout << "----Today's Menu----" << endl;

    // Loop through the menu list to print the item number, name, and price.
    for (int i = 0; i < listSize; i++)
        // Output item number (i+1), name (left-aligned), and price (right-aligned).
        cout << i + 1 << ": " << left << setw(15) << mList[i].menuItem
             << right << " $" << mList[i].menuPrice << endl;
    cout << endl;
}

// Function definition: Calculates and prints the receipt (check) including total and tax.
void printCheck(menuItemType mList[], int listSize, 
                int cList[][2], int cListLength)
{
    int i;
    double salesTax;
    double amountDue = 0; // Total cost before tax.

    cout << "Welcome to Johnny's Resturant" << endl;
    // Loop through the user's list of selected item *records*.
    for (i = 0; i < cListLength; i++)
    {
        // Print the quantity (cList[i][1]).
        cout << cList[i][1] << " "
             // Print the item name (using index cList[i][0]).
             << left << setw(15) << mList[cList[i][0]].menuItem
             << right << " $" << setw(4)
             // Print the total cost for this item (Price * Quantity).
             << mList[cList[i][0]].menuPrice * cList[i][1] << endl;
        // Accumulate the cost of the item to the total amount due.
        amountDue += mList[cList[i][0]].menuPrice * cList[i][1];
    }

    // Calculate 5% sales tax.
    salesTax = amountDue * .05;
    // Print the sales tax amount.
    cout << "  " << left << setw(15) << "Tax "
         << right << " $" << salesTax << endl;

    // Add tax to the subtotal to get the final amount due.
    amountDue = amountDue + salesTax;
    // Print the final total amount due.
    cout << "  " << left << setw(15) << "Amount Due "
         << right << " $" << amountDue << endl;
}

// Function definition: Handles user selection and quantity input.
void makeSelection(menuItemType mList[], int listSize, 
                   int cList[][2], int& cListLength)
{
    int itemNo; // Variable to store the item number selected by the user (1-8).
    int noOfOrders; // Variable to store the quantity ordered for the item.

    char response; // Variable to store the user's Y/N response.

    cListLength = 0; // Initialize the length (number of selections) to zero.

    // Initialize all quantity fields to 0 (though the main logic overrides this).
    // This loop seems incomplete/redundant given the later logic.
    for (int i = 0; i < listSize; i++)
        cList[i][1] = 0; 


    cout << "You can make up to " << listSize
         << " different selections" << endl;

    // Ask the user if they want to start selecting.
    cout << "Do you want to make selection Y/y (Yes), N/n (No): ";
    cin >> response;
    cout << endl
