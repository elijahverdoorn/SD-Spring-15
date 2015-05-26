/* Interface module for a class representing an array of Dog
   implemented as an array of pointers to Dog
   RAB  CS 272  4/14/98 rev 3/00 */

#ifndef _DOG_ARRAY_P_
#define _DOG_ARRAY_P_

#include "Dog.h"

#include <iostream>
using std::ostream;

class DogArrayP {
protected:
  Dog **vec;  
  int size;
  static const int DEFAULT_SIZE;

public:
  DogArrayP(int sz) { init(sz); }
  DogArrayP(void) { init(DEFAULT_SIZE); }
  DogArrayP(const DogArrayP &dap) { copy(dap); }

  ~DogArrayP(void);

  DogArrayP &operator=(const DogArrayP &dap);
  Dog &operator[](int index);
  const Dog &operator[](int index) const { return operator[](index); }

  void display(ostream &ostr) const;
  int get_size(void) const { return size; }

protected:  
  /* helper methods */
  void init(int sz);
  void copy(const DogArrayP &dap);
  void deallocate(void);
};

ostream &operator<<(ostream &ostr, const DogArrayP &dap);

#endif 
