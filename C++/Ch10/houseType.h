#include <string> // Includes the library needed to use the 'string' data type

using namespace std; // Allows us to use standard names like 'string'

// --- Class Definition: houseType ---
// This class is a blueprint for creating objects that hold information about a house.
class houseType
{
public: // --- PUBLIC SECTION: These functions (methods) can be called from outside the class. ---

    // Function to set ALL the property values at once.
    void set(string, int, int, int, int, int, double, double);

    // Function to display all the property information. 'const' means it won't change the data.
    void print() const;

    // --- Accessor/Mutator Pairs (Getters and Setters) ---
    // These functions allow controlled access to the private data members.

    // Style (e.g., "Ranch", "Colonial")
    void setStyle(string);      // Mutator (Setter): Allows setting the style
    string getStyle() const;    // Accessor (Getter): Allows retrieving the style

    // Number of Bedrooms
    void setNumOfBedrooms(int);
    int getNumOfBedrooms() const;

    // Number of Bathrooms
    void setNumOfBathrooms(int);
    int getNumOfBathrooms() const;

    // Number of Cars the Garage can hold
    void setNumOfCarsGarage(int);
    int getNumOfCarsGarage() const;

    // Year the house was built
    void setYearBuilt(int);
    int getYearBuilt() const;

    // Total finished area in square feet
    void setFinishedSquareFootage(int);
    int getFinishedSquareFootage() const;

    // Price of the house
    void setPrice(double);
    double getPrice() const;

    // Annual tax amount
    void setTax(double);
    double getTax() const;

    // Constructor: This special function is called when a new 'houseType' object is created.
    // The arguments are given default values (like "" for string, 0 for int) so an object can 
    // be created without passing any initial values.
    houseType(string = "", int = 0, int = 0, int = 0, int = 0,
              int = 0, double = 0, double = 0);

private: //
