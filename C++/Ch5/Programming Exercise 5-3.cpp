#include <iostream>

using namespace std;

int main()
{
    char letter; // Variable to store the letter input by the user.
    int digit, num; // digit stores the telephone number; num stores the letter's 0-25 index.

    // Output program title and purpose.
    cout << "Program to convert letters to their "
         << "corresponding telephone digits."
         << endl;

    // Instructions for the user to stop the program.
    cout << "To stop the program enter #." << endl;

    // Initial prompt and input read.
    cout << "Enter a letter: ";
    cin >> letter;
    cout << endl;

    // Start of the main processing loop; continues until '#' is entered.
    while (letter != '#')
    {
        // Display the input letter and prepare to output the digit.
        cout << "Letter: " << letter;
        cout << ", Corresponding telephone digit: ";

        // Calculate 0-based index: 'A'=0, 'B'=1, ..., 'Z'=25.
        num = static_cast<int>(letter) - static_cast<int>('A');
        // Handle lowercase letters by normalizing their index (e.g., 'a' is 32 positions from 'A').
        if (num > 25)
            num = num - 32;

        // Check if the input is a valid uppercase or lowercase letter (0 <= num <= 25).
        if ((0 <= num && num <= 25)) // ||  (32 <= num && num <= 57))
        {
            // Standard telephone mapping: (Index / 3) + 2 (e.g., 0/3 + 2 = 2).
            digit = (num / 3) + 2;

            // Correction for 4-letter keys (7 and 9) where the standard formula is off (e.g., 'S').
            if (((num / 3 == 6) || (num / 3 == 7)) && (num % 3 == 0))
                digit = digit - 1;

            // Ensures the final digit doesn't exceed 9 (handles 'Z' which calculates to 10).
            if (digit > 9)
                digit = 9;

            // Output the calculated digit.
            cout << digit << endl;
        }
        else
            // Output for non-letter input.
            cout << "Invalid input." << endl;

        // Reprompt for the next input, providing instructions again.
        cout << "\nEnter another uppercase "
             << "letter to find its corresponding "
             << "telephone digit." << endl;
        cout << "To stop the program enter #."
             << endl;

        // Get the next input from the user.
        cout << "Enter a letter: ";
        cin >> letter;
        cout << endl;
    } // end while

    // Program exit.
    return 0;
}
