/* Interface module for RegDog */
#ifndef _REGISTERED_DOG_H_
#define _REGISTERED_DOG_H_

#include "Dog.h"

#include <iostream>
using std::ostream;

class RegDog : public Dog {
protected:
  int id;

public:
  RegDog(const char *nval, int aval, int ival);
  RegDog();

  void set_id(int newid);
  int get_id() const { return id; }
  void display(ostream &ostr) const;
};

#endif
