#include <iostream>
 
using namespace std;

// Constants representing various percentages for calculations.
const double TAX = 0.14; // Tax rate (14%)
const double CLOTHES_AND_ACC = 0.10; // Percentage of net income spent on clothes and accessories (10%)
const double SCHOOL_SUPPLIES = 0.01; // Percentage of net income spent on school supplies (1%)
const double SAVINGS_BONDS = 0.25; // Percentage of remaining net income used for savings bonds (25%)
const double PARENTS_BONDS = 0.50; // Parents' contribution to the savings bonds (50%)
  
int main()
{
    // Declare variables to store user input and calculated values.
    double payRate;
    double hoursWorkedWeek1, hoursWorkedWeek2, hoursWorkedWeek3,
           hoursWorkedWeek4, hoursWorkedWeek5;
    double totalHoursWorked;
    double totalIncome;
    double netIncome;
    double costOfClothesAndAcc;
    double costOfSchoolSupplies;
    double costOfSavingsBonds;
    double savingsBondsFromParents;

    // Prompt the user to enter their hourly pay rate.
    cout << "Enter the per hour pay rate: ";
    cin >> payRate;
    cout << endl;

    // Prompt the user to enter the hours worked for each of the five weeks.
    cout << "Enter the number of hours worked for week 1: ";
    cin >> hoursWorkedWeek1;
    cout << endl;

    cout << "Enter the number of hours worked for week 2: ";
    cin >> hoursWorkedWeek2;
    cout << endl;

    cout << "Enter the number of hours worked for week 3: ";
    cin >> hoursWorkedWeek3;
    cin >> hoursWorkedWeek4;
    cout << endl;

    cout << "Enter the number of hours worked for week 5: ";
    cin >> hoursWorkedWeek5;
    cout << endl;

    // Calculate the total hours worked over the five weeks.
    totalHoursWorked = hoursWorkedWeek1 + hoursWorkedWeek2 
                      + hoursWorkedWeek3 + hoursWorkedWeek4
                      + hoursWorkedWeek5;

    // Calculate the total income before tax.
    totalIncome = totalHoursWorked * payRate;
    
    // Calculate the net income after tax is deducted.
    netIncome = totalIncome * (1 - TAX);
    
    // Calculate the money spent on clothes and accessories from the net income.
    costOfClothesAndAcc = netIncome * CLOTHES_AND_ACC;
    
    // Calculate the money spent on school supplies from the net income.
    costOfSchoolSupplies = netIncome * SCHOOL_SUPPLIES;
    
    // Calculate the money used to buy savings bonds from the remaining net income.
    costOfSavingsBonds = (netIncome - costOfClothesAndAcc - costOfSchoolSupplies) 
                         * SAVINGS_BONDS;
    
    // Calculate the additional money for savings bonds provided by parents.
    savingsBondsFromParents = costOfSavingsBonds * PARENTS_BONDS;

    // Output a summary of all the calculated values.
    cout << "Total Income before tax: $ " << totalIncome << endl;
    cout << "Net Income: $ " << netIncome << endl;
    cout << "Money spent on clothes and other accessories: $ "
         << costOfClothesAndAcc << endl;
    cout << "Money spent on school supplies: $ "
         << costOfSchoolSupplies << endl;
    cout << "Money spent to buy savings bonds: $ "
         << costOfSavingsBonds << endl;
    cout << "Money spent by parents to buy additional savings bonds: $ "
         << savingsBondsFromParents << endl;
    
    return 0;
}
