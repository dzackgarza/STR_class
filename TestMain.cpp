/*****************************************************

    Zack Garza
    CISP 430 - TTH 5:30 pm
    Programming Project 2 - Classes
    September 12, 2013

*****************************************************/

#include <iostream>
#include "MyString.h"
using namespace std;

//               Main Functions                     //
/****************************************************/

//               Helper Functions                     //
/****************************************************/
void runtests();
void testEmptyConst();
void testSingleCharConst();
void testCharStarConst();
void printTestHeader(char testName[]);
void printTestFooter(char testName[]);

int main()
{
    cout << "Running Tests";
    runtests();
    return 0;
}

void runtests()
{
    testEmptyConst();
    testSingleCharConst();
    testCharStarConst();
}

void testEmptyConst()
{
    char desc[] = "Empty Constructor";
    printTestHeader(desc);

    STRING s;
    cout << "STRING contains '"; STRdisplay(s); cout << "'.\n"
        << "STRING length is " << s.length() << ".\n";


    printTestFooter(desc);
}

void testSingleCharConst()
{
    char desc[] = "Single Character Constructor";
    printTestHeader(desc);

    char c = 'd';
    cout << "Assigned char is '" << c << "'. \n";
    STRING s (c);
    cout << "STRING contains '"; STRdisplay(s); cout << "'.\n"
        << "STRING length is " << s.length() << ".\n";

    printTestFooter(desc);
}

void testCharStarConst()
{
    char desc[] = "Char* Constructor";
    printTestHeader(desc);

    char cstr[] = "This is a string that is incredibly long.";
    cout << "The contents of the C-String are: \n\t'" << cstr << "'.\n";
    STRING s (cstr);
    cout << "The contents of STRING are: \n\t'"; STRdisplay(s); cout << "'.\n";

    printTestFooter(desc);
}

void printTestHeader(char testName[])
{
    cout << "\n********** Begin " << testName << " Test ******************\n";
}

void printTestFooter(char testName[])
{
    cout << "********** End " << testName << " Test ******************\n";
}
