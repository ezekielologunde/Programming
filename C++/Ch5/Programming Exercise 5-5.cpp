#include <iostream> // Include the input/output stream library for console operations.

using namespace std; // Use the standard namespace to avoid typing std:: everywhere.
 
int main ()
{   
    int num1, num2; // Variables to store the two integer inputs from the user.
    int multiple3Count = 0; // Counter for numbers divisible by 3. Initialized to 0.
    int multiple5Count = 0; // Counter for numbers divisible by 5. Initialized to 0.
    int temp; // Temporary variable used for swapping and loop iteration.
                
    // Prompt the user to enter two integers.
    cout << "Enter two integers: ";
    // Read the two integers into num1 and num2.
    cin >> num1 >> num2;
    cout << endl;

    // Check if the second number is smaller than the first.
    if (num2 < num1)
    {
        // Swap num1 and num2 so that num1 is the smaller number (start of the range).
        temp = num2; // Store the smaller value (num2) temporarily.
        num2 = num1; // Assign the larger value (num1) to num2.
        num1 = temp; // Assign the smaller value (stored in temp) to num1.
    }

    // Initialize the loop counter 'temp' with the smaller number (num1).
    temp = num1;
    // Loop through every integer from num1 (inclusive) up to num2 (inclusive).
    while (temp <= num2)
    {
        // Check if the current number is a multiple of 3 (remainder is 0).
        if (temp % 3 == 0)
            // Increment the multiple of 3 counter.
            multiple3Count++;

        // Check if the current number is a multiple of 5 (remainder is 0).
        if (temp % 5 == 0)
            // Increment the multiple of 5 counter.
            multiple5Count++;
        // Move to the next integer in the range.
        temp++;
    }

    // Output the final count of multiples of 3 found in the range.
    cout << "Multiples of 3 between " << num1 
         << " and " << num2 << ": " << multiple3Count << endl;
    // Output the final count of multiples of 5 found in the range.
    cout << "Multiples of 5 between " << num1
         << " and " << num2 << ": " << multiple5Count << endl;

    // Indicate that the program finished successfully.
    return 0;
}
