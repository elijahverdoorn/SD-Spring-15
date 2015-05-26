#include <iostream>
using namespace std;
#include <math.h>
#include <vector>

main()
{
  int current, count = 0, total = 0;
  vector <int> dataArr;
  while (cin >> current)
  {
    dataArr.push_back(current);
    count++;
  }
  count--;
  for (int k = 0; k <= count; k++)
  {
    total += dataArr.at(k);
  }
  double average = total/count;
  vector <double> diffArr;
  for (int k = 0; k <= count; k++)
  {
    diffArr.push_back(pow((dataArr.at(k) - average), 2));
  }
  double deciTotal;
  for (int k = 0; k <= count; k++)
  {
    deciTotal += diffArr.at(k);
  }
  double out = deciTotal/(count + 1);
  out = sqrt(out);
  cout << out << endl;
  return 0;
}