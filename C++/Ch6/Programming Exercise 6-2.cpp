#include <iostream> // Needed for standard input/output operations (like 'cout' and 'cin')
   
using namespace std; // Allows us to use standard names like 'cout' and 'endl'

// Function prototype: Declares a function that returns true if a character is a vowel
bool isVowel(char ch);

int main()
{
    char ch; // Variable to store the single character input by the user

    // Prompt the user for input
    cout << "Enter a character: ";
    cin >> ch; // Read the character
    cout << endl;

    // Call the isVowel function and print the result.
    // The output will be 1 (true) or 0 (false) since 'bool' is often printed as an integer.
    cout << ch << " is a vowel: " << isVowel(ch) << endl;

    return 0; // Signals successful execution
}

// --- Function to check if a character is a vowel ---
bool isVowel(char ch)
{
    // Uses a switch statement to compare the input character against a list of possible values
    switch (ch)
    {
    // These cases handle all uppercase vowels (A, E, I, O, U)
    case 'A': 
    case 'E': 
    case 'I': 
    case 'O': 
    case 'U':
    // These cases handle all lowercase vowels (a, e, i, o, u)
    case 'a': 
    case 'e': 
    case 'i': 
    case 'o': 
    case 'u': 
        // If the character matches any of the above cases, return true
        return true;
        
    default: 
        // If the character does not match any vowel, return false
        return false;
    }
    // Note: Since 'return' is used in each case group, a 'break' is not required.
}
