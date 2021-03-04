//write includes statements
#include "loops.h"
#include <iostream>
//write using statements for cin and cout
using std::cin;
using std::cout;

/*
Use a do while loop to prompt the user for 
a number, call the factorial function, and display the number's
factorial.  Also, loop continues as long as user wants to.
*/
int main()
{
	int value;
	char yesOrNo;
	bool shouldQuit = false;
	do
	{
		cout << "Please enter a number : \n";
		cin >> value;

		while (value < 1 || value > 10)
		{
			cout << "ERROR: Please enter a number between 1 and 10 \n";
			cin >> value;
		}

		cout << "The factorial is: " << factorial(value) << "\n";
		cout << "Would you like to quit? ( y/n ) \n";
		cin >> yesOrNo;

		if (yesOrNo == 'y')
			shouldQuit = true;
		else
			shouldQuit = false;

	} while (!shouldQuit);
	return 0;
}