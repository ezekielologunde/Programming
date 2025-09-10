#include <iostream>

using namespace std;

// This constant defines the weight of one metric ton in pounds.
const int POUNDS_IN_METRIC_TON = 2205; 
 
int main() 
{
    // Declare an integer variable to store the amount of rice a single bag holds.
    int amountOfRice;

    // Prompt the user to enter the amount of rice in a bag.
    cout << "Enter the amount of rice, in pounds, in a bag: ";
    cin >> amountOfRice;
    cout << endl;

    // Output the number of bags needed by dividing the total pounds in a metric ton
    // by the amount of rice in a single bag.
    cout << "The number of bags needed to fill a "
         << "metric ton of rice is approximately " 
         << POUNDS_IN_METRIC_TON / amountOfRice << endl;

    return 0;
}
