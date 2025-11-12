#include <iostream>      // Needed for input/output operations (like 'cout')
#include "counterType.h" // Includes the class definition (the blueprint) for counterType

using namespace std; // Allows us to use standard names like 'cout' and 'endl'

// --- Method Implementation: Initializes the counter value to zero ---
// The 'counterType::' part tells the compiler that this function belongs to the counterType class.
void counterType::initializeCounter()
{
    counter = 0; // Sets the private variable 'counter' to 0
}

// --- Method Implementation: Sets the counter to a new value ---
void counterType::setCounter(int x)
{
    // Safety check: ensures the counter value is not set to a negative number
    if (x >= 0)
        counter = x;
    else
        counter = 0; // If the input is negative, it defaults the counter to 0
}

// --- Method Implementation: Increases the counter by one ---
void counterType::incrementCounter()
{
    counter++; // Uses the shorthand operator to add 1 to the counter
}

// --- Method Implementation: Decreases the counter by one ---
void counterType::decrementCounter()
{
    // Safety check: prevents the counter from becoming negative
    if (counter <= 0)
        cout << "Counter cannot be negative." << endl;
    else
        counter--; // Subtracts 1 from the counter
}

// --- Method Implementation: Retrieves the current value of the counter ---
// 'const' indicates that this function does not change the state of the object.
int counterType::getCounter() const
{
    return counter; // Returns the current value of the private 'counter' variable
}

// --- Method Implementation: Prints the current counter value ---
// 'const' indicates that this function does not change the state of the object.
void counterType::print() const
{
    cout << "Counter = " << counter << endl;
}

// --- Constructor Implementation: Sets the initial value when an object is created ---
// This constructor takes an integer 'x' and sets the initial value of the counter.
counterType::counterType(int x)
{
    // Calls the safe 'setCounter' method to validate the input 'x'
    setCounter(x); 
}
