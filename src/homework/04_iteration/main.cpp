//write include statements
#include "dna.h"
#include <iostream>
#include <string>

//write using statements
using std::string;
using std::cout;
using std::cin;
using std::endl;

/*
Write code that prompts user to enter 1 for Get GC Content, 
or 2 for Get DNA Complement.  The program will prompt user for a 
DNA string and call either get gc content or get dna complement
function and display the result. Program runs as long as 
user enters a y or Y.
*/
int main() 
{
	std::string dna;
	int prompt;
	bool should_quit = false;
	char yes;

	do {
		cout<<"Enter 1 to Get GC Content, or 2 to Get DNA Complement. \n";
		cin>>prompt;
		cout<< "What's the DNA string?\n";
		cin>>dna;

		if(prompt == 1)
			cout<< "GC Content is: "<<get_gc_content(dna)<< endl;
		if(prompt ==2)
			cout<< "DNA Complement is: "<<get_dna_complement(dna) << endl;
		 cout<< "Would you like to quit? (y or n) \n";
		 cin>>yes;
		if (yes == 'y' || yes == 'Y') {
			should_quit = true;
		}
		
	} while (!should_quit);
	
	return 0;
}