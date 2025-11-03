#include <iostream>

using namespace std;

int main()
{
    // Declare variables to store user input.
    double purchasingPrice;
    double minAmtToBeAddedToPurchPrice;
    double maxAmtToBeAddedToPurchPrice;
    double fixedCommission;
    double comissionAsaPercentage;
    
    // Declare variables for the calculated commission range.
    double salesPersonMinCommission;
    double salesPersonMaxCommission;
            
    // Prompt the user for the purchasing price of the car.
    cout << "Enter the purchasing price of the car: ";
    cin >> purchasingPrice;
    cout << endl;

    // Prompt for the minimum amount to add to the purchasing price.
    cout << "Enter the minimum amount to be added to purchasing price of the car: ";
    cin >> minAmtToBeAddedToPurchPrice;
    cout << endl;

    // Prompt for the maximum amount to add to the purchasing price.
    cout << "Enter the maximum amount to be added to purchasing price of the car: ";
    cin >> maxAmtToBeAddedToPurchPrice;
    cout << endl;

    // Prompt for the salesperson's fixed commission.
    cout << "Enter sales person's fixed comission: ";
    cin >> fixedCommission;
    cout << endl;

    // Prompt for the commission percentage.
    cout << "Enter the percentage of the commision: ";
    cin >> comissionAsaPercentage;
    cout << endl;

    // Calculate the minimum and maximum commissions. The excess of the selling price over the
    // cost is `minAmtToBeAddedToPurchPrice` and `maxAmtToBeAddedToPurchPrice`, respectively.
    salesPersonMinCommission = fixedCommission + comissionAsaPercentage * minAmtToBeAddedToPurchPrice / 100;
    salesPersonMaxCommission = fixedCommission + comissionAsaPercentage * maxAmtToBeAddedToPurchPrice / 100;

    // Output the minimum and maximum selling prices.
    cout << "Car's minimum selling price: $" << purchasingPrice + minAmtToBeAddedToPurchPrice << endl;
    cout << "Car's maximum selling price: $" << purchasingPrice + maxAmtToBeAddedToPurchPrice << endl;
    
    // Output the calculated commission range.
    cout << "Sales person's commision range: $" << salesPersonMinCommission << " to $"
        << salesPersonMaxCommission << endl;

    return 0;
}
