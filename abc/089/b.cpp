#include <bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    string S;
    cin >> S;

    if (S == "Y")
    {
      cout << "Four" << endl;
      break;
    }
    if (i == N - 1)
    {
      cout << "Three" << endl;
    }
  }
}
