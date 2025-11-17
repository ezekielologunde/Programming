#include <iostream> // Include the standard input/output stream library (for cout).
#include <string>   // Include the string library (for time zone data).
#include "extClockType.h" // Include the custom header file where the extClockType class is declared.
 
using namespace std; // Use the standard namespace.

// Function definition: Sets the time (hours, minutes, seconds) and the time zone.
void extClockType::setTime(int hours, int minutes, 
                          int seconds, string tZone)
{
    // Call the setTime function of the base class (clockType) to set the time components.
    clockType::setTime(hours, minutes, seconds);
    // Set the timeZone, which is the unique member of the derived class.
    timeZone = tZone;
}

// Function definition: Prints the time, overriding the base class's printTime function.
void extClockType::printTime()
{ 
    // Call the printTime function of the base class to print the hours, minutes, and seconds.
    clockType::printTime();
    // Append the time zone string.
    cout << " " << timeZone;
}

// Function definition: Parameterized constructor for extClockType.
extClockType::extClockType(int hours, int minutes, 
                           int seconds, string tZone)
    // Initialization list: Calls the base class (clockType) constructor to initialize time components.
    :clockType(hours, minutes, seconds)
{
    // Initialize the unique data member of the derived class.
    timeZone = tZone;
}
