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
void compoundAddAssignOpTestcharstar();
void compoundAddAssignOpTestchar();
void testDowncase();
void testUpcase();
void testToggle();
void testNonPrint();
void testCompare();

void testcharstar();
void testNullcstr();
void instreamtest();

int main()
{
    {
        cout << "Running Tests";
        runtests();
    }
    return 0;
}

void runtests()
{
    testEmptyConst();
    testSingleCharConst();
    testCharStarConst();
    oStreamTest();
    iStreamTest();
    comparisonOpTest();
    notEqualOpTest();
    plusOpTest();
    indexTest();
    copyTest();

    compoundAddAssignOpTest();
    compoundAddAssignOpTestcharstar();
    compoundAddAssignOpTestchar();

    testDowncase();
    testUpcase();
    testToggle();
    testNonPrint();

    testCompare();
    //testcharstar();

    //testNullcstr();
    //instreamtest();
}

void instreamtest()
{
    char desc[] = "Istream";
    printTestHeader(desc);

    STRING s;
    cin >> s;
    cout << "String now contains '"; STRdisplay(s);
    cout << "'\n";

    printTestFooter(desc);
}
void testNullcstr()
{
    char desc[] = "Null Char* Constructor";
    printTestHeader(desc);

    char* cstr = NULL;
    if (cstr == NULL) cout << "The contents of the C-String are: \n\t'" << "NULL" << "'.\n";
    STRING s (cstr);
    cout << s.length() << endl;
    cout << "The contents of STRING are: \n\t'"; STRdisplay(s); cout << "'.\n";
    cout << "Success.\n";

    printTestFooter(desc);
}
void testcharstar()
{
    STRING s1 = "Some text.";
    cout << "String One: '" << s1 << "'.\n";
    char* c = (char*)s1;
    cout << "Char* String: '" << c << "'.\n";
}
void testCompare()
{
    char desc[] = "Comparison";
    printTestHeader(desc);

    STRING s1("a");
    STRING s2("a");
    //s1[0] = 132;
    cout << "String 1: '" << s1 << "'.\n";
    cout << "String 2: '" << s2 << "'.\n";
    cout << "Is " << s1 << " > " << s2 << "? : " << ((s1 > s2) ? "True" : "False") << ".\n";
    cout << "Is " << s1 << " >= " << s2 << "? : " << ((s1 >= s2) ? "True" : "False") << ".\n\n";

    cout << "Is " << s1 << " < " << s2 << "? : " << ((s1 < s2) ? "True" : "False") << ".\n";
    cout << "Is " << s1 << " <= " << s2 << "? : " << ((s1 <= s2) ? "True" : "False") << ".\n\n";

    printTestFooter(desc);
}
void testNonPrint()
{
    /*STRING s1;
    for (int i = 0; i <255; i++)
        s1 += char(i);
    cout << s1 << "\n";

    char s2[255];
    int j = 0;
    for (int i = 30; i < 255; i++)
        cout << (char) i;
        j++;
    // cout << s2 << "\n";
    // STRdisplay(s1);
    cout << endl; */
}

void testToggle()
{
    char desc[] = "ToggleCase";
    printTestHeader(desc);

    STRING s1("AbCdEfG");
    cout << "String One: " << s1 << "\n";

    s1.togglecase(0,90);

    cout << "Toggled String: " << s1 << "\n";

    printTestFooter(desc);
}

void testUpcase()
{
    char desc[] = "Upcase";
    printTestHeader(desc);

    STRING s1("abcdef");
    cout << "String One: " << s1 << "\n";

    s1.upcase(0,90);

    cout << "Upcased String: " << s1 << "\n";

    printTestFooter(desc);
}

void testDowncase()
{
    char desc[] = "Downcase";
    printTestHeader(desc);

    STRING s1("ABCDEF");
    cout << "String One: " << s1 << "\n";

    s1.downcase(0,8);

    cout << "Downcased String: " << s1 << "\n";

    printTestFooter(desc);
}

void compoundAddAssignOpTestchar()
{
    char desc[] = "+= Operator (char)";
    printTestHeader(desc);

    STRING s1("Foo");
    cout << "String One: " << s1 << "\n";

    s1 += 'b';

    cout << "Combined String: " << s1 << "\n";
    cout << "String One: " << s1 << "\n\t Length: " << s1.length() << "\n";

    printTestFooter(desc);
}


void compoundAddAssignOpTestcharstar()
{
    char desc[] = "+= Operator (char*)";
    printTestHeader(desc);

    STRING s1("FooFooFooFooFooFooFooFooFooFoo");
    cout << "String One: " << s1 << "\n";

    s1 += "BarbarbarBARBARBARBARBARBARBARBARBARB";

    cout << "Combined String: " << s1 << "\n";
    cout << "String One: " << s1 << "\n\t Length: " << s1.length() << "\n";

    printTestFooter(desc);
}

void compoundAddAssignOpTest()
{
    char desc[] = "+= Operator";
    printTestHeader(desc);

    STRING s1("FooFoo");
    cout << "String One: " << s1 << "\n";
    STRING s2("BarBarBarBarBarbbarbarbarbarb");
    cout << "String Two: " << s2 << "\n";

    s1 += s2;

    cout << "Combined String: " << s1 << "\n";
    cout << "String One: " << s1 << "\n\t Length: " << s1.length() << "\n";
    cout << "String Two: " << s2 << "\n\t Length: " << s2.length() << "\n";

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
    char desc[] = "!= Operator";
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
    unsigned index = 0;
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
