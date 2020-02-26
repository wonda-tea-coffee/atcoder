#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  int a[2][100];
  for (int i = 0; i < n; i++)
  {
    cin >> a[0][i];
  }
  for (int i = 0; i < n; i++)
  {
    cin >> a[1][i];
  }
  int dp[2][100] = {{0}};

  dp[0][0] = a[0][0];
  dp[1][0] = dp[0][0] + a[1][0];
  for (int i = 1; i < n; i++)
  {
    dp[0][i] += dp[0][i - 1] + a[0][i];
  }

  for (int i = 1; i < n; i++)
  {
    dp[1][i] = max(dp[0][i], dp[1][i - 1]) + a[1][i];
  }

  // for (int i = 0; i < 2; i++)
  // {
  //   for (int j = 0; j < n; j++)
  //   {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  cout << dp[1][n - 1] << endl;
}