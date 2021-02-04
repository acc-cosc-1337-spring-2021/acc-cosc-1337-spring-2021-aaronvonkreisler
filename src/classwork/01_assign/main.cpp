//Write the include statement for types.h here
#include "types.h"
//Write include for capturing input from keyboard and displaying output to screen
#include <iostream>

using std::cin;
using std::cout;

int main()
{
	int num;
	int num1 = 4;

	cout << "Enter a number to start ... \n";
	cin >> num;
	int result = multiply_numbers(num); //Multiply num by 5

	cout << "Result: " << result << "\n";

	result = multiply_numbers(num1);
	cout << "Result 2: " << result; //Will be 20 every time
	return 0;
}
