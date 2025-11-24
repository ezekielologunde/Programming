// User-defined exception class.
 
#include <iostream>                     //Line 1: Includes the library for input/output (though not directly used here, it's often included).
#include <string>                       //Line 2: Includes the library needed for the 'string' data type.
   
using namespace std;                    //Line 3: Allows the use of standard names like 'string'.

// --- Class Definition: divisionByZero ---
// This class represents a specific type of error (an exception).
class divisionByZero                    //Line 4: Begins the definition of the custom exception class.
{                                       //Line 5
public:                                 //Line 6: Public members are accessible from outside the class.
    
    // --- Default Constructor ---
    divisionByZero()                    //Line 7: Constructor with no arguments.
    {                                   //Line 8
        // Initializes the error message to a default string.
        message = "Division by zero";   //Line 9: Sets the default error description.
    }                                   //Line 10

    // --- Overloaded Constructor ---
    divisionByZero(string str)          //Line 11: Constructor that accepts a custom string argument.
    {                                   //Line 12
        // Initializes the error message to the string provided by the user.
        message = str;                  //Line 13: Sets the custom error description.
    }                                   //Line 14

    // --- Accessor Method (Getter) ---
    // This is the function called in the catch block (e.g., divByZeroObj.what()) to get the error message.
    string what()                       //Line 15: Function to return the stored message.
    {                                   //Line 16
        return message;                 //Line 17: Returns the private error message.
    }                                   //Line 18

private:                                //Line 19: Private members are only accessible within the class.
    string message;                     //Line 20: The private variable that stores the specific error message.
};
