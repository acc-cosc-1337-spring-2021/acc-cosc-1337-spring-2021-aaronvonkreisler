//Write the include statement for decisions.h here
#include <iostream>
#include <string>
#include "decision.h"
//Write namespace using statements for cout and cin
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	int num;
	cout << "Enter a number between 0 and 100 to grade \n";
	cin >> num;

	if (num >= 0 && num <= 100)
	{
		string grade = get_letter_grade_using_switch(num);
		cout << "The letter Grade is: " << grade << endl;
		grade = get_letter_grade_using_if(num);
		cout << "The letter Grade is: " << grade << endl;
	}
	else
	{
		cout << "Number was out of range.";
		exit(1);
	}

	return 0;
}
