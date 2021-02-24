//cpp
#include "decision.h"
#include <iostream>
#include <string>

using std::string;

string get_letter_grade_using_if(int grade)
{
    bool gradeA = grade >= 90 && grade <= 100;
    bool gradeB = grade >= 80 && grade <= 89;
    bool gradeC = grade >= 70 && grade <= 79;
    bool gradeD = grade >= 60 && grade <= 69;
    bool gradeF = grade >= 0 && grade <= 59;
    string letterGrade;

    if (gradeA)
        letterGrade = "A";
    else if (gradeB)
        letterGrade = "B";
    else if (gradeC)
        letterGrade = "C";
    else if (gradeD)
        letterGrade = "D";
    else
        letterGrade = "F";

    return letterGrade;
}

string get_letter_grade_using_switch(int grade)
{
    string letterGrade;
    switch (grade / 10)
    {
    case 10:
    case 9:
        letterGrade = "A";
        break;
    case 8:
        letterGrade = "B";
        break;
    case 7:
        letterGrade = "C";
        break;
    case 6:
        letterGrade = "D";
        break;
    case 5:
    case 4:
    case 3:
    case 2:
    case 1:
        letterGrade = "F";
        break;
    default:
        letterGrade = "OUT OF RANGE";
    }

    return letterGrade;
}