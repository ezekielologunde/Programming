#include <iostream>
#include <string>
 
using namespace std;

// Named constant for a secret integer value, used in a calculation.
const int SECRET = 11;
// Named constant for a pay rate, used to calculate wages.
const double RATE = 12.50;  
 
int main() 
{
    // Declare integer variables for calculations.
    int num1, num2, newNum;

    // Declare a string variable to hold a name.
    string name;

    // Declare double variables for hours and wages, to handle currency/decimals.
    double hoursWorked, wages;

    // Prompt the user to enter two integers and store them.
    cout << "Enter two integers separated by a space: ";
    cin >> num1 >> num2; 
    cout << endl;

    // Output the values of the two integers that were entered.
    cout << "The value of num1 = " << num1 
         << " and the value of num2 = " << num2
         << "." << endl;

    // Calculate a new integer value based on num1 and num2.
    newNum = 2 * num1 + num2;

    // Output the initial calculated value of newNum.
    cout << "The value of newNum = " << newNum << endl;

    // Update newNum by adding the value of the SECRET constant.
    newNum = newNum + SECRET;

    // Output the new, updated value of newNum.
    cout << "The new value of newNum = " << newNum << endl;

    // Prompt the user to enter a last name and store it.
    cout << "Enter last name: " ;
    cin >> name;
    cout << endl;

    // Prompt for and store the number of hours worked.
    cout << "Enter a decimal number between 0 and 70: " ;
    cin >> hoursWorked;
    cout << endl;

    // Calculate the total wages by multiplying hours worked by the fixed rate.
    wages = hoursWorked * RATE;

    // Output a summary of the user's information and calculated salary.
    cout << "Name: " << name << endl;
    cout << "Pay Rate: $" << RATE << endl;
    cout << "Hours Worked: " << hoursWorked << endl;
    cout << "Salary: $" << wages << endl;

    return 0;
}
