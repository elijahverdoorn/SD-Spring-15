/* Example interface module for subclass and enum type
   CS 272, R. Brown, 3/99 */

#ifndef _OWNED_DOG_H_
#define _OWNED_DOG_H_

#include "Dog.h"

/* "OwnedDog" class */

class OwnedDog : public Dog {
protected:
  char *owner;

public:
  OwnedDog(const Dog &dog, const char *own)
    : Dog(dog) { o_init(own); }
  OwnedDog(void) : Dog() { o_init(""); }
  OwnedDog(const OwnedDog &odog) 
    : Dog(odog) { o_init(odog.owner); }

  ~OwnedDog();

  OwnedDog &operator=(const OwnedDog &odog);
  void display(ostream &ostr) const;

  const char *get_owner(void) const { return owner; }
  void set_owner(const char *new_owner);

protected:
  void o_init(const char *own);  // helper
};

/* output operator */

ostream &operator<<(ostream &ostr, const OwnedDog &d);

#endif /* _OWNED_DOG_H_ */



