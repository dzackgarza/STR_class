/*****************************************************

    Zack Garza
    CISP 430 - TTH 5:30 pm
    Programming Project 2 - Classes
    September 12, 2013

*****************************************************/
#ifndef MY_STRING_CLASS_H
#define MY_STRING_CLASS_H
#endif

// Class Invariants: //
//*******************//

class STRING {
    unsigned len;
    char* contents;
    public:
//          Constructors / Destructor               //
/****************************************************/



/****************************************************/
// Pre:
// Post:
// This constructor will initialize an empty STRING.
STRING();
/**********************************************/


/**********************************************/
// Pre:
// Post:
// This constructor will take a char* and use it to initialize the
// STRING.
STRING(const char*);
/**********************************************/


/**********************************************/
// Pre:
// Post:
// This constructor will take a char and use it to initialize the
// STRING.
STRING(const char);
/**********************************************/


/**********************************************/
// Pre:
// Post:
// This constructor will take a STRING and use it to initialize
// the STRING. This is called the copy constructor.
STRING(const STRING&);
/**********************************************/


/**********************************************/
// Pre:
// Post:
// The destructor.
~STRING();
/**********************************************/









//                  Member Functions                //
/****************************************************/

/**********************************************/
// Pre:
// Post:
// This will return the number of characters in the STRING.
unsigned length() const;
/**********************************************/

/**********************************************/
// Pre:
// Post:
// Assignment ( = ) operator
// This operator assigns one STRING to another.
    // if (this == &right_argument)
    //  return *this;
    // 1.  Deallocate any memory that MyClass is using internally
    // 2.  Allocate some memory to hold the contents of rhs
    // 3.  Copy the values from rhs into this instance
    // 4.  Return *this
STRING& operator = (const STRING &right_argument);
STRING& operator = (const char* &right_argument);
STRING& operator = (const char &right_argument);
/**********************************************/


/**********************************************/
// Pre:
// Post:
// This will return the position of the first occurrence of char in
// the STRING as an int. Throws a positive number if the char is not in the STRING.
int position(const char);
/**********************************************/


/**********************************************/
// Pre:
// Post:
// Immediate concatenation ( += ) operator;
// This operator will be overloaded to
// work with a right hand value of either type STRING, type char* or type char.
STRING operator += (const STRING &right_argument);
STRING operator += (const char* &right_argument);
STRING operator += (const char &right_argument);
/**********************************************/


/**********************************************/
// Pre:
// Post:
// Index ( [ ] ) operator;
// This operator returns one character through indexing. An
// error is handled if the index is out of range. This is to be overloaded with a
// const and non-const version.
// Bounds checks must be done on these to make sure this index is in range.
char& operator [] (const int index);
char& operator [] (const int index) const;
/**********************************************/


/**********************************************/
// Pre:
// Post:
// This function will change all
// alphabetic characters to upper case.
// Functions 11,12, & 13 will work on the character at index first through, but not including, the character at index
// last. Bounds checks must be done on these to make sure they are in range.
void upcase(const unsigned first, const unsigned last);
void upcase(); // Upcases the whole string.
/**********************************************/


/**********************************************/
// Pre:
// Post:
// This function will change
// all alphabetic characters to lower case.
void downcase(const unsigned first, const unsigned last);
void downcase(); // Downcases the entire string.
/**********************************************/


/**********************************************/
// Pre:
// Post:
// This function will
// change the case of all alphabetic characters.
void togglecase(const unsigned first, const unsigned last);
void togglecase(); // Toggle entire string.
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
// Output stream ( << ) operator;
// This operator will return an ostream.
friend std::ostream& operator << (std::ostream &out, const STRING &right_argument);
/**********************************************/


/**********************************************/
// Pre:
// Post:
// Input stream ( >> ) operator;
// This operator will return an istream.
friend std::istream& operator >> (std::istream &in, const STRING &right_argument);
/**********************************************/


/**********************************************/
// Pre:
// Post:
// Comparison ( == ) operator;
// (see note below for all comparison operators)
bool operator == (const STRING &right_argument) const;
bool operator == (const char* &left_argument) const;
bool operator == (const char &left_argument) const;
/**********************************************/


/**********************************************/
// Pre:
// Post:
// Comparison ( != ) operator;
friend bool operator != (const STRING &left_argument, const STRING &right_argument);
friend bool operator != (const char* &left_argument, const STRING &right_argument);
friend bool operator != (const STRING &left_argument, const char* &right_argument);\
//todo
friend bool operator != (const char &left_argument, const STRING &right_argument);
friend bool operator != (const STRING &left_argument, const char &right_argument);
/**********************************************/


/**********************************************/
// Pre:
// Post:
// Comparison ( > ) operator;
friend bool operator > (const STRING &left_argument, const STRING &right_argument);
friend bool operator > (const char* &left_argument, const STRING &right_argument);
friend bool operator > (const STRING &left_argument, const char* &right_argument);
//todo
friend bool operator > (const char &left_argument, const STRING &right_argument);
friend bool operator > (const STRING &left_argument, const char &right_argument);
/**********************************************/


/**********************************************/
// Pre:
// Post:
// Comparison ( < ) operator;
friend bool operator < (const STRING &left_argument, const STRING &right_argument);
friend bool operator < (const char* &left_argument, const STRING &right_argument);
friend bool operator < (const STRING &left_argument, const char* &right_argument);
//todo
friend bool operator < (const char &left_argument, const STRING &right_argument);
friend bool operator < (const STRING &left_argument, const char &right_argument);
/**********************************************/


/**********************************************/
// Pre:
// Post:
// Comparison ( <= ) operator;
friend bool operator <= (const STRING &left_argument, const STRING &right_argument);
friend bool operator <= (const char* &left_argument, const STRING &right_argument);
friend bool operator <= (const STRING &left_argument, const char* &right_argument);
//todo
friend bool operator <= (const char &left_argument, const STRING &right_argument);
friend bool operator <= (const STRING &left_argument, const char &right_argument);
/**********************************************/


/**********************************************/
// Pre:
// Post:
// Comparison ( >= ) operator;
friend bool operator >= (const STRING &left_argument, const STRING &right_argument);
friend bool operator >= (const char* &left_argument, const STRING &right_argument);
friend bool operator >= (const STRING &left_argument, const char* &right_argument);
//todo
friend bool operator >= (const char &left_argument, const STRING &right_argument);
friend bool operator >= (const STRING &left_argument, const char &right_argument);
/**********************************************/


/**********************************************/
// Pre:
// Post:
// Concatenation ( + ) operator;
STRING operator + (const STRING &right_argument);
STRING operator + (const char* &right_argument);
STRING operator + (const char &right_argument);
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

bool isEmpty();
};
