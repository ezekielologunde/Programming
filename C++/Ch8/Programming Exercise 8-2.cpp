#include <iostream> // Includes the library needed for input (cin) and output (cout)

using namespace std; // Allows us to use standard names like cout and endl

const int ARRAY_SIZE = 15; // Global constant to easily change the size of the array later

// Function prototype: Declares a function to print the array contents
// 'const' means the function won't change the array's contents
void printArray(const int x[], int sizeX);

// Function prototype: Declares a function to find the index (position) of the smallest element
int smallestIndex(const int x[], int sizeX);

int main()
{
    // Declares an integer array named 'list' with 15 spots (indices 0 to 14)
    int list[ARRAY_SIZE];

    // Prompts the user to enter the data
    cout << "Enter 15 integers: " << endl;
    
    // Variable to control the loop
    int i = 0;
    
    // Loop to read 15 integers from the user and store them in the array
    while(i < 15) {
        cin >> list[i]; // Reads an integer into the current array position
        ++i;            // Moves to the next position in the array
    }
    
    // Calls the function to display all the entered elements
    printArray(list, ARRAY_SIZE);
    cout << endl; // Prints a newline for formatting

    // Calls the 'smallestIndex' function and prints the returned position
    cout << "The position of the first occurrence of the smallest "
        << "element in list is: "
         << smallestIndex(list, ARRAY_SIZE) << endl;
         
    // Calls 'smallestIndex' again to get the position, then uses that position
    // to look up and print the actual smallest value from the array
    cout << "The smallest element in list is: "
         << list[smallestIndex(list, ARRAY_SIZE)]
         << endl << endl;

    return 0; // Signals that the program executed successfully
}

// --- Function to print the array ---
// Takes the array and its size as input
void printArray(const int list[], int listSize)
{
    int index; // Loop control variable

    // Loop through the array from the first element (index 0) to the last
    for (index = 0; index < listSize; index++)
        cout << list[index] << " "; // Prints each element followed by a space
}

// --- Function to find and return the index of the smallest element ---
int smallestIndex(const int list[], int listSize)
{
    int counter;
    
    // minIndex holds the position of the smallest value found so far.
    // We assume the first element (at index 0) is the smallest initially.
    int minIndex = 0;

    // Loop starts at the second element (index 1) because index 0 is already the assumed smallest
    for (counter = 1; counter < listSize; counter++)
       // Comparison: If the value at the current 'smallest' index (minIndex) 
       // is greater than the value at the current element (counter)...
       if (list[minIndex] > list[counter])
            // ...then we found a new smaller element, so update the index to this new position
            minIndex = counter;
            
    // Returns the final index (position) where the smallest element was found
    return minIndex;
}
