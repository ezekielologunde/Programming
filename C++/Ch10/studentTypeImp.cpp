#include <iostream> // Include the standard input/output stream library (for cout, cin).
#include <string>   // Include the string library (for using the string data type).
#include <iomanip>  // Include the I/O manipulator library (for formatting, though not strictly used in the body).
#include "studentType.h" // Include the custom header file where the studentType class is declared.

using namespace std; // Use the standard namespace to simplify code.

// Function definition: Sets all data members of the student object at once.
void studentType::setData(string fn, string ln, char grade, 
                          int tScore, int prgScore, double gp)
{
    firstName = fn;          // Set the first name.
    lastName = ln;           // Set the last name.
    testScore = tScore;      // Set the numerical test score.
    programmingScore = prgScore; // Set the numerical programming score.
    setGrade();              // Call the helper function to calculate and set the course grade.
    GPA = gp;                // Set the GPA.
}

// Function definition: Setter for the first name.
void studentType::setFirstName(string fn)
{
    firstName = fn;
}

// Function definition: Setter for the last name.
void studentType::setLastName(string ln)
{
    lastName = ln;
}

// Function definition: Calculates the letter grade based on the average of the two scores.
void studentType::setGrade()
{
    // Calculate the average score (integer division is used here, which might truncate the result).
    int score = (testScore + programmingScore) / 2;

    // Determine the letter grade based on a standard scale.
    if (score >= 90)
        courseGrade = 'A'; // Grade A for 90 and above.
    else if (score >= 80)
        courseGrade = 'B'; // Grade B for 80-89.
    else if (score >= 70)
        courseGrade = 'C'; // Grade C for 70-79.
    else if (score >= 60)
        courseGrade = 'D'; // Grade D for 60-69.
    else
        courseGrade = 'F'; // Grade F for anything below 60.
}

// Function definition: Setter for the test score.
void studentType::setTestScore(int tScore)
{
    testScore = tScore;
}

// Function definition: Setter for the programming score.
void studentType::setProgScore(int prgScore)
{
    programmingScore = prgScore;
}

// Function definition: Setter for the GPA.
void studentType::setGPA(double gp)
{
    GPA = gp;
}


// Function definition: Getter for the first name (declared const as it doesn't modify the object).
string studentType::getFirstName() const
{
    return firstName;
}

// Function definition: Getter for the last name (declared const).
string studentType::getLastName() const
{
    return lastName;
}

// Function definition: Getter for the course grade (declared const).
char studentType::getGrade() const
{
    return courseGrade;
}

// Function definition: Getter for the test score (declared const).
int studentType::getTestScore() const
{
    return testScore;
}

// Function definition: Getter for the programming score (declared const).
int studentType::getProgScore() const
{
    return programmingScore;
}

// Function definition: Getter for the GPA (declared const).
double studentType::getGPA() const
{
    return GPA;
}

// Function definition: Prints all student details to the console (declared const).
void studentType::print() const
{
    cout << "Name: " << firstName << " " << lastName << endl;
    cout << "Grade: " << courseGrade << endl;
    cout << "Test score: " << testScore << endl;
    cout << "Programming score: " << programmingScore << endl;
    cout << "GPA: " << GPA << endl;
}

// Function definition: Constructor that initializes all data members using parameters.
studentType::studentType(string fn, string ln, char grade, 
                         int tScore, int prgScore, double gp)
{
    firstName = fn;          // Initialize first name.
    lastName = ln;           // Initialize last name.
    testScore = tScore;      // Initialize test score.
    programmingScore = prgScore; // Initialize programming score.
    setGrade();              // Calculate and initialize the course grade.
    GPA = gp;                // Initialize GPA.
}
