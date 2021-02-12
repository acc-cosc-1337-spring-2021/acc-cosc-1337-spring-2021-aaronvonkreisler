//write include statements
#include "variables.h"
#include <iostream>

//write namespace using statement for cout
using std::cin;
using std::cout;
using std::endl;
/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int main()
{
	double meal_amount;

	cout << "Enter the price of the meal : \n";
	cin >> meal_amount;

	double tax_amount = get_sales_tax_amount(meal_amount);
	double tip_rate;

	cout << "What rate would you like to tip? \n";
	cin >> tip_rate;

	double tip_amount = get_tip_amount(meal_amount, tip_rate);
	double total = tip_amount + tax_amount + meal_amount;
	cout << "Here is your receipt \n";
	cout << "---------------------------- \n";
	cout << "Meal Amount ---- $" << meal_amount << endl;
	cout << "Sales Tax ---- $" << tax_amount << endl;
	cout << "Tip Amount ---- $" << tip_amount << endl;
	cout << "------------------------- \n";
	cout << "Total ---- $" << total << endl;

	return 0;
}
