#include <iostream>   // For input/output stream operations
#include <iomanip>    // For output formatting (like setprecision)
#include "houseType.h" // Include the corresponding header file for class definition

using namespace std;

//************************************************************
// Constructor
// Initializes a houseType object with all its property details
//************************************************************
houseType::houseType(string style, int numOfBedrooms, int numOfBathrooms,
                     int numOfFloors, int yearBuilt, int garageSize,
                     double price, double taxRate)
{
    // Assign constructor parameters to member variables
    this->style = style;
    this->numOfBedrooms = numOfBedrooms;
    this->numOfBathrooms = numOfBathrooms;
    this->numOfFloors = numOfFloors;
    this->yearBuilt = yearBuilt;
    this->garageSize = garageSize;
    this->price = price;
    this->taxRate = taxRate;
}

//************************************************************
// print
// Displays formatted details about the house
//************************************************************
void houseType::print() const
{
    cout << fixed << showpoint << setprecision(2); // Format numbers with 2 decimal places

    cout << "Style: " << style << endl;
    cout << "Bedrooms: " << numOfBedrooms << endl;
    cout << "Bathrooms: " << numOfBathrooms << endl;
    cout << "Floors: " << numOfFloors << endl;
    cout << "Year Built: " << yearBuilt << endl;
    cout << "Garage Size: " << garageSize << endl;
    cout << "Price: $" << price << endl;

    // Calculate and display the annual property tax
    cout << "Annual Tax: $" << price * taxRate << endl;
}

//************************************************************
// Destructor
// Automatically called when a houseType object goes out of scope.
// Currently, it doesn’t need to release any resources.
//************************************************************
houseType::~houseType()
{
    // No dynamic memory to free — empty body is fine
}
