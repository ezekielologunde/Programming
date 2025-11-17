#ifndef H_ExtClockType // Line 1: Check if the header guard macro H_ExtClockType is NOT defined.
#define H_ExtClockType // Line 2: If not defined, define H_ExtClockType to prevent multiple inclusion.
 
#include <string> // Include the string library for using the timeZone member.

#include "clockType.h" // Include the header file for the base class (clockType).

using namespace std; // Use the standard namespace.
 
// Declaration of the derived class extClockType.
// It publicly inherits all public members from clockType.
class extClockType: public clockType
{
public: // Public interface of the derived class.
    // Overrides or extends the base class's setTime function to include a time zone argument.
    void setTime(int hours, int minutes, int seconds, string tZone);
    // Overrides the base class's printTime function to include the time zone in the output.
    void printTime();

    // Constructor: Calls the base class constructor implicitly/explicitly and initializes timeZone.
    // Uses default arguments for creating objects without initial values.
    extClockType(int = 0, int = 0, int = 0, string = "EST");

private: // Private data member unique to the derived class.
    string timeZone; // Stores the time zone identifier (e.g., "CST", "PST").
};

#endif // Line 3: Ends the header guard.
