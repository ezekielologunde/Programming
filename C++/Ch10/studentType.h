#include <string> // Include the string library, necessary for using the string data type.

using namespace std; // Use the standard namespace to simplify code.

// Declaration of the custom class studentType.
class studentType
{
public: // All members declared here are publicly accessible.
    // Function to set all student data. Uses default arguments for flexibility.
    void setData(string fn = "", string ln = "", char grade = '*', 
                 int tScore = 0, int prgScore = 0, double gp = 0.0);

    // Setter function to modify the first name.
    void setFirstName(string fn);
    // Setter function to modify the last name.
    void setLastName(string ln);
    // Function to calculate and set the course grade (typically based on scores).
    void setGrade();
    // Setter function to modify the test score.
    void setTestScore(int tScore);
    // Setter function to modify the programming score.
    void setProgScore(int prgScore);
    // Setter function to modify the GPA.
    void setGPA(double gp);

    // Getter function to retrieve the first name (const means it won't change the object).
    string getFirstName() const;
    // Getter function to retrieve the last name.
    string getLastName() const;
    // Getter function to retrieve the course grade.
    char getGrade() const;
    // Getter function to retrieve the test score.
    int getTestScore() const;
    // Getter function to retrieve the programming score.
    int getProgScore() const;
    // Getter function to retrieve the GPA.
    double getGPA() const;

    // Function to print all student details to the console.
    void print() const;

    // Constructor: Called when a studentType object is created. Includes default arguments.
    studentType(string fn = "", string ln = "", char grade = '*', 
                int tScore = 0, int prgScore = 0, double gp = 0.0);
private: // All members declared here are privately accessible (only by class members).
    string firstName; // Private data member to store the student's first name.
    string lastName;  // Private data member to store the student's last name.
    char courseGrade; // Private data member to store the student's letter grade.
    int testScore;    // Private data member to store the first test score.
    int programmingScore; // Private data member to store the second test/program score.
    double GPA;       // Private data member to store the student's GPA.
};
