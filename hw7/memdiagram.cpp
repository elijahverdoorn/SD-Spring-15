#include<iostream>
using namespace std;

int g(int &m, short &n);

int f( int a, short b )
{
  cout << "f: a " << a << " b " << b << endl;
  if ( b > 2 ) return a + b;

  a -= 2;
  g( a, b );

  return 42;
}

int g( int &m, short &n )
{
  cout << "g: m " << m << " n " << n << endl;
  if ( m < 2 ) return n;

  if ( m < 3 ) n -= f(n, m);

  m /= 2;
  n *= 2;
  return g( m, n );
}

int main()
{
  int x = 2;
  short y = 2;
  cout << g(x, y) << endl;
  return 0;
}