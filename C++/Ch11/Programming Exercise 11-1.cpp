//Program that uses the class extClockType
 
#include <iostream> // Include the standard input/output stream library (for cin, cout).
#include "extClockType.h" // Include the custom header file defining the extClockType class.
 
using namespace std; // Use the standard namespace.

// Main function where program execution begins.
int main()
{
    // 1. Create extClockType object time1 using the parameterized constructor: (hour, minute, second, time zone).
    extClockType time1(5, 10, 34, "CST");
    // 2. Create extClockType object time2 using the default constructor.
    extClockType time2; 
    
    // Output the initial state of time1.
    cout << "Time 1: ";
    // Call the member function to print time1's current time and time zone.
    time1.printTime();
    cout << endl;

    // Set time2's time and time zone using the custom setter function.
    time2.setTime(12, 45, 59, "PST");

    // Output the updated state of time2.
    cout << "Time 2: ";
    time2.printTime();
    cout << endl;

    // Increment time2 by exactly one second.
    time2.incrementSeconds();

    // Output the state of time2 after the increment operation.
    cout << "After incrementing time2 by one second, Time 2: ";
    time2.printTime();
    cout << endl;

    // Indicate that the program finished successfully.
    return 0;
}//end main
