#include <iostream>
 
using namespace std; 

int main()
{ 
    // Declare integer variables to store the number of quarters, dimes, and nickels.
    int quarters;
    int dimes;
    int nickels;

    // Declare an integer variable for the total value in pennies.
    int pennies; 

    // Prompt the user to enter the number of quarters.
    cout << "Enter the number of quarters: ";
    cin >> quarters;
    cout << endl;
 
    // Prompt for the number of dimes.
    cout << "Enter the number of dimes: ";
    cin >> dimes;
    cout << endl;

    // Prompt for the number of nickels.
    cout << "Enter the number of nickels: ";
    cin >> nickels;
    cout << endl;

    // Calculate the total value in pennies by converting each coin type and summing them.
    pennies = quarters * 25 + dimes * 10 + nickels * 5;

    // Output the total value in pennies to the console.
    cout << "The change in pennies = " << pennies << endl;

    return 0;
}
