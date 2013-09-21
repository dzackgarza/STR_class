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

void oStreamTest();
void iStreamTest();
void comparisonOpTest();
void notEqualOpTest();
void plusOpTest();
void indexTest();
void copyTest();
void compoundAddAssignOpTest();


int main()
{
    cout << "Running Tests";
    runtests();
    return 0;
}

void runtests()
{
    /*testEmptyConst();
    testSingleCharConst();
    testCharStarConst();
    oStreamTest();
    iStreamTest();
    comparisonOpTest();
    notEqualOpTest();
    plusOpTest();
    indexTest();
    copyTest();
    */
    compoundAddAssignOpTest();
}

void compoundAddAssignOpTest()
{
    char desc[] = "+= Operator";
    printTestHeader(desc);

    STRING s1("FooFoo");
    cout << "String One: " << s1 << "\n";
    STRING s2("BarBarBarBar");
    cout << "String Two: " << s2 << "\n";
    s1 += s2;
    cout << "Combined String: " << s1 << "\n";
    cout << "String One: " << s1 << s1.length() << "\n";
    cout << "String Two: " << s2 << s2.length() << "\n";

    printTestFooter(desc);
}

void testEmptyConst()
{
    char desc[] = "Empty Constructor";
    printTestHeader(desc);

    STRING s;
    cout << "STRING contains '"; STRdisplay(s); cout << "'.\n"
        << "STRING length is " << s.length() << ".\n"
        << "isEmpty returns " << (s.isEmpty() ? "True" : "False") << ".\n";

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

void oStreamTest()
{
    char desc[] = "oStream";
    printTestHeader(desc);

    char str[] = "Some random contents.";
    cout << "The oStream of the C-String contains: \n\t'" << str << "'\n";
    STRING s (str);
    cout << "The oStream of the STRING contains: \n\t'" << s << "'\n";;

    printTestFooter(desc);
}

void iStreamTest()
{
    char desc[] = "iStream";
    printTestHeader(desc);

    cout << "How do you test this?~!\n";

    printTestFooter(desc);
}

void comparisonOpTest()
{
    char desc[] = "== Operator";
    printTestHeader(desc);

    STRING s1("This is one string.");
    STRING s2("This is one string.");
    if (s1 == s2) cout << "The strings are equal.\n";
    else cout <<"The strings are not equal.\n";

    printTestFooter(desc);
}

void notEqualOpTest()
{
    char desc[] = "== Operator";
    printTestHeader(desc);

    STRING s1("This is one string.");
    STRING s2("This is another string.");
    if (s1 != s2) cout << "The strings are not equal.\n";
    else cout <<"The strings are equal.\n";

    printTestFooter(desc);
}

void plusOpTest()
{
    char desc[] = "+ Operator";
    printTestHeader(desc);

    STRING s1("FooFooFooFooFoo");
    cout << "String One: ' " << s1 << "'.\n";
    STRING s2("BarBarBarBarBar");
    cout << "String Two: ' " << s2 << "'.\n";
    cout << "The new string is: '" << (s1 + s2) << "'.\n";

    printTestFooter(desc);
}

void indexTest()
{
    char desc[] = "Index";
    printTestHeader(desc);

    STRING s("abcdefgh");
    int index = 0;
    char result = s[index];

    if (result == -1)
        cout << index << " is not a valid position, the index ranges from 0 to " << s.length()-1 << " \n";
    else
        cout << "The character at position " << index << " of '" << s << "' is " << result << ". \n";

    printTestFooter(desc);
}

void copyTest()
{
    char desc[] = "Index";
    printTestHeader(desc);

    STRING s1("Foo");
    cout << "String one contains: \n\t'" << s1 << "'\n";
    STRING s2;
    cout << "String two contains: \n\t'" << s2 << "'\n";
    s2 = s1;
    cout << "After assignment, String two now contains: \n\t'" << s2 << "'\n";

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
