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
#define pb              push_back
#define fst             first
#define int             long long

using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;

const ll MOD = 1000000007; // 10^9 + 7
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

ll d(ll x1, ll y1, ll x2, ll y2) {
  ll v1 = x1 - x2;
  ll v2 = y1 - y2;
  return v1 * v1 + v2 * v2;
}

void solve() {
  int n; cin >> n;
  vector<P> p(n);
  rep(i, n) {
    int xi, yi; cin >> xi >> yi;
    p[i] = make_pair(xi, yi);
  }
  sort(p);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int xi = p[i].first;
    int yi = p[i].second;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      int xj = p[j].first;
      int yj = p[j].second;

      int qx = xj - yj + yi;
      int qy = yj + xj - xi;
      if (!binary_search(all(p), make_pair(qx, qy))) continue;

      int rx = xi - yj + yi;
      int ry = yi + xj - xi;
      if (!binary_search(all(p), make_pair(rx, ry))) continue;

      ans = max(ans, abs(xj-xi)*abs(xj-xi) + abs(yj-yi)*abs(yj-yi));
    }
  }
  outl(ans);
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
