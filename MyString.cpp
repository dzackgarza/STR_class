/*****************************************************

    Zack Garza
    CISP 430 - TTH 5:30 pm
    Programming Project 2 - Classes
    September 12, 2013

*****************************************************/

#include <iostream>
#include "MyString.h"

using namespace std;
int objectCount = 0;

//          Constructors / Destructor               //
/****************************************************/

// This constructor will initialize an empty STRING.
STRING::STRING()
{
    this->len = 0;
    contents = new char[0];
    objectCount++;

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
    this->contents = new char[cstrLength];
    this->len = cstrLength;

    // Letter by letter assignment
    for (i = 0; i < cstrLength; i++)
    {
        this->contents[i] = cstr[i];
    }
    objectCount++;
}


// This constructor will take a char and use it to initialize the
// STRING.
STRING::STRING(const char c)
{
    this->len = 1;
    contents = new char[this->len];
    this->contents[0] = c;
    objectCount++;

}


// This constructor will take a STRING and use it to initialize
// the STRING. This is called the copy constructor.
STRING::STRING(const STRING& s)
{
    this->len = s.len;
    this->contents = new char[s.len];
    for (unsigned i = 0; i < s.len; i++)
    {
        this->contents[i] = s.contents[i];
    }
    objectCount++;

}


// The destructor.
STRING::~STRING()
{
    //cout << "Destructor called on String: ";
    //STRdisplay(*this); cout << endl;
    objectCount--;
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
    // 1.  Deallocate any memory that STRING is using internally
    // 2.  Allocate some memory to hold the contents of the new STRING
    // 3.  Copy the values from into this instance
    // 4.  Return *this
STRING& STRING::operator = (const STRING &right_argument)
{
    if (this == &right_argument) return *this;

    delete[] this->contents;
    this->contents = new char [right_argument.len];

    for (unsigned i = 0; i < right_argument.len; i++)
    {
        this->contents[i] = right_argument.contents[i];
    }
    this->len = right_argument.len;
    return *this;
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
    throw int(1);
}


// Immediate concatenation ( += ) operator{}
// This operator will be overloaded to
// work with a right hand value of either type STRING, type char* or type char.
STRING STRING::operator += (const STRING &right_argument)
{
    unsigned newLength = this->len + right_argument.length();
    char temp[this->len];

    // Copy the left hand argument into a temporary char array
    // so we can delete its contents and reallocate more memory
    for(unsigned i = 0; i < this->len; i++)
    {
        temp[i] = this->contents[i];
    }
    delete[] this->contents;
    this->contents = new char[newLength];

    unsigned i = 0;
    // Copy the first string's contents back in.
    while (i < this->len)
    {
        this->contents[i] = temp[i];
        i++;
    }
    // Copy the second string's contents in.
    for (unsigned j = 0; j < right_argument.length(); j++)
    {
        this->contents[i + j] = right_argument.contents[j];
    }

    this->len = newLength;
    return *this;
}

STRING STRING::operator += (const char* &right_argument)
{
    *this += STRING(right_argument);
    return *this;
}

STRING STRING::operator += (const char &right_argument)
{
    *this += STRING(right_argument);
    return *this;
}




// Index ( [ ] ) operator{}
// This operator returns one character through indexing. An
// error is handled if the index is out of range. This is to be overloaded with a
// const and non-const version.
// Bounds checks must be done on these to make sure this index is in range.
int STRING::operator [] (const int index)
{
    if (index >= (int)this->len || index < 0) throw int(1);
    else return this->contents[index];
}

int STRING::operator [] (const int index) const
{
    if (index >= (int)this->len || index < 0) throw int(1);
    else return this->contents[index];
}


// This function will change all
// alphabetic characters to upper case.
// Functions 11,12, & 13 will work on the character at index first through, but not including, the character at index
// last. Bounds checks must be done on these to make sure they are in range.
void STRING::upcase(const unsigned first, const unsigned last)
{
    for (unsigned i = first; i < last && i <= this->len && i >= 0; i++)
    {
        if (this->contents[i] >= 'a' && this->contents[i] <= 'z')
        {
            this->contents[i] &= ('A' - 'a' - 1);    // 223 = 1101 1111; Equivalent to subtracting 32 from ASCII value by clearing the 5th bit.
        }
    }
}



// This function will change
// all alphabetic characters to lower case.
void STRING::downcase(const unsigned first, const unsigned last)
{
    for (unsigned i = first; i < last && i <= this->len && i >= 0; i++)
    {
        if (this->contents[i] >= 'A' && this->contents[i] <= 'Z')
        {
            this->contents[i] |= 'a'-'A'; // 32 = 0010 0000; Equivalent to adding 32 to ASCII value by setting the 5th bit.
        }
    }
}


// This function will
// change the case of all alphabetic characters.
void STRING::togglecase(unsigned first, unsigned last)
{
    for (unsigned i = first; i < last && i <= this->len && i >= 0; i++)
    {
        if (this->contents[i] >= 'A' && this->contents[i] <= 'Z') // Is it an uppercase letter?
        {
            this->contents[i] |= 'a'-'A'; // Send it to lowercase
        }
        else if (this->contents[i] >= 'a' && this->contents[i] <= 'z')  // Is it a lowercase letter?
        {
            this->contents[i] &= ('A' - 'a' - 1);    // Send it to uppercase
        }
    }
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
    return true;
}

// Comparison ( < ) operator{}
bool operator < (const STRING &left_argument, const STRING &right_argument)
{
    return true;
}

// Comparison ( <= ) operator{}
bool operator <= (const STRING &left_argument, const STRING &right_argument)
{
    return true;
}

// Comparison ( >= ) operator{}
bool operator >= (const STRING &left_argument, const STRING &right_argument)
{
    return true;
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

bool STRING::isEmpty()
{
    return (this->len == 0);
}
