#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 0; i < n; i++)
  {
    int b;
    cin >> b;
    a.push_back(b);
  }

  int ans = 1000000;
  for (int i = 0; i < n; i++)
  {
    int cnt = 0;
    while (a.at(i) % 2 == 0)
    {
      a.at(i) /= 2;
      cnt++;
    }
    ans = min(ans, cnt);
  }

  cout << ans << endl;

  return 0;
}