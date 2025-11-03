#include <iostream> // Includes the library needed for input (cin) and output (cout)

using namespace std; // Allows us to use standard names like cout and endl

const int ARRAY_SIZE = 15; // Defines a constant for the fixed size of the array (15 elements)

// Function prototype: Declares a function to print the array contents
void printArray(const int x[], int sizeX);

// Function prototype: Declares a function to find the index of the last largest element
int lastLargestIndex(const int x[], int sizeX);

int main()
{
    // Declares an integer array named 'list' with 15 spots (indices 0 to 14)
    int list[ARRAY_SIZE];

    // Prompts the user to enter the data
    cout << "Enter 15 integers: " << endl;
    
    // Variable to control the input loop
    int i = 0;
    
    // Loop to read 15 integers from the user and store them in the array
    while(i < 15) {
        cin >> list[i]; // Reads an integer into the current array position
        ++i;            // Moves to the next position (index) in the array
    }
    
    // Calls the function to display all the entered elements
    printArray(list, ARRAY_SIZE);
    cout << endl; // Prints a newline for spacing

    // Calls the 'lastLargestIndex' function and prints the returned position
    cout << "The position of the last occurrence of the largest "
        << "element in list is: "
         << lastLargestIndex(list, ARRAY_SIZE) << endl;
         
    // Calls 'lastLargestIndex' again to get the position, then uses that index
    // to look up and print the actual largest value from the array
    cout << "The largest element in list is: "
         << list[lastLargestIndex(list, ARRAY_SIZE)]
         << endl << endl;

    return 0; // Signals that the program executed successfully
}

// --- Function to print the array ---
void printArray(const int list[], int listSize)
{
    int index; // Loop control variable

    // Loop through the array from the first element (index 0) to the last
    for (index = 0; index < listSize; index++)
        cout << list[index] << " "; // Prints each element followed by a space
}
    
// --- Function to find and return the index of the last largest element ---
int lastLargestIndex(const int list[], int listSize)
{
    int counter;
    // maxIndex holds the position of the largest value found so far.
    // Initialize it to the first element's index (0) to start the comparison.
    int maxIndex = 0; 

    // Loop through the array starting from the second element (index 1)
    for (counter = 1; counter < listSize; counter++)
       // Comparison: If the value at the current 'largest' index (maxIndex) 
       // is LESS THAN OR EQUAL TO the value at the current element (counter)...
       if (list[maxIndex] <= list[counter]) 
            // ...then we found a new largest element, OR a duplicate of the current largest.
            // By using '<=' (less than or equal to), we ensure the index is always updated 
            // to the rightmost (last) occurrence of the largest value.
            maxIndex = counter;
            
    // Returns the final index (position) where the last largest element was found
    return maxIndex;
}
