#include <iostream>  // Include the standard input/output stream library (for cin, cout).
#include <string>    // Include the string library (for using the string data type).
#include <iomanip>   // Include the I/O manipulator library (for formatting output, like setprecision).

using namespace std; // Use the standard namespace to simplify code (e.g., using cout instead of std::cout).

// Define a structure (custom data type) named computerType.
struct computerType
{
    string manufacturer;  // Member to store the computer's manufacturer (text).
    string modelType;     // Member to store the computer's model name (text).
    string processorType; // Member to store the processor type (text).
    int ram;              // Member to store RAM size in GB (integer).
    int hardDriveSize;    // Member to store hard drive size in GB (integer).
    int yearBuilt;        // Member to store the year the computer was built (integer).
    double price;         // Member to store the computer's price (floating-point number).
};

// Main function where program execution begins.
int main()
{
    computerType computer; // Declare a variable 'computer' of the custom type computerType.

    // Set output formatting for floating-point numbers (price).
    cout << fixed          // Use fixed-point notation.
         << showpoint      // Always show the decimal point.
         << setprecision(2); // Display exactly two digits after the decimal point.

    // Prompt the user for the manufacturer name.
    cout << "Enter the name of the manufacturer: ";
    // Use getline to read the entire line, including spaces, into the struct member.
    getline(cin, computer.manufacturer);
    cout << endl;

    // Prompt and read the computer model.
    cout << "Enter the model of the computer: ";
    getline(cin, computer.modelType);
    cout << endl;

    // Prompt and read the processor type.
    cout << "Enter processor type: ";
    getline(cin, computer.processorType);
    cout << endl;

    // Prompt and read RAM size (the previous getlines cleared the input buffer).
    cout << "Enter the size of RAM (in GB): ";
    cin >> computer.ram;
    cout << endl;

    // Prompt and read hard drive size.
    cout << "Enter the size of hard drive (in GB): ";
    cin >> computer.hardDriveSize;
    cout << endl;

    // Prompt and read the year built.
    cout << "Enter the year the computer was built: ";
    cin >> computer.yearBuilt;
    cout << endl;

    // Prompt and read the price.
    cout << "Enter the price: ";
    cin >> computer.price;
    cout << endl;

    // --- Output Section ---

    // Display all the collected data from the struct 'computer' to the console.
    cout << "Manufacturer: " << computer.manufacturer << endl;
    cout << "Model: " << computer.modelType << endl;
    cout << "Processor: " << computer.processorType << endl;
    cout << "Ram: " << computer.ram << endl;
    cout << "Hard Drive Size: " << computer.hardDriveSize << endl;
    cout << "Year Built: " << computer.yearBuilt << endl;
    // Display the price with a dollar sign and the applied two-decimal formatting.
    cout << "Price: $" << computer.price << endl;

    // Indicate that the program terminated successfully.
    return 0;
}
