#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
  int n;
  cin >> n;

  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  set<int> set;
  for (int i = 0; i < n; i++)
  {
    set.insert(a[i]);
  }

  cout << set.size() << endl;
}