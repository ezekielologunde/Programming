#include <iostream>  // Include the standard input/output stream library (for cin, cout).
#include <string>    // Include the string library (for using the string data type).
#include <fstream>   // Include the file stream library (for file input/output).
#include <iomanip>   // Include the I/O manipulator library (for formatting output, like setw).

using namespace std; // Use the standard namespace to simplify code.

const int NO_OF_STUDENTS = 20; // Constant defining the fixed size of the student array.

// Define a structure to hold information for a single student.
struct studentType
{
    string studentFName; // Student's first name.
    string studentLName; // Student's last name.
    int testScore;       // Student's numerical test score (0-100).
    char grade;          // Student's calculated letter grade (A, B, C, D, F).
};

// Function prototypes (declarations)
// Function to read student data from the input file into the array.
void getData(ifstream& inFile, studentType sList[], int listSize);
// Function to calculate and assign the letter grade for each student.
void calculateGrade(studentType sList[], int listSize);
// Function to find and return the highest test score in the array.
int highestScore(const studentType sList[], int listSize);
// Function to print the formatted results and statistics to the output file.
void printResult(ofstream& outFile, const studentType sList[], 
                 int listSize);

// Main function where program execution begins.
int main()
{
    ifstream inData; // Declare an input file stream object.
    ofstream outData; // Declare an output file stream object.
    studentType studentList[NO_OF_STUDENTS]; // Declare an array of studentType structs.

    // Attempt to open the input data file.
    inData.open("Ch9_Ex2Data.txt");
    // Check if the input file failed to open.
    if (!inData)
    {
        // Output an error message and terminate the program with an error code.
        cout << "The input file does not exist. Program terminates!"
             << endl;
        return 1;
    }

    // Attempt to open the output data file.
    outData.open("Ch9_Ex2Out.txt");
    // Check if the output file failed to open.
    if (!outData)
    {
        // Output an error message and terminate the program with an error code.
        cout << "Cannot open the output file. Program terminates!" 
             << endl;
        return 1;
    }

    // Call function to read data from the file into the student array.
    getData(inData, studentList, NO_OF_STUDENTS);
    // Call function to calculate and store the letter grade for each student.
    calculateGrade(studentList, NO_OF_STUDENTS);
    // Call function to print all results and statistics to the output file.
    printResult(outData, studentList, NO_OF_STUDENTS);

    // Indicate that the program finished successfully.
    return 0;
}

// Function definition: Reads student first name, last name, and score from file.
void getData(ifstream& inFile, studentType sList[], int listSize)
{
    // Loop through the array to read data for each student.
    for (int i = 0; i < listSize; i++)
        // Read data directly into the struct members from the file stream.
        inFile >> sList[i].studentFName >> sList[i].studentLName
               >> sList[i].testScore;
}

// Function definition: Calculates letter grade based on test score (standard 90/80/70/60 scale).
void calculateGrade(studentType sList[], int listSize)
{
    // Loop through the entire list of students.
    for (int i = 0; i < listSize; i++)
    {
        // Use a switch statement on the score divided by 10 (integer division) for grading bands.
        switch (sList[i].testScore / 10)
        {
        case 10: // Score 100
        case 9:  // Score 90-99
            sList[i].grade = 'A';
            break;
        case 8:  // Score 80-89
            sList[i].grade = 'B';
            break;
        case 7:  // Score 70-79
            sList[i].grade = 'C';
            break;
        case 6:  // Score 60-69
            sList[i].grade = 'D';
            break;
        case 5: case 4: case 3: case 2: case 1: case 0: // Scores 0-59
            sList[i].grade = 'F';
        }
    }
}

// Function definition: Finds the maximum test score in the student list.
int highestScore(const studentType sList[], int listSize)
{
    // Initialize highest score with the score of the first student.
    int hScore = sList[0].testScore;

    // Loop through the rest of the array starting from the second student (index 1).
    for (int i = 1; i < listSize; i++)
        // Check if the current student's score is higher than the stored highest score.
        if (hScore < sList[i].testScore)
            // Update the highest score.
            hScore = sList[i].testScore;

    // Return the final highest score found.
    return hScore;
}

// Function definition: Prints formatted results to the specified output file.
void printResult(ofstream& outFile, const studentType sList[], 
                 int listSize)
{
    // Get the highest score using the helper function.
    int maxScore = highestScore(sList, listSize);
    int i; // Loop index variable.

    // Print the header row to the output file, using setw for alignment.
    outFile << setw(15) << "Student Name          " // Note: Manual spacing for alignment
            << setw(10) << "Test Score"
            << setw(7) << "Grade" << endl;

    // Loop through the student list to print each student's results.
    for (i = 0; i < listSize; i++)
        // Print student name (Last, First) left-aligned.
        outFile << left << setw(25)
                << sList[i].studentLName + ", " + sList[i].studentFName
                // Print score right-aligned with padding.
                << right << " " << setw(5) << sList[i].testScore
                // Print grade with padding.
                << setw(6) << " " << sList[i].grade << endl;

    // Print the highest test score found.
    outFile << endl << "Highest Test Score: " << maxScore << endl;
    // Print header for students who achieved the highest score.
    outFile << "Students having the highest test score:" << endl;

    // Loop again to identify and print only the names of students with the max score.
    for (i = 0; i < listSize; i++)
        // Check if the current student's score matches the highest score.
        if (sList[i].testScore == maxScore)
            // Print the name of the high-scoring student.
            outFile << sList[i].studentLName + ",  " + sList[i].studentFName
                    << endl;
}
