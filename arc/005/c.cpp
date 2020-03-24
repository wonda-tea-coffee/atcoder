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
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void solve() {
  int h, w; cin >> h >> w;
  vector<string> field(h); rep(i, h) cin >> field[i];
  const int MAX = 500, INF = 0xffffffff;
  int mins[3][MAX + 1][MAX + 1] = {{{}}};
  for (int i = 0; i <= MAX; i++) {
    for (int j = 0; j <= MAX; j++) {
      mins[0][i][j] = INF;
      mins[1][i][j] = INF;
      mins[2][i][j] = INF;
    }
  }

  // スタート位置を探す
  int sx = -1, sy = -1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (field[i][j] == 's') {
        sy = i;
        sx = j;
      }
    }
  }
  
  queue<int> qx, qy, qc, qb;
  qx.push(sx); qy.push(sy); qc.push(0); qb.push(0);
  mins[0][sy][sx] = 0;
  mins[1][sy][sx] = 0;
  mins[2][sy][sx] = 0;
  while (!qx.empty()) {
    int x = qx.front(); qx.pop();
    int y = qy.front(); qy.pop();
    int c = qc.front(); qc.pop();
    int b = qb.front(); qb.pop();
    // cout << "x = " << x << ", y = " << y << ", c = " << c << ", b = " << b << endl;

    if (field[y][x] == 'g') {
      YES();
      return;
    }

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
        int nb = field[ny][nx] == '#' ? b + 1 : b;
        if (nb > 2) continue;
        if (c + 1 >= mins[nb][ny][nx]) continue;

        qx.push(nx);
        qy.push(ny);
        qc.push(c + 1);
        mins[nb][ny][nx] = c + 1;
        if (field[ny][nx] == '#') qb.push(b + 1);
        else qb.push(b);
      }
    }
  }

  NO();
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
