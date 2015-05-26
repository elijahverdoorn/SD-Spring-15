/* Implementation module for a class representing an array of Dog
   implemented as an array of pointers to Dog
   CS 272  4/14/98 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

#include <cstring>
#include <cassert>
#include "DogArrayP.h"

/* initialization of class variable */

const int DogArrayP::DEFAULT_SIZE = 10;

/* helper methods */

/* init
   Arguments:
     sz, integer, size of array to initialize
   State change:  An array of pointers to Dog of size sz is allocated  
     and initialized to 0.  The state variable size is assigned the 
     value sz.
   Return:  None. */

void DogArrayP::init(int sz)
{
  assert(0 <= sz);
  size = sz;
  vec = new Dog*[sz];
  int i = 0;
  /* LI:  first i locations have been initialized to 0 
     AND 0 <= i <= size */
  while (i < sz)
    vec[i++] = 0;
}

/* copy -- helper method
     Argument
       dap -- DogArrayP object to be copied
     State change:  This instance of DogArrayP is allocated and 
       initialized to be a copy of dap.
     Return:  None. */

void DogArrayP::copy(const DogArrayP &dap)
{
  size = dap.size;
  vec = new Dog*[size];
  
  int k = 0;
  /* LI:  the first k elements of dap have been copied, with 
     new allocation for all Dogs copied AND 0 <= k <= size */
  while (k < size) {
    if (dap.vec[k] == 0)
      vec[k] = 0;
    else
      vec[k] = new Dog(*dap.vec[k]);
    k++;
  }
}

/* destructor */

DogArrayP::~DogArrayP(void)
{ 
  //cout << "~DogArrayP()" << endl;
  deallocate(); 
}


/* deallocate -- helper method
     Arguments:  None.
     State change:  All dynamically allocated memory for this instance
       of DogArrayP is deallocated
     Return:  None. */

void DogArrayP::deallocate(void)
{
  int k = 0;
  /* LI:  Any Dog objects associated with the first k elements of vec
     have been deallocated AND 0 <= k <= size */
  while (k < size) {
    if (vec[k] != 0) 
      delete vec[k];
    k++;
  }
      
  delete [] vec;
  vec = 0;  /* defensive programming */
}

/* operators and methods */

DogArrayP &DogArrayP::operator=(const DogArrayP &dap)
{
  deallocate();
  copy(dap);
  return *this;
}

Dog &DogArrayP::operator[](int index)
{
  assert(0 <= index && index < size);
  if (vec[index] == 0)
    vec[index] = new Dog;
  return *vec[index];
}

void DogArrayP::display(ostream &ostr) const
{
  ostr << "index name (age)" << endl;
  int k = 0;
  /* LI:  all Dogs among the first k elements of vec have been printed
     AND 0 <= k <= size */
  while (k < size) {
    if (vec[k] != 0) {
      ostr << "  " << k << "  ";
      vec[k]->display(ostr);
      ostr << endl;
    }
    k++;
  }    
}

/* output operator for DogArrayP */

ostream &operator<<(ostream &ostr, const DogArrayP &dap)
{
  dap.display(ostr);
  return ostr;
}

