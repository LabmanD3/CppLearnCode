#ifndef CONSTRUCTOR_H
#define CONSTRUCTOR_H

#include <iostream>

using namespace std;

class String
{
private:
    char *ptr;

public:
    // String() = default;              // default constructor (not used)
    explicit String(int size = 0);      // constructor with parameter
    String(const char *p);              // constructor
    String(const String&);              // copy constructor
    ~String();                          // destructor

    friend ostream& operator<<(ostream &cout, String &s);       // overloaded operator
    String& operator=(const String &s);                         // copy-assginment operator
};


#endif  // CONSTRUCTOR_H