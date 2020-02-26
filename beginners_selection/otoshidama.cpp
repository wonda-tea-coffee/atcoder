#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

int main()
{
  double N, Y;
  cin >> N >> Y;
  Y /= 1000;

  int a = ceil((Y - 2 * N) / 5);
  int b = Y - N - 9 * a;

  cout << a << endl;
  cout << b << endl;

  while (b >= 0 && b % 4 > 0)
  {
    a += 1;
    b = Y - N - 9 * a;
  }
  if (b < 0)
  {
    cout << "-1 -1 -1" << endl;
    return 0;
  }

  cout << a << " " << b << " " << N - a - b << endl;
}