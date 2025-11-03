#include <iostream> // Needed for standard input/output (like 'cin' and 'cout')
#include <string>   // Needed for using the string data type

using namespace std; // Allows us to use standard names like 'cout' and 'string'

// --- Function Prototypes ---
// Declares a function to remove all vowels from the string passed by reference (&)
void removeVowels(string& str);
// Declares a helper function to check if a character is a vowel
bool isVowel(char ch);

int main()
{
    string str; // Variable to hold the user's input string

    // Prompt the user for input
    cout << "Enter a string: ";
    // Reads a single word (stops at the first space) into the string variable
    cin >> str;
    cout << endl;

    // Show the string before modification
    cout << "Before removing vowels: " << str << endl;

    // Call the function to modify the string, passing it by reference
    removeVowels(str);

    // Show the string after modification
    cout << "Afer removing vowels: " << str << endl;

    return 0; // Signals successful execution
}

// --- Function to remove vowels from the string ---
// The ampersand (&) means 'str' is passed by reference, so changes made here
// directly modify the original string in the 'main' function.
void removeVowels(string& str)
{
    int len = str.length(); // Get the initial length of the string
    int index = 0;          // Loop control variable, starts at the first character

    // Loop continues as long as the index hasn't gone past the current end of the string
    while (index < len)
    {
        // Check if the character at the current index is a vowel
        if (isVowel(str[index]))
        {
            // --- Vowel Removal Logic ---
            // Replaces the string with a combination of two substrings:
            // 1. str.substr(0, index): Everything BEFORE the vowel
            // 2. str.substr(index + 1, str.length()): Everything AFTER the vowel
            str = str.substr(0, index) + str.substr(index + 1, str.length());

            // The length changes when a character is removed, so 'len' must be updated.
            // Since the vowel was removed, we DON'T increment 'index' here.
            // The next character to check is now at the SAME 'index' position.
            len = str.length();
        }
        else
            // If it's a consonant (or other character), move to the next character
            index++;
    }
}

// --- Helper Function to check if a character is a vowel ---
bool isVowel(char ch)
{
    // Uses a switch statement to check for all upper and lowercase vowels
    switch (ch)
    {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':
        return true; // It's a vowel
    default:
        return false; // It's not a vowel
    }
}
