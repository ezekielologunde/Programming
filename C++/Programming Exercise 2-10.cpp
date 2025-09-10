#include <iostream>
 
using namespace std;
 
int main() {
    // Declare five double variables to store the user's decimal inputs.
    double dec1, dec2, dec3, dec4, dec5; 

    // Declare an integer variable to store the final rounded sum.
    int num;

    // Prompt the user to enter five decimal numbers.
    cout << "Enter five decimal numbers: ";
    cin >> dec1 >> dec2 >> dec3 >> dec4 >> dec5;

    // Calculate the sum of the five numbers.
    // The expression `+ 0.5` and `static_cast<int>` is a common
    // method to round a floating-point number to the nearest integer.
    num = static_cast<int>(dec1 + dec2 + dec3 + dec4 + dec5 + 0.5);

    // Output the final rounded sum to the console.
    cout << "The sum of the numbers to the nearest integer = " 
         << num << endl;

    return 0; 
}
