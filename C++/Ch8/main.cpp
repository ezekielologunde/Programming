   
#include <iostream>
#include <iomanip> 
 
using namespace std;

void initialize(double list[], int size);
void print(double list[], int size);

int main()
{
    double alpha[50];

    initialize(alpha, 50);
    print(alpha, 50);
    return 0;
}

void initialize(double list[], int size)
{
	int count;

	for (count = 0; count < 25; count++)
		list[count] = count * count;

	for (count = 25; count < size; count++)
		list[count] = 3 * count;
}

void print(double list[], int size)
{
	int count;

	for (count = 0; count < size; count++)
	{
		cout << setw(4) << list[count] << " ";
		if ((count + 1) % 10 == 0)
			cout << endl;
	}
	cout << endl;
}