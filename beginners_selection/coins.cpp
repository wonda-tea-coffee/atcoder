#include <iostream>
#include <string>
using namespace std;

int main()
{
  int a, b, c, x;
  int ans = 0;
  cin >> a >> b >> c >> x;

  for (int ai = 0; ai <= a; ai++)
  {
    for (int bi = 0; bi <= b; bi++)
    {
      for (int ci = 0; ci <= c; ci++)
      {
        if (ai * 500 + bi * 100 + 50 * ci == x)
        {
          ans++;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}