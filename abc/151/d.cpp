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
const int dx[8] = {1, 0, -1, 0};
const int dy[8] = {0, 1, 0, -1};

void solve() {
  int h, w; cin >> h >> w;
  vector<string> grid(h); rep(i, h) cin >> grid[i];
  vector<P> dots;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (grid[i][j] == '.') dots.push_back(make_pair(i, j));
    }
  }

  ll ans = 0;
  const int MAX = 20;
  bool visited[MAX][MAX] = {};
  for (int i = 0; i < dots.size(); i++) {
    int sy = dots[i].first;
    int sx = dots[i].second;
    for (int j = i + 1; j < dots.size(); j++) {
      int gy = dots[j].first;
      int gx = dots[j].second;

      queue<ll> qx, qy, qc;
      qx.push(sx);
      qy.push(sy);
      qc.push(0);
      visited[sy][sx] = true;

      while (!qx.empty()) {
        int x = qx.front(); qx.pop();
        int y = qy.front(); qy.pop();
        int c = qc.front(); qc.pop();

        if (x == gx && y == gy) {
          ans = max(ans, c);
          break;
        }

        for (int k = 0; k < 4; k++) {
          int nx = x + dx[k];
          int ny = y + dy[k];
          if (nx >= 0 && nx < w && ny >= 0 && ny < h && !visited[ny][nx] && grid[ny][nx] == '.') {
            visited[ny][nx] = true;
            qx.push(nx);
            qy.push(ny);
            qc.push(c + 1);
          }
        }
      }

      memset(visited, false, sizeof(visited));
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
