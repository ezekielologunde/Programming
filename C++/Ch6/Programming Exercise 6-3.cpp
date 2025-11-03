#include <iostream> // Needed for standard input/output operations (like 'cout' and 'cin')
  
using namespace std; // Allows us to use standard names like 'cout' and 'endl'

// Function prototype: Declares a function that returns true if a character is a vowel
bool isVowel(char ch);

int main() 
{
    char ch; // Variable to store the character currently being read
    int numberOfVowels = 0; // Counter for the total number of vowels found

    cout << "Enter a sentence." << endl;

    // Reads the very first character from the input stream
    cin.get(ch);
    
    // Loop continues as long as the character read is NOT a newline ('\n', which marks the end of the input line)
    while (ch != '\n')
    {
        // Check if the current character is a vowel
        if (isVowel(ch))
            // If it is, increment the counter
            numberOfVowels++;

        // Read the next character from the input stream; this is what controls the loop
        cin.get(ch);
    }

    // Print the final count of vowels
    cout << "There are " << numberOfVowels 
         << " vowels in this sentence." << endl;
         
    return 0; // Signals successful execution
}


// --- Function to check if a character is a vowel ---
bool isVowel(char ch)
{
    // Uses a switch statement for efficient checking against multiple fixed values
    switch (ch)
    {
    // Handles all uppercase vowels
    case 'A': 
    case 'E': 
    case 'I': 
    case 'O': 
    case 'U':
    // Handles all lowercase vowels
    case 'a': 
    case 'e': 
    case 'i': 
    case 'o': 
    case 'u': 
        return true; // If a match is found
    default: 
        return false; // If no match is found
    }
}
