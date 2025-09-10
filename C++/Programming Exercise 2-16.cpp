#include <iostream>
 
using namespace std;

// Constant for the volume of a single milk carton in liters.
const double CARTON_CAPACITY = 3.78;
// Constant for the production cost of one liter of milk.
const double COST_OF_ONE_LITER = 0.38;
// Constant for the profit earned from one carton of milk.
const double PROFIT_ON_A_CARTON = 0.27;
   
int main()  
{
    // Declare a double to store the total quantity of milk produced.
    double milkQuantity; 
    // Declare an integer to store the calculated number of cartons.
    int noOfMilkCartons;
    // Declare doubles to store the total cost and profit.
    double totalCostOfMilk;
    double profit;

    // Prompt the user for the total milk quantity produced.
    cout << "Enter, in liters, the total quantity of milk produced: ";
    cin >> milkQuantity;
    cout << endl;

    // Calculate the number of cartons needed, rounding to the nearest integer.
    // The `+ 0.5` and `static_cast<int>` method is used for rounding.
    noOfMilkCartons = static_cast<int>(milkQuantity / CARTON_CAPACITY + 0.5);
    
    // Calculate the total production cost based on the quantity of milk.
    totalCostOfMilk = milkQuantity * COST_OF_ONE_LITER;
    
    // Calculate the total profit based on the number of cartons.
    profit = noOfMilkCartons * PROFIT_ON_A_CARTON;

    // Output the number of milk cartons needed.
    cout << "The number of milk cartons needed to hold milk: " 
         << noOfMilkCartons << endl;

    // Output the total cost of producing the milk.
    cout << "The cost of producing milk: $" 
         << totalCostOfMilk << endl;

    // Output the total profit.
    cout << "Profit: $" 
         << profit << endl;

    return 0;
}
