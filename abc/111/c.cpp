#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstring>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <regex>
#include <vector>

#define fix(n)          cout<<fixed<<setprecision(n)
#define rep(i,n)        for (int i = 0; i < (n); ++i)
#define all(a)          (a).begin(), (a).end()
#define sort(a)         sort(all(a))
#define uniq(a)         sort(a);(a).erase(unique(all(a), (a).end())
#define reverse(a)      reverse(all(a))
#define ctos(c)         string(1, (c))
#define out(d)          cout << (d)
#define outl(d)         std::cout<<(d)<<"\n"
#define YES()           cout << "YES" << endl
#define NO()            cout << "NO" << endl
#define Yes()           cout << "Yes" << endl
#define No()            cout << "No" << endl
#define ceil(x, y)      ((x + y - 1) / (y))
#define debug(x)        cerr << #x << ": " << (x) << '\n'
#define debug2(x, y)    cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << '\n'
#define debug3(x, y, z) cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << ", " << #z << ": " << (z) << '\n'
#define dbg(v)          for (size_t _ = 0; _ < v.size(); ++_){ cerr << #v << "[" << _ << "] : " << v[_] << '\n'; }

using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;

const ll MOD = 1000000007; // 10^9 + 7
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

void solve() {
  int n; cin >> n;
  const int MAX = 100005;
  vector<int> cntl(MAX, 0), cntr(MAX, 0);
  rep(i, n) {
    int u; cin >> u;
    if (i % 2 == 0) cntl[u]++;
    else cntr[u]++;
  }

  vector<pair<int,int>> x, y;
  for (int i = 1; i <= MAX; i++) {
    if (cntl[i] > 0) x.push_back(make_pair(-cntl[i], i));
    if (cntr[i] > 0) y.push_back(make_pair(-cntr[i], i));
  }
  sort(x); sort(y);

  if (x[0].second == y[0].second) {
    int x1 = x[0].first;
    int y1 = y[0].first;
    int x2 = x.size() > 1 ? x[1].first : 0;
    int y2 = y.size() > 1 ? y[1].first : 0;
    outl(min(n + x1 + y2, n + x2 + y1));
  } else {
    outl(n + x[0].first + y[0].first);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
