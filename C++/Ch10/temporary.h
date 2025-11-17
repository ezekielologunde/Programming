#include <string> // Include the string library, necessary for using the string data type.

using namespace std; // Use the standard namespace to simplify code.

// Declaration of the custom class named temporary.
class temporary
{
public: // All members declared here are publicly accessible.
    // Setter function to set all three data members at once (description, first, second).
    void set(string, double, double);
    // Function to print the details (description, first, second) of the object.
    void print();
    // Function to perform a manipulation/calculation (like area or volume) and return the result.
    double manipulate();
    // Function to retrieve the values of all three private data members via reference parameters.
    void get(string&, double&, double&);
    // Setter function to modify the description.
    void setDescription(string);
    // Setter function to modify the 'first' dimension/parameter.
    void setFirst(double);
    // Setter function to modify the 'second' dimension/parameter.
    void setSecond(double); 
    // Getter function to retrieve the description (const means it won't change the object).
    string getDescription() const;
    // Getter function to retrieve the 'first' dimension/parameter (const).
    double getFirst() const;
    // Getter function to retrieve the 'second' dimension/parameter (const).
    double getSecond() const;

    // Constructor: Called when a temporary object is created. Uses default arguments for flexibility.
    temporary(string = "", double = 0, double = 0);

private: // All members declared here are privately accessible (only by class members).
    string description; // Private data member to store the object's description/type (e.g., "rectangle").
    double first;       // Private data member to store the first dimension (e.g., length or radius).
    double second;      // Private data member to store the second dimension (e.g., width or height).
};
