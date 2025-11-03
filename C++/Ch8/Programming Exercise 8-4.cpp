#include <iostream> // Needed for standard input/output (like 'cout')
#include <iomanip>  // Needed for formatting output (like 'setw')
#include <fstream>  // Needed for file input/output operations (like 'ifstream')
 
using namespace std; // Allows us to use standard names like 'cout', 'endl', and 'ifstream'
 
// Function prototype: Declares a function to read data from the file and update the array
// 'ifstream&' means the function receives a reference to the input file stream
void readData(ifstream& inputFile, int list[], int size);

// Function prototype: Declares a function to print the frequency array
void print(int list[], int size);

int main()
{
    // Declares an integer array named 'scores' with 8 elements.
    // Initializing it with {0} ensures all 8 counts start at zero.
    // Each element will store the count for a 25-point score range.
    int scores[8] = {0};

    // Declares a file stream object for reading input
    ifstream infile;

    // Attempts to open the specified file
    infile.open("Ch8_Ex4Data.txt");

    // Checks if the file failed to open (e.g., file not found)
    if (!infile)
    {
        // Prints an error message
        cout << "Cannot open the input file. Program terminates!" 
             << endl;
        // Returns an error code (1) to the operating system
        return 1;
    }

    // Calls the function to read scores from the file and populate the 'scores' array
    readData(infile, scores, 8);

    // Calls the function to print the calculated score ranges and their counts
    print(scores, 8);
    cout << endl;

    // Closes the input file after reading is complete
    infile.close();
    
    // Program finished successfully
    return 0;
}

// --- Function to read scores and count them by range ---
// Takes the open file stream, the array to store counts, and the array size (8)
void readData(ifstream& inputFile, int list[], int size)
{
    int score; // Variable to hold the current score read from the file
    int index; // Variable to hold the calculated array index (the score range)

    // Reads the first score from the file
    inputFile >> score;

    // Loop continues as long as the file stream is successful (not end-of-file or error)
    while (inputFile)
    {
        // Calculates which array index (range) the score belongs to.
        // Integer division by 25 groups scores: 0-24 -> 0, 25-49 -> 1, 75-99 -> 3, etc.
        index = score / 25;

        // Special check: If a score is 200, the index is 8 (200/25).
        // Since the array only has 8 spots (indices 0-7), this adjusts index 8 to 7.
        if (index == size)
            index--;
            
        // Final check to make sure the index is valid (0-7)
        if (index < size)
            // Increments the count for the calculated score range (index)
            list[index]++;

        // Reads the next score; this also controls the 'while' loop condition
        inputFile >> score;
    }
}

// --- Function to print the frequency table ---
// Takes the array of counts and the array size (8)
void print(int list[], int size)
{
    int range;        // Loop control variable
    int lowRange = 0; // The start of the current score range (e.g., 0, 25, 50)
    int upperRange = 24; // The end of the current score range (e.g., 24, 49, 74)

    // Prints the column headers for the output table
    cout << "   Range       # of Students" << endl;

    // Loops through the 8 elements (ranges) of the array
    for (range = 0; range < size; range++)
    {
        // Prints the range (e.g., "  0 -  24") and the count from the array (list[range])
        cout << setw(3) << lowRange << " - " << setw(3)
             << upperRange << setw(15)
             << list[range] << endl;
             
        // Updates the range limits for the next loop iteration
        lowRange = upperRange + 1; // New range starts one higher (e.g., 25)
        upperRange = upperRange + 25; // New range ends 25 higher (e.g., 49)
        
        // This adjusts the last range (index 7) to be 175 - 200, 
        // covering the maximum possible score (200) without going over.
        if (range == size - 2)
            upperRange++;
    }
    cout << endl;
}
