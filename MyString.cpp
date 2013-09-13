/*****************************************************

    Zack Garza
    CISP 430 - TTH 5:30 pm
    Programming Project 2 - Classes
    September 12, 2013

*****************************************************/

#include <iostream>
#include "MyString.h"
using namespace std;

/*****************************************************

    Zack Garza
    CISP 430 - TTH 5:30 pm
    Programming Project 2 - Classes
    September 12, 2013

*****************************************************/

//          Constructors / Destructor               //
/****************************************************/
STRING::STRING()
{

}
// This constructor will initialize an empty STRING.


STRING::STRING(char*)
{

}
// This constructor will take a char* and use it to initialize the
// STRING.


STRING::STRING(char)
{

}
// This constructor will take a char and use it to initialize the
// STRING.


STRING::STRING(const STRING&)
{

}
// This constructor will take a STRING and use it to initialize
// the STRING. This is called the copy constructor.


STRING::~STRING()
{

}
// The destructor.



//                  Member Functions                //
/****************************************************/
unsigned STRING::length()
{

}
// This will return the number of characters in the STRING.


// Assignment ( = ) operator
STRING& STRING::operator = (const STRING &right_argument)
{

}
// This operator assigns one STRING to another.
    // if (this == &right_argument)
    //  return *this{}
    // 1.  Deallocate any memory that MyClass is using internally
    // 2.  Allocate some memory to hold the contents of rhs
    // 3.  Copy the values from rhs into this instance
    // 4.  Return *this


unsigned STRING::position(char)
{

}
// This will return the position of the first occurrence of char in
// the STRING as an int. Returns -1 if the char is not in the STRING.


STRING& STRING::operator += (const STRING &right_argument)
{

}
// Immediate concatenation ( += ) operator{}
// This operator will be overloaded to
// work with a right hand value of either type STRING, type char* or type char.


char STRING::operator [] (const STRING &right_argument)
{

}
// Index ( [ ] ) operator{}
// This operator returns one character through indexing. An
// error is handled if the index is out of range. This is to be overloaded with a
// const and non-const version.
// Bounds checks must be done on these to make sure this index is in range.


void STRING::upcase(unsigned first, unsigned last)
{

}
// This function will change all
// alphabetic characters to upper case.
// Functions 11,12, & 13 will work on the character at index first through, but not including, the character at index
// last. Bounds checks must be done on these to make sure they are in range.


void STRING::downcase(unsigned first, unsigned last)
{

}
// This function will change
// all alphabetic characters to lower case.


void STRING::togglecase(unsigned first, unsigned last)
{

}
// This function will
// change the case of all alphabetic characters.


//               Comparison / Friend Functions      //
/****************************************************/
std::ostream& operator << (ostream &out, const STRING &right_argument)
{
}
// Output stream ( << ) operator{}
// This operator will return an ostream.

std::istream& operator >> (istream &in, const STRING &right_argument)
{
}

// Input stream ( >> ) operator{}
// This operator will return an istream.

// STRING& STRING::operator == (const STRING &right_argument)
bool operator == (const STRING &left_argument, const STRING &right_argument)
{

}
// Comparison ( == ) operator{}
// (see note below for all comparison operators)

bool operator != (const STRING &left_argument, const STRING &right_argument)
{

}
// Comparison ( != ) operator{}

bool operator > (const STRING &left_argument, const STRING &right_argument)
{

}
// Comparison ( > ) operator{}

bool operator < (const STRING &left_argument, const STRING &right_argument)
{

}
// Comparison ( < ) operator{}

bool operator <= (const STRING &left_argument, const STRING &right_argument)
{

}
// Comparison ( <= ) operator{}

bool operator >= (const STRING &left_argument, const STRING &right_argument)
{

}
// Comparison ( >= ) operator{}

STRING& operator + (const STRING &left_argument, const STRING &right_argument)
{

}
// Concatenation ( + ) operator{}


//               Extra Credit Functions             //
/****************************************************/
// STRING& STRING::operator char*(const STRING &left_argument, const STRING &right_argument){}
// This will cast our STRING to a char*.

// STRING& STRING::operator int(const STRING &left_argument, const STRING &right_argument){}
// This will cast our STRING to an int if possible. It will return 0
// if unsuccessful.

// STRING& STRING::operator float(const STRING &left_argument, const STRING &right_argument){}
// This will cast our STRING to a float if possible. It will
// return 0 if unsuccessful.
