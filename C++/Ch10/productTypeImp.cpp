#include <iostream> // Include the standard input/output stream library (for cout).
#include <string>   // Include the string library (for using string data type).
#include <iomanip>  // Include the I/O manipulator library (though not directly used in these definitions).
#include "productType.h" // Include the custom header file where the productType class is declared.

using namespace std; // Use the standard namespace.

// Function definition: Default constructor. Initializes all data members to safe, empty, or zero values.
productType::productType()
{
    productName = "";          // Initialize product name to an empty string.
    id = "";                   // Initialize product ID to an empty string.
    manufacturer = "";         // Initialize manufacturer to an empty string.
    quantitiesInStock = 0;     // Initialize stock quantity to zero.
    price = 0.0;               // Initialize price to zero.
    discount = 0.0;            // Initialize discount to zero.
}

// Function definition: Constructor taking only numerical values (Quantity, Price, Discount).
productType::productType(int x, double y, double z)
{
    productName = "";          // Default name to empty string.
    id = "";                   // Default ID to empty string.
    manufacturer = "";         // Default manufacturer to empty string.

    // Validate and set quantitiesInStock (must be non-negative).
    if (x >= 0)
        quantitiesInStock = x;
    else
        quantitiesInStock = 0; // Default to 0 if input is negative.

    // Validate and set price (must be non-negative).
    if (y >= 0.0)
        price = y;
    else
        price = 0.0; // Default to 0.0 if input is negative.

    // Validate and set discount (must be non-negative).
    if (z >= 0.0)
        discount = z;
    else
        discount = 0.0; // Default to 0.0 if input is negative.
}

// Function definition: Constructor taking ID and numerical values (ID, Quantity, Price, Discount).
productType::productType(string s, int x, double y, double z)
{
    productName = "";          // Default name to empty string.
    id = s;                    // Set the product ID.
    manufacturer = "";         // Default manufacturer to empty string.

    // Validate and set quantitiesInStock.
    if (x >= 0)
        quantitiesInStock = x;
    else
        quantitiesInStock = 0;

    // Validate and set price.
    if (y >= 0.0)
        price = y;
    else
        price = 0.0;

    // Validate and set discount.
    if (z >= 0.0)
        discount = z;
    else
        discount = 0.0;
}

// Function definition: Full constructor taking all data members.
productType::productType(string n, string pID, string m,
                         int x, double y, double z)
{
    productName = n;           // Set the product name.
    id = pID;                  // Set the product ID.
    manufacturer = m;          // Set the manufacturer.

    // Validate and set quantitiesInStock.
    if (x >= 0)
        quantitiesInStock = x;
    else
        quantitiesInStock = 0;

    // Validate and set price.
    if (y >= 0.0)
        price = y;
    else
        price = 0.0;

    // Validate and set discount.
    if (z >= 0.0)
        discount = z;
    else
        discount = 0.0;
}


// Function definition: Setter function to set all product data at once.
void productType::set(string n, string pID, string m,
                      int x, double y, double z)
{
    productName = n;           // Set the product name.
    id = pID;                  // Set the product ID.
    manufacturer = m;          // Set the manufacturer.

    // Validate and set quantitiesInStock.
    if (x >= 0)
        quantitiesInStock = x;
    else
        quantitiesInStock = 0;

    // Validate and set price.
    if (y >= 0.0)
        price = y;
    else
        price = 0.0;

    // Validate and set discount.
    if (z >= 0.0)
        discount = z;
    else
        discount = 0.0;
}

// Function definition: Prints all product details to the console (const).
void productType::print() const
{
    cout << "Product Name: " << productName << endl;
    cout << "Product ID: " << id << endl;
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Quantities In Stock: " << quantitiesInStock
         << endl;
    cout << "Price: " << price << endl;
    cout << "Discount: " << discount << endl;
}

// Function definition: Setter for the quantities in stock.
void productType::setQuantitiesInStock(int x)
{
    // Ensure quantity is non-negative.
    if (x >= 0)
        quantitiesInStock = x;
    else
        quantitiesInStock = 0;
}

// Function definition: Updates the quantities in stock by adding or subtracting x.
void productType::updateQuantitiesInStock(int x)
{
    quantitiesInStock = quantitiesInStock + x; // Add the change (x can be positive or negative).

    // Ensure the resulting stock quantity is never negative.
    if (quantitiesInStock < 0)
        quantitiesInStock = 0;
}

// Function definition: Getter for the quantities in stock (const).
int productType::getQuantitiesInStock() const
{
    return quantitiesInStock;
}

// Function definition: Setter for the price.
void productType::setPrice(double x)
{
    // Ensure price is non-negative.
    if (x >= 0.0)
        price = x;
    else
        price = 0;
}

// Function definition: Getter for the price (const).
double productType::getPrice() const
{
    return price;
}

// Function definition: Setter for the discount.
void productType::setDiscount(double d)
{
    // Ensure discount rate is non-negative.
    if (d >= 0.0)
        discount = d;
    else
        discount = 0;
}

// Function definition: Getter for the discount rate (const).
double productType::getDiscount() const
{
    return discount;
}
