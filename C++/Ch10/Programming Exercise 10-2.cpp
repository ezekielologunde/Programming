//Main program
    
#include <iostream> // Include the standard input/output stream library (for cin, cout).
#include <string>   // Include the string library (for using the string data type).
#include "productType.h" // Include the custom header file defining the productType class.

using namespace std; // Use the standard namespace to simplify code.

// Main function where program execution begins.
int main()
{
    // 1. Create product1 using the default constructor (all members set to default values).
    productType product1;
    
    // 2. Create product2 using the full parameterized constructor: 
    //    (Name, ID, Manufacturer, Quantity, Price, Discount).
    productType product2("Microwave", "M3562", "GeneralPool",
                         35, 175.00, 0.1);
                         
    // 3. Create product3 using a partial constructor (assuming one exists):
    //    (ID, Quantity, Price, Discount). Name and Manufacturer likely default.
    productType product3("D1290", 25, 375.00, 0.05);
    
    // 4. Create product4 using a constructor that takes only numerical data (assuming one exists):
    //    (Quantity, Price, Discount). Name and ID/Manufacturer likely default.
    productType product4(10, 8.50, 0.2);

    // Call the member function 'print' to display the details of the 'product1' object.
    product1.print();
    // Print a separator line.
    cout << "***************" << endl << endl;

    // Call the member function 'print' to display the details of the 'product2' object.
    product2.print();
    // Print a separator line.
    cout << "***************" << endl << endl;

    // Note: product3 and product4 are created but their details aren't printed in this final code block.

    // Indicate that the program finished successfully.
    return 0;
}
