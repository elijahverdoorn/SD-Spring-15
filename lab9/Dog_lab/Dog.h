/* Example interface module for CS 272
   R. Brown, 2/98 */

#ifndef _DOG_H_
#define _DOG_H_

#include <iostream>
using std::ostream;

/* "Dog" class */

class Dog {
protected:
  char *name;
  int age;

public:
  Dog(const char *n, int a) { init(n, a); }
  Dog() { init("", 0); }
  Dog(const Dog &dog) { init(dog.name, dog.age); }

  ~Dog();

  Dog &operator=(const Dog &dog);
  void display(ostream &ostr) const;

  const char *get_name(void) const { return name; }
  int get_age(void) const { return age; }

  void set_name(const char *new_name);
  void birthday(void) { age++; }

protected:
  void init(const char *s, int i);  /* helper func */
};

#endif /* _DOG_H_ */



