#include <iostream> // Needed for input/output operations (like 'cout')
#include <iomanip>  // Needed for manipulating output, like setting width ('setw')

using namespace std; // Allows us to use standard names like 'cout' and 'endl'

// Function prototype: declares a function that fills an array with values
void initialize(double list[], int size);

// Function prototype: declares a function that prints the array's contents
void print(double list[], int size);

int main()
{
    // Declares an array named 'alpha' that can hold 50 double-precision numbers
    double alpha[50];

    // Calls the 'initialize' function to fill the 'alpha' array with specific values
    initialize(alpha, 50);

    // Calls the 'print' function to display the contents of the 'alpha' array
    print(alpha, 50);

    // Indicates that the program finished successfully
    return 0;
}

// --- Function to fill the array with values ---
// Takes an array of doubles ('list') and its size as input
void initialize(double list[], int size)
{
    int count; // Loop control variable

    // Loop for the first 25 elements (indices 0 through 24)
    for (count = 0; count < 25; count++)
        // Sets the element's value to the index squared (e.g., list[2] = 4)
        list[count] = count * count;

    // Loop for the rest of the elements (indices 25 through 49, up to 'size')
    for (count = 25; count < size; count++)
        // Sets the element's value to the index multiplied by 3 (e.g., list[25] = 75)
        list[count] = 3 * count;
}

// --- Function to print the array's contents neatly ---
// Takes an array of doubles ('list') and its size as input
void print(double list[], int size)
{
    int count; // Loop control variable

    // Loop through every element in the array
    for (count = 0; count < size; count++)
    {
        // Prints the element, using 4 spaces for its width for neat alignment
        cout << setw(4) << list[count] << " ";

        // Checks if 10 elements have been printed (since 'count' is 0-indexed)
        if ((count + 1) % 10 == 0)
            // If 10 elements are on the current line, start a new line
            cout << endl;
    }
    // Prints a final newline to ensure the prompt appears on a fresh line
    cout << endl;
}
