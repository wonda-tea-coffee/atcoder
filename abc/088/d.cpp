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
  ll cntw = 0;
  vector<string> grid(h);
  rep(i, h) {
    cin >> grid[i];
    rep(j, w) if (grid[i][j] == '.') cntw++;
  }

  const ll MAX = 50;
  ll mins[MAX][MAX] = {{}};
  rep(i, MAX)rep(j, MAX) mins[i][j] = INF;

  queue<ll> qx, qy, qc;
  qx.push(0); qy.push(0); qc.push(0);
  mins[0][0] = 0;

  while (!qx.empty()) {
    ll x = qx.front(); qx.pop();
    ll y = qy.front(); qy.pop();
    ll c = qc.front(); qc.pop();

    if (y == h-1 && x == w-1) {
      outl(cntw - c - 1);
      return;
    }

    for (int i = 0; i < 4; i++) {
      ll nx = x + dx[i];
      ll ny = y + dy[i];
      if (nx >= 0 && nx < w && ny >= 0 && ny < h && grid[ny][nx] == '.' && c + 1 < mins[ny][nx]) {
        mins[ny][nx] = c + 1;
        qx.push(nx);
        qy.push(ny);
        qc.push(c+1);
      }
    }
  }

  outl(-1);
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
