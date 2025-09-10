#include <iostream>

using namespace std;
 
// Constant for the volume of a single milk carton in liters.
const double CARTON_CAPACITY = 3.78;
 
int main()
{
    // Declare variables for user input.
    double milkQuantity;
    double costOfOneLiter;
    double profitOnACarton; 
    
    // Declare variables for the calculated values.
    int noOfMilkCartons;
    double totalCostOfMilk;
    double profit;

    // Prompt for the total quantity of milk produced.
    cout << "Enter, in liters, the total quantity of the milk produced: ";
    cin >> milkQuantity;
    cout << endl;

    // Prompt for the cost of one liter of milk.
    cout << "Enter the cost of producing one liter of milk: ";
    cin >> costOfOneLiter;
    cout << endl;

    // Prompt for the profit on each carton.
    cout << "Enter the profit on each carton of milk: ";
    cin >> profitOnACarton;
    cout << endl;

    // Calculate the number of cartons needed, rounding to the nearest integer.
    noOfMilkCartons = static_cast<int>(milkQuantity / CARTON_CAPACITY + 0.5);
    
    // Calculate the total production cost.
    totalCostOfMilk = milkQuantity * costOfOneLiter;
    
    // Calculate the total profit.
    profit = noOfMilkCartons * profitOnACarton;

    // Output the calculated number of cartons.
    cout << "The number of milk cartons needed to hold the milk: " 
         << noOfMilkCartons << endl;

    // Output the total cost of production.
    cout << "The cost of producing the milk: $" 
         << totalCostOfMilk << endl;

    // Output the total profit.
    cout << "Profit: $" 
         << profit << endl;

    return 0;
}
