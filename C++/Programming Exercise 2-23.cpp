#include <iostream>
 
using namespace std; 

// Constant representing the service charge rate (1.5% or 0.015).
const double SERVICE_CHARGES = 0.015;
 
int main() 
{
    // Declare variables for stock prices and number of shares.
    double stockBuyPricePerShare;
    double stockSellPricePerShare;
    int sharesSold;

    // Declare variables for calculated prices and charges.
    double stockPurchasePrice;
    double stockSellPrice;
    double serviceChargesBuy;
    double serviceChargesSell;

    // Prompt the user for the buying price of each share.
    cout << "Enter the buying price of each share: ";
    cin >> stockBuyPricePerShare;
    cout << endl;

    // Prompt for the selling price of each share.
    cout << "Enter the selling price of each share: ";
    cin >> stockSellPricePerShare;
    cout << endl;

    // Prompt for the number of shares sold.
    cout << "Enter the number of shares sold: ";
    cin >> sharesSold;
    cout << endl;

    // Calculate the service charges for buying and selling.
    serviceChargesBuy = stockBuyPricePerShare * sharesSold * SERVICE_CHARGES;
    serviceChargesSell = stockSellPricePerShare * sharesSold * SERVICE_CHARGES;

    // Calculate the total purchase price (including service charges).
    stockPurchasePrice = stockBuyPricePerShare * sharesSold + serviceChargesBuy;
    
    // Calculate the total amount received from the sale (after deducting service charges).
    stockSellPrice = stockSellPricePerShare * sharesSold - serviceChargesSell;

    // Output a summary of the investment.
    cout << "Total amount invested: $ " << stockPurchasePrice << endl; 
    cout << "Total amount received: $ " << stockSellPrice << endl; 
    cout << "Total service charges: $ " 
         << (serviceChargesBuy + serviceChargesSell) << endl;

    // Output the amount gained or lost from the transaction.
    cout << "Amount gained or lost: $" 
         << (stockSellPrice - stockPurchasePrice) << endl;
    
    return 0;
}
