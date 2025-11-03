#include <iostream> // Needed for input/output operations (like 'cin' and 'cout')
#include <iomanip>  // Needed for formatting output (like 'setprecision')

using namespace std; // Allows us to use standard names like 'cout' and 'endl'

// --- Defines a namespace to group related constant values (royalty rates) ---
namespace royaltyRates
{
    // Constants for Option 1: a fixed payment
    const double OPTION_1_DOWN_PAY = 5000;    // Initial payment
    const double OPTION_1_BOOK_DEL_PAY = 20000; // Payment upon delivery

    // Constant for Option 2: a single percentage royalty rate
    const double OPTION_2_ROYALTY_RATE = 0.125; // 12.5% of net sales

    // Constants for Option 3: a tiered percentage royalty rate
    const double OPTION_3_ROYALTY_RATE_1 = 0.10; // 10% for the first 4000 copies
    const double OPTION_3_ROYALTY_RATE_2 = 0.14; // 14% for copies over 4000
}

// Brings all names from the 'royaltyRates' namespace into the program's scope
using namespace royaltyRates;

int main()
{
    // Variables to store user input
    int numberOfCopiesSold;
    double netPriceOfABook;

    // Variables to track the best option found so far
    int bestOption = 0;
    double bestRoyalty = 0;

    // Variables to store the calculated royalty for each option
    double royaltyOption1;
    double royaltyOption2;
    double royaltyOption3;

    // --- Output Formatting ---
    cout << fixed << showpoint; // Forces decimal point and trailing zeros
    cout << setprecision(2);    // Sets the output to display exactly 2 decimal places (for currency)

    // --- User Input ---
    cout << "Enter the num of copies sold: ";
    cin >> numberOfCopiesSold;
    cout << endl;

    cout << "Enter the net price of one book: ";
    cin >> netPriceOfABook;
    cout << endl;

    // --- Royalty Calculation ---

    // Option 1: Total fixed payment (sum of the two fixed amounts)
    royaltyOption1 = OPTION_1_DOWN_PAY + OPTION_1_BOOK_DEL_PAY;

    // Option 2: Percentage of total net sales (copies * price * rate)
    royaltyOption2 = numberOfCopiesSold * netPriceOfABook * OPTION_2_ROYALTY_RATE;

    // Option 3: Tiered royalty calculation
    if (numberOfCopiesSold <= 4000)
        // If 4000 or fewer copies sold, use the lower 10% rate
        royaltyOption3 = numberOfCopiesSold * netPriceOfABook * OPTION_3_ROYALTY_RATE_1;
    else
        // If more than 4000 copies sold, use a mix of rates:
        royaltyOption3 = 4000 * netPriceOfABook * OPTION_3_ROYALTY_RATE_1  // 10% for the first 4000 copies
                        + (numberOfCopiesSold - 4000)  * netPriceOfABook * OPTION_3_ROYALTY_RATE_2; // 14% for copies above 4000

    // --- Find the Best Option (Comparison) ---

    // Assume Option 1 is the best starting point
    bestOption = 1;
    bestRoyalty = royaltyOption1;

    // Check if Option 2 is better than the current best
    if (bestRoyalty < royaltyOption2)
    {
        bestOption = 2;
        bestRoyalty = royaltyOption2;
    }

    // Check if Option 3 is better than the current best
    if (bestRoyalty < royaltyOption3)
    {
        bestOption = 3;
        bestRoyalty = royaltyOption3;
    }

    // --- Print Final Result (Handle Ties) ---

    // If Option 1 was the highest (or tied for the highest)
    if (bestOption == 1)
    {
        if (royaltyOption1 == royaltyOption2)
            if (royaltyOption1 == royaltyOption3)
                // Case: Option 1 = Option 2 = Option 3
                cout << "All three options are the same and the royalty is: "
                     << bestRoyalty << endl;
            else
                // Case: Option 1 = Option 2 > Option 3
                cout << "Options 1 and 2 are the same and give the best royalty, which is: "
                     << bestRoyalty << endl;
        else if (royaltyOption1 == royaltyOption3)
            // Case: Option 1 = Option 3 > Option 2
            cout << "Options 1 and 3 are the same and give the best royalty, which is: "
                 << bestRoyalty << endl;
        else
            // Case: Option 1 > Option 2 and Option 1 > Option 3
            cout << "Option 1 is the best and the royalty is: "
                 << bestRoyalty << endl;
    }
    // If Option 2 was the highest (but Option 1 wasn't)
    else if (bestOption == 2)
    {
        if (royaltyOption2 == royaltyOption3)
            // Case: Option 2 = Option 3 > Option 1
            cout << "Options 2 and 3 are the same and give the best royalty, which is: "
                 << bestRoyalty << endl;
        else
            // Case: Option 2 > Option 1 and Option 2 > Option 3
            cout << "Option 2 is the best and the royalty is: "
                 << bestRoyalty << endl;
    }
    // If Option 3 was the highest (and neither Option 1 nor 2 was better)
    else
        // Case: Option 3 > Option 1 and Option 3 > Option 2
        cout << "Option 3 is the best and the royalty is: "
             << bestRoyalty << endl;

    // --- Display Calculated Royalties for Comparison ---
    cout << "Royalty option1: " << royaltyOption1 << endl;
    cout << "Royalty option2: " << royaltyOption2 << endl;
    cout << "Royalty option3: " << royaltyOption3 << endl;

    return 0; // Signals successful execution
}
