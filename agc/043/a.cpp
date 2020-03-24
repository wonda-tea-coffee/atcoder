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
const int dx[2] = {1, 0};
const int dy[2] = {0, 1};

void solve() {
  int h, w; cin >> h >> w;
  vector<string> v(h); rep(i, h) cin >> v[i];

  const int MAX = 100;
  int mins[MAX + 1][MAX + 1] = {{}};

  for (int i = 0; i <= MAX; i++) {
    for (int j = 0; j <= MAX; j++) {
      mins[i][j] = MOD;
    }
  }
  mins[0][0] = v[0][0] == '.' ? 0 : 1;
  queue<ll> qx; qx.push(0);
  queue<ll> qy; qy.push(0);
  queue<ll> qc; qc.push(mins[0][0]);

  while (!qx.empty()) {
    int x = qx.front(); qx.pop();
    int y = qy.front(); qy.pop();
    int c = qc.front(); qc.pop();
    // debug3(x, y, c);

    for (int i = 0; i < 2; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx >= 0 && nx < w && ny >= 0 && ny < h) {
        int nc = v[ny][nx] == '#' && v[y][x] == '.' ? c + 1 : c;
        if (nc >= mins[ny][nx]) continue;

        mins[ny][nx] = nc;
        qx.push(nx);
        qy.push(ny);
        qc.push(nc);
      }
    }
  }
  outl(mins[h-1][w-1]);
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
