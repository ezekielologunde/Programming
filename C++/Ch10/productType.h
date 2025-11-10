#include <string> // Include the string library, necessary for using the string data type.

using namespace std; // Use the standard namespace to simplify code.

class productType                           // Line 1: Begins the declaration of the class named productType.
{                                           // Line 2: Opening brace for the class definition.
public:                                     // Line 3: Access specifier: Members here are accessible from outside the class.
    productType();                          // Line 4: Default constructor prototype (takes no arguments).
    productType(int, double, double);       // Line 5: Constructor prototype that initializes quantity, price, and discount.
    productType(string, int, double, double); // Line 6: Constructor prototype that also initializes product ID.
    productType(string, string, string,     // Line 7: Full constructor prototype that initializes all data members.
                int, double, double);       // (Name, ID, Manufacturer, Quantity, Price, Discount)

    void set(string, string, string, int,   // Line 8: Function prototype to set all data members at once.
             double, double);
    void print() const;                     // Line 9: Function prototype to print all product details (const means it doesn't modify the object).

    void setQuantitiesInStock(int x);       // Line 10: Setter function to set the quantity in stock to a specific value.
    void updateQuantitiesInStock(int x);    // Line 11: Function to update the quantity (e.g., add or subtract from current stock).
    int getQuantitiesInStock() const;       // Line 12: Getter function to retrieve the current quantity in stock.

    void setPrice(double x);                // Line 13: Setter function to set the price.
    double getPrice() const;                // Line 14: Getter function to retrieve the price.
    void setDiscount(double d);             // Line 15: Setter function to set the discount rate.
    double getDiscount() const;             // Line 16: Getter function to retrieve the discount rate.
    
private:                                    // Line 17: Access specifier: Members here are only accessible within the class.
    string productName;                     // Line 18: Private data member to store the product name.
    string id;                              // Line 19: Private data member to store the product ID.
    string manufacturer;                    // Line 20: Private data member to store the product manufacturer.
    int quantitiesInStock;                  // Line 21: Private data member to store the current inventory count.
    double price;                           // Line 22: Private data member to store the price.
    double discount;                        // Line 23: Private data member to store the discount rate (e.g., 0.1 for 10%).
};                                          // Line 24: Closing brace for the class definition and semicolon.
