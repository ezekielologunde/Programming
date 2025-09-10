
#include <iostream>

using namespace std;

// This constant represents the ratio of dry fruit calories to nut calories.
// For example, if it's 0.70, then dry fruit has 70% of the calories of nuts per pound.
const double FRUIT_NUT_CALORIES_RATIO = 0.70;
  
int main() {
    // Declare variables to store user input and calculated values.
    int numberOfStudents;
    double caloriesPerStudent; 
    double totalCalories;
    double caloriesPerPoundNut;
    double caloriesPerPoundDryFruit;
    double caloriesPerPoundMixture;
    double totalMixtureNeeded;
    
    // Prompt the user to enter the number of students.
    cout << "Enter the number of students in the schools: ";
    cin >> numberOfStudents;
    cout << endl;

    // Prompt for the individual caloric requirement.
    cout << "Enter the calories required for each student: ";
    cin >> caloriesPerStudent;
    cout << endl;

    // Prompt for the caloric content of nuts per pound.
    cout << "Enter calories in one pound of nuts: ";
    cin >> caloriesPerPoundNut;
    cout << endl;

    // Calculate the calories per pound of dry fruit using the defined ratio.
    caloriesPerPoundDryFruit = caloriesPerPoundNut / FRUIT_NUT_CALORIES_RATIO;
    
    // Calculate the average calories per pound for a mixture that is 50% nuts and 50% dry fruits by weight.
    caloriesPerPoundMixture = (caloriesPerPoundNut + caloriesPerPoundDryFruit) / 2.0;

    // Calculate the total calories required for all students.
    totalCalories = numberOfStudents * caloriesPerStudent;
    cout << endl;

    // Calculate the total pounds of the mixture needed.
    totalMixtureNeeded = totalCalories / caloriesPerPoundMixture;

    // Output the amount of nuts and dry fruit needed, assuming a 50/50 mixture by weight.
    cout << "Dry fruits mixture: " << totalMixtureNeeded / 2 << " pounds." << endl;
    cout << "Nuts mixture: " << totalMixtureNeeded / 2 << " pounds." << endl;

    return 0;
}
