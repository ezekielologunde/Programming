#include <iostream>

using namespace std; 
  
int main()
{
    // Declare variables for the masses of the two bodies.
    double mass1;
    double mass2;
    // Declare a variable for the distance between the two bodies.
    double distance;

    // Declare a variable to store the calculated force.
    double force;

    // Prompt the user to enter the mass of the first body.
    cout << "Enter the mass of the first body: ";
    cin >> mass1;
    cout << endl; 

    // Prompt the user to enter the mass of the second body.
    cout << "Enter the mass of the second body: ";
    cin >> mass2;
    cout << endl;

    // Prompt the user to enter the distance between the bodies.
    cout << "Enter the distance between the two bodies: ";
    cin >> distance;
    cout << endl;

    // Calculate the force using Newton's law of universal gravitation.
    // The constant `6.67 / 100000000` is the gravitational constant in scientific notation.
    // The formula is F = k * (m1 * m2) / d^2.
    force = (6.67 / 100000000) * (mass1 * mass2 / (distance * distance));

    // Output the calculated force.
    cout << "The force between the two bodies = " << force << endl;

    return 0;
}
