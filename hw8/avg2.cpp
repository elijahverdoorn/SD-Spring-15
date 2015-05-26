#include<iostream>
using namespace std;

double averageOf(float dat[], int nelts, float &minVal)
{
  double result = 0;
  minVal = dat[0];
  for(int i = 0; i < nelts; ++i) {
    if ( dat[i] < minVal ) minVal = dat[i];
    result += dat[i];
  }
  result /= nelts;
  return result;
}

int main()
{
  float minimum, mydata[225];
  int k=0;
  while(k <=224)
  {
    cin >> mydata[k];
    k++;
  }
  double avg;

  avg = averageOf(mydata, 225, minimum);

  cout << "avg " << avg << " minimum value " << minimum << endl;
}