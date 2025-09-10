#include <iostream>

using namespace std; 

// Named constant for the number of seconds in an hour.
const int SECONDS_PER_HOUR = 3600;
// Named constant for the number of seconds in a minute.
const int SECONDS_PER_MINUTE = 60; 

int main() 
{
    // Declare integer variables for hours, minutes, and seconds.
    int hours; 
    int minutes;
    int seconds;

    // Prompt the user to enter the elapsed time in seconds.
    cout << "Enter the elapsed time in seconds: ";
    cin >> seconds; 
    cout << endl;

    // Output the total seconds entered by the user.
    cout << "The elapsed time in seconds = " << seconds << endl;

    // Calculate the number of hours and update the remaining seconds.
    hours = seconds / SECONDS_PER_HOUR;
    seconds = seconds % SECONDS_PER_HOUR;
    
    // Calculate the number of minutes from the remaining seconds and update the seconds.
    minutes = seconds / SECONDS_PER_MINUTE;
    seconds = seconds % SECONDS_PER_MINUTE;

    // Output the equivalent time in the format hours:minutes:seconds.
    cout << "The equivalent time in hours:minutes:seconds = "
         << hours << ":" << minutes << ":" << seconds << endl;

    return 0;
}
