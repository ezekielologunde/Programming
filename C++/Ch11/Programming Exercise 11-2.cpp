#include <iostream> // Include the standard input/output stream library (for cin, cout).
#include "dateType.h" // Include the custom header file defining the dateType class.

using namespace std; // Use the standard namespace.
 
// Main function where program execution begins.
int main()
{
    // 1. Create date1 using the parameterized constructor: (Month, Day, Year).
    dateType date1(3, 15, 2008);
    // 2. Create date2 using the parameterized constructor (likely tests invalid month input).
    dateType date2(15, 20, 2008);
    // 3. Create date3 using the parameterized constructor (likely tests invalid day input for Feb).
    dateType date3(2, 30, 2009);
    // 4. Create date4 using the default constructor (should initialize to 1/1/1900 or similar default).
    dateType date4;
    
    // Variables to store user input for month, day, and year.
    int m, d, y;

    // Output the details for date1.
    cout << "Date 1: ";
    date1.printDate(); // Call the member function to print the date.
    if (date1.isLeapYear()) { // Check if the year (2008) is a leap year.
        cout << endl << "this is a leap year";
    } else {
        cout << endl << "this is not a leap year";
    }
    cout << endl;

    // Output the details for date2 (tests constructor validation for month 15).
    cout << "Date 2: ";
    date2.printDate();
    if (date2.isLeapYear()) {
        cout << endl << "this is a leap year";
    } else {
        cout << endl << "this is not a leap year";
    }
    cout<<endl;

    // Output the details for date3 (tests constructor validation for day 30 in month 2).
    cout << "Date 3: ";
    date3.printDate();
    if (date3.isLeapYear()) {
        cout << endl << "this is a leap year";
    } else {
        cout << endl << "this is not a leap year";
    }
    cout << endl;

    // Prompt the user for a new date.
    cout << "Enter month day year: ";
    // Read the user input into m, d, and y.
    cin >> m >> d >>y;
    cout << endl;

    // Set the state of date4 using the user-provided and likely validated input.
    date4.setDate(m, d, y);

    // Output the details for the user-defined date4.
    cout << "Date 4: ";
    date4.printDate();
    if (date4.isLeapYear()) {
        cout << endl << "this is a leap year";
    } else {
        cout << endl << "this is not a leap year";
    }
    cout << endl;

    // Indicate that the program finished successfully.
    return 0;
}
