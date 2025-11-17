#ifndef date_H // Start of the header guard: checks if date_H is NOT defined.
#define date_H // Defines the macro date_H to prevent multiple inclusion.
 
// Declaration of the dateType class.
class dateType
{
public: // Public interface: functions accessible from outside the class.
    // Mutator (setter) function to set all date components.
    void setDate(int month, int day, int year);
    // ... (Documentation for setDate) ...

    // Accessor (getter) function to retrieve the day (const).
    int getDay() const;
    // ... (Documentation for getDay) ...

    // Accessor (getter) function to retrieve the month (const).  
    int getMonth() const;
    // ... (Documentation for getMonth) ...

    // Accessor (getter) function to retrieve the year (const).    
    int getYear() const;
    // ... (Documentation for getYear) ...

    // Function to display the date in the M-D-Y format (const).
    void printDate() const;
    // ... (Documentation for printDate) ...

    // Function to check if the stored year is a leap year.
    bool isLeapYear();
    // ... (Documentation for isLeapYear) ...

    // Constructor: Initializes the date. Uses default arguments (1/1/1900).
    dateType(int month = 1, int day = 1, int year = 1900);
    // ... (Documentation for constructor) ...

private: // Private data members: accessible only within the class implementation.
    int dMonth;      // Variable to store the month (1-12).
    int dDay;        // Variable to store the day (1-31, depends on month/year).
    int dYear;       // Variable to store the year (e.g., 2025).
};

#endif // End of the header guard.
