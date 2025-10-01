#include <iostream>
#include <string>

using namespace std;
 
int main()
{
    // letter: Used to hold the current character being processed.
    char letter;
    // noOfLetters: Counter to track how many letters have been processed (up to 7).
    int noOfLetters;
    // response: User input to continue or terminate the program.
    char response;
    // A string to hold the entire 7-letter input sequence from the user.
    string telLetters; 

    // Prompt the user to start the program.
    cout << "Enter Y/y to convert a telephone number " 
         << "form letters to digits.\n"
         << "Enter any other letter to terminate the program." << endl;

    // Read the user's initial response.
    cin >> response;

    // Main loop: continues as long as the user enters 'Y' or 'y'.
    while (response == 'Y' || response == 'y')
    {
        // Prompt the user to enter the letter-based telephone number.
        cout << "Enter a telephone number using letters (e.g., PHONESZ): ";
        // FIX: Read the entire letter sequence as a string into telLetters.
        cin >> telLetters;
        cout << endl;

        // Initialize the counter for the letters processed.
        noOfLetters = 0;

        // Output header for the result.
        cout << "The corresponding telephone number is: \n";

        // Loop 7 times to process the first 7 characters of the input string.
        while (noOfLetters < 7)
        {
            // Increment the letter counter.
            noOfLetters++;
            
            // FIX: Get the character at the current index from the input string.
            // If the input is shorter than 7 characters, this will access invalid memory!
            // A more robust solution would check telLetters.length().
            letter = telLetters[noOfLetters - 1]; 

            // Switch statement to map the character to its corresponding digit.
            switch (letter)
            {
            case 'a': case 'b': case 'c': // Fall-through cases for lowercase 'a' to 'c'.
            case 'A': case 'B': case 'C': // Fall-through cases for uppercase 'A' to 'C'.
                cout << '2'; 
                break;
            case 'd': case 'e': case 'f': // Cases for 'd', 'e', 'f'.
            case 'D': case 'E': case 'F': 
                cout << '3';
                break;
            case 'g': case 'h': case 'i': // Cases for 'g', 'h', 'i'.
            case 'G': case 'H': case 'I': 
                cout << '4';
                break;
            case 'j': case 'k': case 'l': // Cases for 'j', 'k', 'l'.
            case 'J': case 'K': case 'L': 
                cout << '5';
                break;
            case 'm': case 'n': case 'o': // Cases for 'm', 'n', 'o'.
            case 'M': case 'N': case 'O': 
                cout << '6';
                break;
            case 'p': case 'q': case 'r': case 's': // Cases for the 4-letter group 'p' through 's' (digit 7).
            case 'P': case 'Q': case 'R': case 'S': 
                cout << '7';
                break;
            case 't': case 'u': case 'v': // Cases for 't', 'u', 'v'.
            case 'T': case 'U': case 'V': 
                cout << '8';
                break;
            case 'w': case 'x': case 'y': case 'z': // Cases for the 4-letter group 'w' through 'z' (digit 9).
            case 'W': case 'X': case 'Y': case 'Z': 
                cout << '9';
                break;
            // Add a default case to handle non-letter characters like '1', '0', or other symbols.
            default:
                cout << letter; // Just print the character as is.
            }
            // Insert the standard telephone number separator after the 3rd digit.
            if (noOfLetters == 3)
                cout << '-';
            // REMOVED: The original code had 'cin >> letter;' here, which was wrong.
            // It attempted to read the next letter inside the switch's loop,
            // but the outer 'cin >> letter;' only read the *first* letter.
        }
        
        // Clear any remaining input characters from the buffer (important after reading a string).
        cin.ignore(100, '\n');

        // Prompt the user to process another number or terminate.
        cout << "\nTo process another telephone number, enter Y/y \n"
             << "Enter any other letter to terminate the program." << endl;
        // Read the user's response to continue or quit.
        cin >> response;
        cout << endl;
    }//end while
    return 0; // Standard practice to explicitly return 0 at the end of main.
}
