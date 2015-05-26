#include <iostream>
using namespace std;


int fibonacci(int n)
{
   if ( n == 0 )
      return 0;
   else if ( n == 1 )
      return 1;
   else
      return (fibonacci(n-1) + fibonacci(n-2));
}

main()
{
   int i = 0, c =1;
   do
   {
      cout << fibonacci(i) << endl;
      i++;
      c++;
   } while (c <= 10);

   return 0;
}