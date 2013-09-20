/*****************************************************

    Zack Garza
    CISP 430 - TTH 5:30 pm
    Programming Project 2 - Classes
    September 12, 2013

*****************************************************/
#ifndef MY_STRING_CLASS_H
#define MY_STRING_CLASS_H
#endif

const unsigned MAX_STR_LENGTH = 0;
// Class Invariants: //



class STRING {
    unsigned len;
    char* contents;
    public:




//          Constructors / Destructor               //
/****************************************************/
// Pre:
// Post:
//
STRING();
// This constructor will initialize an empty STRING.
/**********************************************/


/**********************************************/
// Pre:
// Post:
//
STRING(const char*);
// This constructor will take a char* and use it to initialize the
// STRING.
/**********************************************/


/**********************************************/
// Pre:
// Post:
//
STRING(const char);
// This constructor will take a char and use it to initialize the
// STRING.
/**********************************************/


/**********************************************/
// Pre:
// Post:
//
STRING(const STRING&);
// This constructor will take a STRING and use it to initialize
// the STRING. This is called the copy constructor.
/**********************************************/


/**********************************************/
// Pre:
// Post:
//
~STRING();
// The destructor.
/**********************************************/







//                  Member Functions                //
/****************************************************/

/**********************************************/
// Pre:
// Post:
//
unsigned length();
// This will return the number of characters in the STRING.
/**********************************************/

/**********************************************/
// Pre:
// Post:
//
// Assignment ( = ) operator
STRING& operator = (const STRING &right_argument);
// This operator assigns one STRING to another.
    // if (this == &right_argument)
    //  return *this;
    // 1.  Deallocate any memory that MyClass is using internally
    // 2.  Allocate some memory to hold the contents of rhs
    // 3.  Copy the values from rhs into this instance
    // 4.  Return *this
/**********************************************/


/**********************************************/
// Pre:
// Post:
//
int position(const char);
// This will return the position of the first occurrence of char in
// the STRING as an int. Returns -1 if the char is not in the STRING.
/**********************************************/


/**********************************************/
// Pre:
// Post:
//
STRING& operator += (const STRING &right_argument);
// Immediate concatenation ( += ) operator;
// This operator will be overloaded to
// work with a right hand value of either type STRING, type char* or type char.
/**********************************************/


/**********************************************/
// Pre:
// Post:
//
char operator [] (const STRING &right_argument);
// Index ( [ ] ) operator;
// This operator returns one character through indexing. An
// error is handled if the index is out of range. This is to be overloaded with a
// const and non-const version.
// Bounds checks must be done on these to make sure this index is in range.
/**********************************************/


/**********************************************/
// Pre:
// Post:
//
void upcase(unsigned first, unsigned last);
// This function will change all
// alphabetic characters to upper case.
// Functions 11,12, & 13 will work on the character at index first through, but not including, the character at index
// last. Bounds checks must be done on these to make sure they are in range.
/**********************************************/


/**********************************************/
// Pre:
// Post:
//
void downcase(unsigned first, unsigned last);
// This function will change
// all alphabetic characters to lower case.
/**********************************************/


/**********************************************/
// Pre:
// Post:
//
void togglecase(unsigned first, unsigned last);
// This function will
// change the case of all alphabetic characters.
/**********************************************/

//           Comparison / Friend Functions          //
/****************************************************/
// Two STRINGs will be said to be equal if they contain exactly the same characters, for
// example, "abc" == "abc" but "ABC" != "abc". The operators, ">", "<", ">=",
// and "<=" will compare the STRINGs alphabetically, for example, "a" < "b", "A" < "B", "A"
// < "a", "a" < "B", and "ab" < "abc". Notice that the numerical (ASCII) value of a
// character decides its position when comparing upper to lower case of the same letter,
// e.g., "A" < "a", but it does not when comparing differing letters, e.g., "a" < "B". All non-
// alphabetic characters will be compared by their ASCII values.

// YOU ARE TO IMPLEMENT A MINIMUM NUMBER (2) OF THE COMPARISON OPERATORS AND USE
// THESE TO IMPLEMENT THE OTHERS. IMPLEMENT OPERATOR== AND OPERATOR>. USE THESE TO
// IMPLEMENT ALL OF THE OTHER COMPARISON OPERATORS.

/**********************************************/
// Pre:
// Post:
//
friend std::ostream& operator << (std::ostream &out, const STRING &right_argument);
// Output stream ( << ) operator;
// This operator will return an ostream.
/**********************************************/


/**********************************************/
// Pre:
// Post:
//
friend std::istream& operator >> (std::istream &in, const STRING &right_argument);
// Input stream ( >> ) operator;
// This operator will return an istream.
/**********************************************/


/**********************************************/
// Pre:
// Post:
//
bool operator == (const STRING &right_argument);
// Comparison ( == ) operator;
// (see note below for all comparison operators)
/**********************************************/


/**********************************************/
// Pre:
// Post:
//
friend bool operator != (const STRING &left_argument, const STRING &right_argument);
// Comparison ( != ) operator;
/**********************************************/


/**********************************************/
// Pre:
// Post:
//
friend bool operator > (const STRING &left_argument, const STRING &right_argument);
// Comparison ( > ) operator;
/**********************************************/


/**********************************************/
friend bool operator < (const STRING &left_argument, const STRING &right_argument);
// Pre:
// Post:
//
// Comparison ( < ) operator;
/**********************************************/


/**********************************************/
// Pre:
// Post:
//
friend bool operator <= (const STRING &left_argument, const STRING &right_argument);
// Comparison ( <= ) operator;
/**********************************************/


/**********************************************/
// Pre:
// Post:
//
friend bool operator >= (const STRING &left_argument, const STRING &right_argument);
// Comparison ( >= ) operator;
/**********************************************/


/**********************************************/
// Pre:
// Post:
//
friend STRING& operator + (const STRING &left_argument, const STRING &right_argument);
// Concatenation ( + ) operator;
/**********************************************/




//               Extra Credit Functions             //
/****************************************************/
// Pre:
// Post:
//
// STRING& operator char*(const STRING &right_argument);
// operator char*();
// This will cast our STRING to a char*.
/**********************************************/


/**********************************************/
// Pre:
// Post:
//
// STRING& operator int(const STRING &right_argument);
// operator int();
// This will cast our STRING to an int if possible. It will return 0
// if unsuccessful.
/**********************************************/

/**********************************************/
// Pre:
// Post:
//
// STRING& operator float(const STRING &right_argument);
// operator float();
// This will cast our STRING to a float if possible. It will
// return 0 if unsuccessful.
/**********************************************/

// Helper Functions //
friend void STRdisplay(const STRING&);
};
