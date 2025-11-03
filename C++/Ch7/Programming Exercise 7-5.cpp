#include <iostream> // Needed for standard input/output (like 'cin' and 'cout')
#include <iomanip>  // Needed for formatting output (like 'setprecision')

using namespace std; // Allows us to use standard names like 'cout' and 'endl'

// --- Global Constants for Tax Calculations ---
const double MARRIED_DEDUCTION = 7000.00; // Standard deduction for married status
const double SINGLE_DEDUCTION = 4000.00;  // Standard deduction for single status
const double PERSONAL_EXECPTION = 1500.00; // Amount deducted per person/child

// --- Function Prototypes ---

// Function to get user data. Variables are passed by reference (&) so they can be modified.
void getData(char& mStatus, int& nOfChildren, double& salary,
            double& pContribPension);

// Function to calculate the final tax amount
double taxAmount(char mStatus, int nOfChildren, double salary,
                double pContribPension);

int main()
{
    // Variables to store user input
    char maritalStatus;
    int numberOfChildren;
    double grossSalary;
    double pContributedToPension;

    // --- Output Formatting ---
    cout << fixed << showpoint; // Ensures decimal points are always shown
    cout << setprecision(2);    // Sets output to two decimal places (currency format)

    // Call the function to get all necessary data from the user
    getData(maritalStatus, numberOfChildren,
            grossSalary, pContributedToPension);

    cout << endl;
    // Calculate and print the final tax amount by calling the taxAmount function
    cout << "Your tax for the year is: "
         << taxAmount(maritalStatus, numberOfChildren,
                      grossSalary, pContributedToPension)
         << endl;

    return 0; // Signals successful execution
}

// --- Function to get input data from the user ---
// All parameters are passed by reference (&) to store the input values in main's variables.
void getData(char& mStatus, int& nOfChildren, double& salary,
             double& pContribPension)
{
    // Get marital status
    cout << "Enter marital status: m or M (married), s or S (single): ";
    cin >> mStatus;
    cout << endl;

    // Only prompt for children if the status is married
    if (mStatus == 'm' || mStatus == 'M')
    {
        cout << "Enter number of children under the age of 14: ";
        cin >> nOfChildren;
        cout << endl;
    }

    // Get annual gross salary
    cout << "Enter gross salary for the year: ";
    cin >> salary;
    cout << endl;

    // Get pension contribution percentage
    cout << "Enter percentage of salary contributed to pension (0-6 percent): ";
    cin >> pContribPension;
    cout << endl;
}

// --- Function to calculate the final tax amount ---
double taxAmount(char mStatus, int nOfChildren, double salary,
                 double pContribPension)
{
    double taxableAmount;      // The amount of income that is actually taxed
    double sDeduction;         // The standard deduction (Single or Married)
    double tax;                // The final calculated tax

    int numberOfDeduction;     // Total number of personal exemptions

    // --- Determine Standard Deduction and Exemptions ---
    if (mStatus == 'm' || mStatus == 'M')
    {
        // Married: 2 adults + n children
        numberOfDeduction = 2 + nOfChildren;
        sDeduction = MARRIED_DEDUCTION;
    }
    else
    {
        // Single: 1 adult
        numberOfDeduction = 1;
        sDeduction = SINGLE_DEDUCTION;
    }

    // --- Calculate Taxable Income ---
    taxableAmount = salary
                    - sDeduction                               // Subtract standard deduction
                    - PERSONAL_EXECPTION * numberOfDeduction   // Subtract personal exemptions
                    - salary * pContribPension / 100;          // Subtract pension contribution

    // Taxable income cannot be negative
    if (taxableAmount < 0)
        taxableAmount = 0;

    // --- Apply Progressive Tax Brackets (using 'if-else if-else') ---

    // Bracket 1: 15% tax rate (for income up to $15,000)
    if (0 <= taxableAmount && taxableAmount <= 15000)
        tax = taxableAmount * .15;

    // Bracket 2: 25% tax rate (for income from $15,001 to $40,000)
    else if (15001 <= taxableAmount && taxableAmount <= 40000)
        // Tax is $2250 (max of bracket 1) PLUS 25% of the income OVER $15,000
        tax = 2250 + (taxableAmount - 15000) * .25;

    // Bracket 3: 35% tax rate (for income over $40,000)
    else // taxableAmount > 40000
        // Tax is $8460 (max of bracket 2) PLUS 35% of the income OVER $40,000
        tax = 8460 + (taxableAmount - 40000) * .35;

    return tax; // Return the final calculated tax
}
