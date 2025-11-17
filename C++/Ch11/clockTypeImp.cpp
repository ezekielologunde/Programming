//Implementation File for the class clockType
 
#include <iostream> // Include the standard input/output stream library (for cout).
#include "clockType.h" // Include the custom header file where the clockType class is declared.
 
using namespace std; // Use the standard namespace.
 
// Function definition: Sets the time with validation.
void clockType::setTime(int hours, int minutes, int seconds)
{
    // Validate and set hours (0-23).
    if (0 <= hours && hours < 24)
        hr = hours;
    else 
        hr = 0; // Default to 0 if hours are invalid.

    // Validate and set minutes (0-59).
    if (0 <= minutes && minutes < 60)
        min = minutes;
    else 
        min = 0; // Default to 0 if minutes are invalid.

    // Validate and set seconds (0-59).
    if (0 <= seconds && seconds < 60)
        sec = seconds;
    else 
        sec = 0; // Default to 0 if seconds are invalid.
}

// Function definition: Retrieves the current time via reference parameters (const).
void clockType::getTime(int& hours, int& minutes, 
                        int& seconds) const
{
    hours = hr;   // Return the hour value.
    minutes = min; // Return the minute value.
    seconds = sec; // Return the second value.
}

// Function definition: Increments the hour by one.
void clockType::incrementHours()
{
    hr++; // Increase hour by 1.
    // Wrap around from 23 to 0.
    if (hr > 23)
        hr = 0;
}

// Function definition: Increments the minute by one.
void clockType::incrementMinutes()
{
    min++; // Increase minute by 1.
    // Check for overflow (60 minutes).
    if (min > 59)
    {
        min = 0;          // Reset minutes to 0.
        incrementHours(); // Carry over to the next hour.
    }
}

// Function definition: Increments the second by one.
void clockType::incrementSeconds()
{
    sec++; // Increase second by 1.

    // Check for overflow (60 seconds).
    if (sec > 59)
    {
        sec = 0;            // Reset seconds to 0.
        incrementMinutes(); // Carry over to the next minute.
    }
}

// Function definition: Prints the time in HH:MM:SS format with leading zeros (const).
void clockType::printTime() const
{
    // Print hour with a leading zero if < 10.
    if (hr < 10)
        cout << "0";
    cout << hr << ":";

    // Print minute with a leading zero if < 10.
    if (min < 10)
        cout << "0";
    cout << min << ":";

    // Print second with a leading zero if < 10.
    if (sec < 10)
        cout << "0";
    cout << sec;
}

// Function definition: Compares the current clock object with another clock object (const).
bool clockType::equalTime(const clockType& otherClock) const
{
    // Returns true if hour, minute, and second are all equal in both objects.
    return (hr == otherClock.hr 
            && min == otherClock.min 
            && sec == otherClock.sec);
}

// Function definition: Parameterized constructor. Initializes time with validation.
clockType::clockType(int hours, int minutes, int seconds)
{
    // Initialization with validation logic (identical to setTime).
    if (0 <= hours && hours < 24)
        hr = hours;
    else 
        hr = 0;

    if (0 <= minutes && minutes < 60)
        min = minutes;
    else 
        min = 0;

    if (0 <= seconds && seconds < 60)
        sec = seconds;
    else 
        sec = 0;
}

// Function definition: Default constructor. Initializes time to 00:00:00.
clockType::clockType() 
{
    hr = 0; // Initialize hour.
    min = 0; // Initialize minute.
    sec = 0; // Initialize second.
}
