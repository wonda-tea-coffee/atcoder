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
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void solve() {
  ll h, w; cin >> h >> w;
  vector<string> grid(h); rep(i, h) cin >> grid[i];
  const ll MAX = 400;
  bool visited[MAX][MAX] = {{}};
  ll ans = 0;
  rep(i, h)rep(j, w) {
    if (visited[i][j]) continue;
    ll cntw = 0, cnth = 0;

    visited[i][j] = true;
    queue<ll> qx, qy;
    qx.push(j); qy.push(i);
    while (!qx.empty()) {
      ll x = qx.front(); qx.pop();
      ll y = qy.front(); qy.pop();

      if (grid[y][x] == '.') cntw++;
      else cnth++;

      rep(k, 4) {
        ll nx = x + dx[k];
        ll ny = y + dy[k];
        if (nx >= 0 && nx < w && ny >= 0 && ny < h && grid[y][x] != grid[ny][nx] && !visited[ny][nx]) {
          visited[ny][nx] = true;
          qx.push(nx);
          qy.push(ny);
        }
      }
    }

    ans += cntw * cnth;
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
