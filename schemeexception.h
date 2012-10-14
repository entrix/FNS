#ifndef SCHEMEEXCEPTION_H
#define SCHEMEEXCEPTION_H

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class SchemeException
{
    string *msg;
public:
    SchemeException(string *msg);
    virtual const string* message() const throw();
};

#endif // SCHEMEEXCEPTION_H
