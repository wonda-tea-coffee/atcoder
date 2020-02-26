#include <iostream>
#include <string>
using namespace std;

int sumOfDigits(int n)
{
  int ret = 0;

  while (n > 0)
  {
    ret += n % 10;
    n /= 10;
  }

  return ret;
}

int main()
{
  int n, a, b;
  cin >> n >> a >> b;

  int ans = 0;

  for (int i = 1; i <= n; i++)
  {
    int sod = sumOfDigits(i);
    if (a <= sod && sod <= b)
    {
      ans += i;
    }
  }

  cout << ans << endl;
  return 0;
}