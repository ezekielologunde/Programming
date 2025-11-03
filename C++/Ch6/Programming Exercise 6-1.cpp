#include <iostream> // Needed for standard input/output (like 'cout')
#include <string>   // Needed for using the string data type
#include <cmath>    // This header is included, but not strictly needed for this code
   
using namespace std; // Allows us to use standard names like 'cout' and 'string'

// Function prototype: Declares a function to check if a string is a palindrome
bool isPalindrome(string str);

int main()
{
    // --- Test Cases ---

    // Test Case 1: "Madam" (Should be a palindrome)
    if (isPalindrome("Madam"))
        cout << "Madam" << " is a palindrome." << endl;
    else
        cout << "Madam" << " is not a palindrome." << endl;

    // Test Case 2: "abBa" (Should be a palindrome due to case-insensitivity)
    if (isPalindrome("abBa"))
        cout << "abBa" << " is a palindrome." << endl;
    else
        cout << "abBa" << " is not a palindrome." << endl;

    // Test Case 3: "22" (Should be a palindrome)
    if (isPalindrome("22"))
        cout << "22" << " is a palindrome." << endl;
    else
        cout << "22" << " is not a palindrome." << endl;

    // Test Case 4: "67876" (Should be a palindrome)
    if (isPalindrome("67876"))
        cout << "67876" << " is a palindrome." << endl;
    else
        cout << "67876" << " is not a palindrome." << endl;

    // Test Case 5: "444244" (Should NOT be a palindrome)
    if (isPalindrome("444244"))
        cout << "444244" << " is a palindrome." << endl;
    else
        cout << "444244" << " is not a palindrome." << endl;

    // Test Case 6: "trYmeuemyRT" (Should be a palindrome)
    if (isPalindrome("trYmeuemyRT"))
        cout << "trYmeuemyRT" << " is a palindrome." << endl;
    else
        cout << "trYmeuemyRT" << " is not a palindrome." << endl;

    return 0; // Signals successful execution
}

// --- Function to check if a string is a palindrome (case-insensitive) ---
bool isPalindrome(string str)
{
    int length = str.length(); // Get the length of the string

    char ch1, ch2; // Variables to hold the characters being compared

    // Loop through only the first half of the string.
    // length / 2 ensures we don't compare the middle character (for odd-length strings)
    // or compare every pair twice.
    for (int i = 0; i < length / 2; i++)
    {
        // Get the character from the start of the string (index i)
        // toupper() converts the character to uppercase for a case-insensitive check
        ch1 = toupper(str[i]);

        // Get the corresponding character from the end of the string
        // The index is calculated as: length - 1 (last index) - i (offset from the end)
        ch2 = toupper(str[length - 1 - i]);

        // Check if the characters (now both uppercase) are different
        if (ch1 != ch2 )
            return false; // If they don't match, it's not a palindrome, so exit immediately
    }

    // If the loop completes without finding any non-matching pair, it IS a palindrome
    return true;
}
