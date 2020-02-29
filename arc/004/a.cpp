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

double dist(int x1, int y1, int x2, int y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N; cin >> N;
  int x[N], y[N];
  REP(i, N) cin >> x[i] >> y[i];

  double ans = 0;

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      ans = max(ans, dist(x[i], y[i], x[j], y[j]));
    }
  }

  cout << ans << endl;
}