#include "dna.h"
#include <iostream>

using std::cout;
/*
Write code for function get_gc_content that accepts
a const reference string parameter and returns a double.
Calculate GC content:
Iterate string count Gs and Cs, divide count by string length.
Return quotient.
*/

double get_gc_content(const std::string& dna){
    double count = 0;
    double content;
    for (std::size_t i = 0; i < dna.size(); ++i) {
        if(char(dna.at(i) == 'C') || char(dna.at(i) == 'G'))
            count++; 
    }
    content =count / dna.length();
    return content;
}


/*
Write code for function get_reverse_string that
accepts a string parameter and returns a string reversed.
*/
string get_reverse_string(string dna){
    string reversed;

    for (int i = dna.size() - 1; i >= 0; --i) {
        reversed.push_back(dna[i]);
    }

    return reversed;
}


/*
Write prototype for function get_dna_complement that
accepts a string dna and returns a string.
Calculate dna complement:
a. call function get_reverse_string(dna), save results to a local string variable
b. iterate local string variable and
    replace A with T, T with A, C with G and G with C
c. return string
*/
string get_dna_complement(string dna) {
    string reversed = get_reverse_string(dna);
    string complement;

    for(std::size_t i=0; i < reversed.size(); ++i) {
        char letter;
        switch(reversed[i]){
            case 'A':
                letter = 'T';
                break;
            case 'T':
                letter = 'A';
                break;
            case 'C':
                letter = 'G';
                break;
            case 'G':
                letter = 'C';
                break;
            default:
                letter = reversed[i];
        }

        complement.push_back(letter);
    }

    return complement;
}
