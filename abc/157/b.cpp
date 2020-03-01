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
#include <vector>

#define REP(i,n)   for (int i = 0; i < (n); ++i)
#define SORT(a)    sort((a).begin(), (a).end());
#define UNIQ(a)    SORT(a);(a).erase(unique((a).begin(), (a).end()), (a).end());
#define FIND(a,x)  find((a).begin(), (a).end(), (x)) != (a).end()
#define REVERSE(a) reverse((a).begin(), (a).end());

using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MOD = 1000000007; // 10^9 + 7

int a[3][3] = {};

bool check() {
  bool f = true;
  for (int i = 0; i < 3; i++) {
    f = true;
    for (int j = 0; j < 3; j++)
      f &= a[i][j] == 0;
    if (f) return true;
  }

  for (int i = 0; i < 3; i++) {
    f = true;
    for (int j = 0; j < 3; j++)
      f &= a[j][i] == 0;
    if (f) return true;
  }

  f = true;
  for (int i = 0; i < 3; i++) {
    f &= a[i][i] == 0;
  }
  if (f) return true;

  f = true;
  for (int i = 2; i >= 0; i--) {
    f &= a[i][3 - i - 1] == 0;
  }
  if (f) return true;

  return false;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  REP(i, 3)REP(j, 3) cin >> a[i][j];
  int n; cin >> n;
  REP(i, n) {
    int b; cin >> b;
    REP(j, 3)REP(k, 3) {
      if (a[j][k] == b) {
        a[j][k] = 0;
      }
    }
  }

  cout << (check() ? "Yes" : "No") << endl;
}
