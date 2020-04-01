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
#define uniq(a)         sort(a);(a).erase(unique(all(a)), (a).end())
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
#define INF             __LONG_LONG_MAX__

using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;

const ll MOD = 1000000007; // 10^9 + 7
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

void solve() {
  ll n, m; cin >> n >> m;
  vector<vector<P>> v(n+1);
  rep(i, m) {
    ll ai, bi; cin >> ai >> bi;
    v[ai].emplace_back(make_pair(bi, i));
    v[bi].emplace_back(make_pair(ai, i));
  }

  ll ans = 0;
  rep(i, m) {
    vector<bool> visited(n+1);
    queue<ll> qx, qc;
    ll start = -1;
    for (int j = 1; j <= n; j++) {
      for (int k = 0; k < v[j].size(); k++) {
        if (v[j][k].second != i) {
          start = j;
          goto START_BFS;
        }
      }
    }
    START_BFS:
    qx.push(start);
    ll cnt = 0;
    visited[start] = true;
    // 辺iを使わずにBFSする
    while (!qx.empty()) {
      ll x = qx.front(); qx.pop();
      cnt++;

      for (int j = 0; j < v[x].size(); j++) {
        ll y = v[x][j].first;
        if (visited[y]) continue;
        if (v[x][j].second == i) continue;

        qx.push(y);
        visited[y] = true;
      }
    }
    if (cnt != n) ans++;
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
