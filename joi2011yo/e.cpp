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
  ll h, w, s; cin >> h >> w >> s;
  vector<string> grid(h); rep(i, h) cin >> grid[i];
  vector<ll> vy(s + 1), vx(s + 1);
  rep(i, h)rep(j, w) {
    if (grid[i][j] == 'X' || grid[i][j] == '.') continue;

    if (grid[i][j] == 'S') { vy[0] = i; vx[0] = j; }
    else {
      ll g = grid[i][j] - '0';
      vy[g] = i;
      vx[g] = j;
    }
  }

  ll ans = 0;
  vector<vector<ll>> mins_orig(h);
  rep(i, h) mins_orig[i].resize(w);
  rep(i, h)rep(j, w) mins_orig[i][j] = INF;

  vector<vector<ll>> mins(h);
  rep(i, h) mins[i].resize(w);

  for (int i = 1; i <= s; i++) {
    copy(all(mins_orig), mins.begin());

    // (vy[i-1], vx[i-1])から(vy[i], vx[i])を目指す
    // debug2(vy[i-1], vx[i-1]);
    // debug2(vy[i], vx[i]);
    ll cnt = 0;
    queue<ll> qx, qy, qc;
    qx.push(vx[i-1]);
    qy.push(vy[i-1]);
    qc.push(0);
    mins[vy[i-1]][vx[i-1]] = 0;

    while (!qx.empty()) {
      ll x = qx.front(); qx.pop();
      ll y = qy.front(); qy.pop();
      ll c = qc.front(); qc.pop();
      // debug3(x, y, c);

      if (x == vx[i] && y == vy[i]) {
        ans += c;
        break;
      }

      for (int j = 0; j < 4; j++) {
        int nx = x + dx[j];
        int ny = y + dy[j];
        // debug2(nx, ny);
        if (nx >= 0 && nx < w && ny >= 0 && ny < h && c+1 < mins[ny][nx] && grid[ny][nx] != 'X') {
          mins[ny][nx] = c+1;
          qx.push(nx);
          qy.push(ny);
          qc.push(c+1);
        }
      }
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
