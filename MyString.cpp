/*****************************************************

    Zack Garza
    CISP 430 - TTH 5:30 pm
    Programming Project 2 - Classes
    September 12, 2013

*****************************************************/

#include <iostream>
#include "MyString.h"

using namespace std;

//          Constructors / Destructor               //
/****************************************************/

// This constructor will initialize an empty STRING.
STRING::STRING()
{
    this->len = 0;
    contents = new char[0];
}

// This constructor will take a char* and use it to initialize the
// STRING.
STRING::STRING(const char* cstr)
{
    unsigned i = 0;
    unsigned cstrLength = 0;

    // Count the characters in cstr to find the minimum amount of memory necessary.
    while (cstr[i] != '\0')
    {
        cstrLength++; i++;
    }
    contents = new char[cstrLength];
    this->len = cstrLength;

    // Letter by letter assignment
    for (i = 0; i < cstrLength; i++)
    {
        this->contents[i] = cstr[i];
    }
}


// This constructor will take a char and use it to initialize the
// STRING.
STRING::STRING(const char c)
{
    this->len = 1;
    contents = new char[this->len];
    this->contents[0] = c;
}


// This constructor will take a STRING and use it to initialize
// the STRING. This is called the copy constructor.
STRING::STRING(const STRING& s)
{
    this->len = s.len;
    contents = new char[s.len];
    for (unsigned i = 0; i < s.len; i++)
    {
        this->contents[i] = s.contents[i];
    }
}


// The destructor.
STRING::~STRING()
{
    delete[] contents;
}



//                  Member Functions                //
/****************************************************/

// This will return the number of characters in the STRING.
unsigned STRING::length() const
{
    return this->len;
}


// Assignment ( = ) operator
// This operator assigns one STRING to another.
    // if (this == &right_argument)
    //  return *this{}
    // 1.  Deallocate any memory that MyClass is using internally
    // 2.  Allocate some memory to hold the contents of rhs
    // 3.  Copy the values from rhs into this instance
    // 4.  Return *this
STRING& STRING::operator = (const STRING &right_argument)
{

}


// This will return the position of the first occurrence of char in
// the STRING as an int. Returns -1 if the char is not in the STRING.
int STRING::position(const char c)
{
    for (unsigned i = 0; i <= this->len; i++)
    {
        if (contents[i] == c) return i;
    }
    // Character not found.
    return -1;
}


// Immediate concatenation ( += ) operator{}
// This operator will be overloaded to
// work with a right hand value of either type STRING, type char* or type char.
STRING& STRING::operator += (const STRING &right_argument)
{

}


// Index ( [ ] ) operator{}
// This operator returns one character through indexing. An
// error is handled if the index is out of range. This is to be overloaded with a
// const and non-const version.
// Bounds checks must be done on these to make sure this index is in range.
int STRING::operator [] (const int index)
{
    if (index >= this->len || index < 0) return -1;
    else return this->contents[index];
}


// This function will change all
// alphabetic characters to upper case.
// Functions 11,12, & 13 will work on the character at index first through, but not including, the character at index
// last. Bounds checks must be done on these to make sure they are in range.
void STRING::upcase(unsigned first, unsigned last)
{

}


// This function will change
// all alphabetic characters to lower case.
void STRING::downcase(unsigned first, unsigned last)
{

}


// This function will
// change the case of all alphabetic characters.
void STRING::togglecase(unsigned first, unsigned last)
{

}



//               Comparison / Friend Functions      //
/****************************************************/

// Output stream ( << ) operator{}
// This operator will return an ostream.
std::ostream& operator << (ostream &out, const STRING &right_argument)
{
    for (unsigned i = 0; i < right_argument.len; i++)
    {
        out << right_argument.contents[i];
    }
    return out;
}


// Input stream ( >> ) operator{}
// This operator will return an istream.
std::istream& operator >> (istream &in, const STRING &right_argument)
{
    for (unsigned i = 0; i < right_argument.len; i++)
    {
        in >> right_argument.contents[i];
    }
    return in;
}


// Comparison ( == ) operator{}
// (see note below for all comparison operators)
bool STRING::operator == (const STRING &left_argument) const
{
    if  (this->len != left_argument.len) return false;
    for (unsigned i = 0; i < this->len; i++)
    {
        if (this->contents[i] != left_argument.contents[i]) return false;
    }
    return true;
}

// Comparison ( != ) operator{}
bool operator != (const STRING &left_argument, const STRING &right_argument)
{
    return !(left_argument == right_argument);
}

// Comparison ( > ) operator{}
bool operator > (const STRING &left_argument, const STRING &right_argument)
{

}

// Comparison ( < ) operator{}
bool operator < (const STRING &left_argument, const STRING &right_argument)
{

}

// Comparison ( <= ) operator{}
bool operator <= (const STRING &left_argument, const STRING &right_argument)
{

}

// Comparison ( >= ) operator{}
bool operator >= (const STRING &left_argument, const STRING &right_argument)
{

}

// Concatenation ( + ) operator{}
STRING STRING::operator + (const STRING &right_argument)
{
    unsigned right_arg_length = right_argument.length();
    unsigned left_arg_length = this->length();
    unsigned newSTRlen = left_arg_length + right_arg_length;

    STRING temp;
    temp.contents = new char[newSTRlen];
    temp.len = newSTRlen;

    for (unsigned i = 0; i < left_arg_length; i++)
    {
        temp.contents[i] = this->contents[i];
    }

    for (unsigned i = 0; i < right_arg_length; i++)
    {
        temp.contents[i + left_arg_length] = right_argument.contents[i];
    }
    return temp;
}


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

// Helper Functions //
void STRdisplay(const STRING& s)
{
    for (unsigned i = 0; i < s.len; i++)
    {
        cout << s.contents[i];
    }
}
