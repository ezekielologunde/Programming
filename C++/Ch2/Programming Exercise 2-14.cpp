#include <iostream>

using namespace std; 

// This constant defines the value of one gigabyte in bytes for a computer (1024^3).
const int oneGB = 1073741824;
 
int main()  
{
    // Declare an integer for the hard drive size specified by the manufacturer.
    int hardDriveSize;
    // Declare a double for the calculated actual storage capacity.
    double hardDriveStorageCapacity; 

    // Prompt the user to enter the manufacturer's hard drive size in GB.
    cout << "Enter hard drive size in giga bytes:  ";
    cin >> hardDriveSize;
    cout << endl;

    // Calculate the actual storage capacity.
    // The manufacturer's size (in GB) is converted to bytes by multiplying by 1,000,000,000.
    // Then, this value is divided by the actual size of a gigabyte in bytes (1024^3),
    // to get the true capacity.
    hardDriveStorageCapacity = hardDriveSize / static_cast<double>(oneGB) * 1000000000;

    // Output the advertised hard drive size.
    cout << "Hard drive size = " << hardDriveSize << " GB" << endl;

    // Output the calculated actual storage capacity.
    cout << "Actual hard drive storage capacity = " << hardDriveStorageCapacity << " GB" << endl;

    return 0;
}
