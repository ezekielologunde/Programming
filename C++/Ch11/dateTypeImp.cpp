//Implementation file date
    
#include <iostream> // Include the standard input/output stream library (for cout).
#include "dateType.h" // Include the custom header file where the dateType class is declared.

using namespace std; // Use the standard namespace.

// Function definition: Sets the month, day, and year with extensive validation.
void dateType::setDate(int month, int day, int year)
{
    // 1. Validate and set the year.
    if (year >= 1)
        dYear = year; // Year must be positive.
    else
        dYear = 1900; // Default year if input is invalid.

    // 2. Validate and set the month.
    if (1 <= month && month <= 12)
        dMonth = month;
    else
        dMonth = 1; // Default month to January (1) if input is invalid.

    // 3. Validate and set the day based on the (now validated) month and year.
    switch (dMonth)
    {
    case 1: // January (31 days)
    case 3: // March (31 days)
    case 5: // May (31 days)
    case 7: // July (31 days)
    case 8: // August (31 days)
    case 10: // October (31 days)
    case 12: // December (31 days)
        if (1 <= day && day <= 31)
            dDay = day;
        else
            dDay = 1; // Default day to 1 if outside range [1, 31].
        break;
    case 4: // April (30 days)
    case 6: // June (30 days)
    case 9: // September (30 days)
    case 11: // November (30 days)
        if (1 <= day && day <= 30)
            dDay = day;
        else
            dDay = 1; // Default day to 1 if outside range [1, 30].
        break;
    case 2: // February (28 or 29 days)
        if (isLeapYear()) // Check if the *current* year is a leap year (29 days).
        {
            if (1 <= day && day <= 29)
                dDay = day;
            else
                dDay = 1; // Default day to 1 if outside range [1, 29].
        }
        else // Not a leap year (28 days).
        {
            if (1 <= day && day <= 28)
                dDay = day;
            else
                dDay = 1; // Default day to 1 if outside range [1, 28].
        }
    }
}

// Function definition: Getter for the day (const).
int dateType::getDay() const 
{
    return dDay;
