#include <iostream> // Include the input/output stream library for console operations (cout, cin).
#include <cstring> // Include the C-style string library for string manipulation functions (like strlen).
#include <cctype> // Include the character classification library for character functions (like toupper).
 
using namespace std; // Use the standard namespace to avoid typing std:: everywhere.

int main()
{
    char str[81]; // Declare a C-style character array (string) to hold up to 80 characters + null terminator.

    int len; // Variable to store the length of the string.

    int i; // Loop control variable (index).

    // Prompt the user to enter a string.
    cout << "Enter a string: ";
    // Read up to 80 characters from the input stream into 'str', including spaces.
    // The input stops after 80 characters or when the Enter key is pressed.
    cin.get(str, 80);
    cout << endl;
    // Inform the user about the output format.
    cout << "String in upper case letters is:" << endl;

    // Calculate the length of the string currently stored in 'str'.
    len = strlen(str);
    // Loop through the string, character by character, from index 0 up to (but not including) the length.
    for (i = 0; i < len; i++)
        // Convert the current character to uppercase using toupper() and immediately output it.
        // toupper returns an int, so we cast it back to char for correct output.
        cout << static_cast<char>(toupper(str[i]));
    // Output a newline character for clean formatting after the entire string is processed.
    cout << endl;

    // Indicate that the program finished successfully.
    return 0;
}
