#include <iostream> // Include the standard input/output stream library (for cin, cout, endl).
#include <cstring>  // Include the C-style string library (for strlen, strcpy).
#include <cctype>   // Include the character type library (for toupper).

using namespace std; // Use the standard namespace.

int main() {
    char *str; // Declare a pointer to a character, which will point to the dynamically allocated string.

    int len; // Variable to store the length of the input string.

    cout << "Enter a string: "; // Prompt the user for input.

    char temp[1000]; // Declare a large, fixed-size C-style array (buffer) to safely hold the input.
    // Read a line of input (up to 999 characters) from the user into the temp buffer.
    cin.get(temp, 1000); 

    len = strlen(temp); // Calculate the length of the string in the temp buffer (excluding the null terminator).

    // Dynamically allocate a char array large enough to hold the string plus the null terminator (+1).
    str = new char[len + 1];
    
    // Copy the contents of the temporary buffer (temp) into the dynamically allocated memory (str).
    strcpy(str, temp);

    cout << "String in upper case letters is:" << endl;

    // Loop through the string from the start (i = 0) up to the length (i < len).
    for (int i = 0; i < len; i++)
        // Convert the character to uppercase using toupper, cast it back to char, and print it.
        cout << static_cast<char>(toupper(str[i]));
    cout << endl; // Print a newline after the full uppercase string is displayed.

    // Free the dynamically allocated memory pointed to by str to prevent memory leaks.
    delete[] str;

    return 0; // Indicate that the program finished successfully.
}
