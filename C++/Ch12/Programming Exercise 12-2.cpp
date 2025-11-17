#include <iostream> // Include for standard I/O (cout, cin, endl).
#include <fstream>  // Include for file I/O (ifstream, ofstream).
#include <cstring>  // Include for C-style string functions (strlen, strcpy).

using namespace std;

char examGrade(int score); // Function prototype to determine the letter grade.

int main()
{
    char *keyString;      // Pointer to dynamically hold the answer key.
    int noOfQuestions;    // Stores the number of questions in the exam.

    char *answerString;   // Pointer to dynamically hold the student's answers.
    
    char ID[9];           // C-style array to hold the student's ID (up to 8 characters + null terminator).
    
    char ch;              // Temporary character to consume newline characters from the file.

    int score;            // Stores the calculated score for each student.
    int len;              // Stores the length of the student's answer string read from the file.
    ifstream infile;      // Input file stream object.
    ofstream outfile;     // Output file stream object (declared but not used for writing).

    int i;                // Loop counter.

    // Attempt to open the input data file.
    infile.open("Ch12_Ex2Data.txt");
    if (!infile)
    {
        cout << "Cannot open input file. Program terminates!" << endl;
        return 1; // Exit with error code if file fails to open.
    }

    // Get the number of questions from the user (needed for dynamic allocation and grading).
    cout << "Enter number of exam questions: ";
    cin >> noOfQuestions;
    cout << endl;

    // Dynamically allocate memory for the key and answer strings (+1 for null terminator).
    keyString = new char[noOfQuestions + 1];
    answerString = new char[noOfQuestions + 1];

    cout << "Processing Data" << endl;
    
    // Read the answer key from the first line of the file (using get to read the whole line).
    infile.get(keyString, noOfQuestions + 1);

    cout << "Key: " << keyString << endl;
    
    // The following block processes the first student record:
    // 1. Read the student ID (ID is treated as a word/token).
    infile >> ID;
    // 2. Consume the newline character left after reading the ID.
    infile.get(ch);
    // 3. Read the student's answers (using get to read the line, including spaces).
    infile.get(
