//clockType.h, the specification file for the class clockType
#ifndef H_ClockType // Start of the header guard: checks if H_ClockType is NOT defined.
#define H_ClockType // Defines the macro H_ClockType to prevent multiple inclusion.

// Declaration of the clockType class.
class clockType 
{
public: // Public interface: functions accessible from outside the class.
    // Mutator (setter) function to set the time components (hours, minutes, seconds).
    void setTime(int hours, int minutes, int seconds);
    // ... (Documentation for setTime) ...

    // Accessor (getter) function to retrieve the time components via reference parameters (const).
    void getTime(int& hours, int& minutes, int& seconds) const;
    // ... (Documentation for getTime) ...

    // Function to display the time in HH:MM:SS format (const).
    void printTime() const;
    // ... (Documentation for printTime) ...

    // Function to advance the time by one second.
    void incrementSeconds();
    // ... (Documentation for incrementSeconds) ...

    // Function to advance the time by one minute.
    void incrementMinutes();
    // ... (Documentation for incrementMinutes) ...

    // Function to advance the time by one hour.
    void incrementHours();
    // ... (Documentation for incrementHours) ...

    // Function to compare two clock objects for equality (const).
    bool equalTime(const clockType& otherClock) const;
    // ... (Documentation for equalTime) ...

    // Parameterized constructor: Initializes the time based on input values with validation.
    clockType(int hours, int minutes, int seconds);
    // ... (Documentation for parameterized constructor) ...

    // Default constructor: Initializes the time to 00:00:00.
    clockType();
    // ... (Documentation for default constructor) ...
    
private: // Private data members: accessible only within the class.
    int hr;  // Variable to store the hours (0-23).
    int min; // Variable to store the minutes (0-59).
    int sec; // Variable to store the seconds (0-59).
};
#endif // End of the header guard.
