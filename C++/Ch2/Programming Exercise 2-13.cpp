#include <iostream>

using namespace std; 

int main() 
{ 
    // Declare variables to store the various price components.
    double originalPrice;
    double markedUpPercentage;
    double salesTaxRate;
    double sellingPrice;  
    double salesTax;
    double finalPrice;

    // Prompt the user to enter the original price of the item.
    cout << "Enter the original price of the item: ";
    cin >> originalPrice;
    cout << endl;

    // Prompt for the marked-up percentage.
    cout << "Enter the marked up percentage: ";
    cin >> markedUpPercentage;
    cout << endl;

    // Prompt for the sales tax rate.
    cout << "Enter the sales tax rate: ";
    cin >> salesTaxRate;
    cout << endl;

    // Calculate the selling price by adding the marked-up amount.
    sellingPrice = originalPrice + originalPrice * markedUpPercentage / 100;
    
    // Calculate the sales tax based on the selling price.
    salesTax = sellingPrice * salesTaxRate / 100;
    
    // Calculate the final price by adding the sales tax to the selling price.
    finalPrice = sellingPrice + salesTax;

    // Output a summary of all the calculated values.
    cout << "The original price = $" << originalPrice << endl;
    cout << "The price is marked up by " << markedUpPercentage 
         << "%" << endl;
    cout << "The selling price = $" << sellingPrice << endl;
    cout << "The sales rate = " << salesTaxRate << "%" << endl;
    cout << "The sales tax = $" << salesTax << endl;
    cout << "The final price = $" << finalPrice << endl;

    return 0;
}
