#include "schemeexception.h"

SchemeException::SchemeException(string *msg)
{
    this->msg = msg;
}

const string* SchemeException::message() const throw()
{
  return msg;
}
