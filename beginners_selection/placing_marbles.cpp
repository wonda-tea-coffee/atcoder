#include <iostream>
#include <string>
using namespace std;

int main()
{
  int s;

  cin >> s;
  int ans = 0;
  while (s > 0)
  {
    ans += s % 10;
    s /= 10;
  }

  cout << ans << endl;

  return 0;
}