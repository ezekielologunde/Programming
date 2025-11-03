#include <iostream>
 
using namespace std;

const double PI = 3.141593;
 
int main()
{ 
    double radius;
    double area;
    double price;
    double pricePerSquareInch;

    cout << "Enter the radius of the pizza: ";
    cin >> radius;
    cout << endl;  

    cout << "Enter the price of the pizza: ";
    cin >> price;
    cout << endl;

    area = PI * radius * radius;
    pricePerSquareInch = price / area;

    cout << "The price per square inch is: " << pricePerSquareInch << endl;

    return 0;
}
