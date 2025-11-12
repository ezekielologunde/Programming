//Main program
  
#include <iostream>      // Includes the library for standard input/output (like 'cout')
#include "counterType.h" // Includes the header file containing the definition of the counterType class

using namespace std;     // Allows us to use standard names like 'cout' and 'endl'

int main()
{
    // --- Object Creation ---
    
    // Creates an object named counter1 using the default constructor (likely initializes the count to 0)
    counterType counter1; 
    
    // Creates an object named counter2 using the overloaded constructor, initializing its count to 5
    counterType counter2(5); 

    // --- Object Manipulation ---
    
    // Calls the print() method to display the current value of counter1 (should be 0)
    counter1.print(); 

    cout << endl;

    // Calls the method to increase the count of counter1 by 1
    counter1.incrementCounter(); 
    
    // Calls the getter method to retrieve and print the new value of counter1 (should be 1)
    cout << "After Increment counter1: " << counter1.getCounter() << endl; 

    // Prints the current value of counter2 (should be 5)
    cout << "Counter2 = " << counter2.getCounter() << endl; 

    // Calls the method to decrease the count of counter2 by 1
    counter2.decrementCounter(); 
    
    // Prints the new value of counter2 (should be 4)
    cout << "After decrement counter2 = " << counter2.getCounter() << endl; 

    // Calls the setter method to attempt to set the value of counter1 to -6.
    // (Note: A well-designed counter class usually limits the value, so it may reset to 0 or 1,
    // but the intention is to change the value.)
    counter1.setCounter(-6); 
    
    // Prints the final value of counter1 after attempting the reset
    cout << "After resetting counter1: " << counter1.getCounter() << endl; 

    return 0; // Signals successful execution
}
