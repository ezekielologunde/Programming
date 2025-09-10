#include <iostream>
#include <string>

using namespace std;

int main() {
    // Declare five double variables to store the test scores and one for the average.
    double score1, score2, score3, score4, score5;
    double average;

    // Prompt the user to enter each of the five test scores.
    cout << "Enter test score #1: ";
    cin >> score1;

    cout << "Enter test score #2: ";
    cin >> score2;

    cout << "Enter test score #3: ";
    cin >> score3;

    cout << "Enter test score #4: ";
    cin >> score4;

    cout << "Enter test score #5: ";
    cin >> score5;

    // Calculate the average of the five scores.
    // Use 5.0 to ensure a floating-point division.
    average = (score1 + score2 + score3 + score4 + score5) / 5.0;

    // Print the average test score to the terminal in the required format.
    cout << "Your average test score is: " << average << endl;

    return 0;
}
