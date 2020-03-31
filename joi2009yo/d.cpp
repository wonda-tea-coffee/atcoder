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

ll m, n;
vector<vector<bool>> v;
ll ans = 0;

void clean(int y, int x) {
  v[y][x] = 0;
  rep(i, 4) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[ny][nx] == 1) {
      clean(ny, nx);
    }
  }
}

tuple<ll, ll, ll> dfs(int y, int x, int c) {
  tuple<ll, ll, ll> ret = make_tuple(y, x, c);
  rep(i, 4) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx >= 0 && nx < n && ny >= 0 && ny < m && v[ny][nx] == 1) {
      v[y][x] = 0;

      tuple<ll, ll, ll> tmp = dfs(ny, nx, c+1);
      if (get<2>(ret) < get<2>(tmp)) {
        ret = tmp;
      }

      v[y][x] = 1;
    }
  }
  return ret;
}

void solve() {
  cin >> m >> n;
  v.resize(m);
  rep(i, m) {
    v[i].resize(n);
    rep(j, n) {
      ll ij; cin >> ij;
      v[i][j] = ij == 1;
    }
  }

  rep(i, m)rep(j, n) {
    if (v[i][j] == 0) continue;
    tuple<ll, ll, ll> tup1 = dfs(i, j, 1);
    tuple<ll, ll, ll> tup2 = dfs(get<0>(tup1), get<1>(tup1), 1);

    // debug2(i, j);
    // debug3(get<0>(tup1), get<1>(tup1), get<2>(tup1));
    // debug3(get<0>(tup2), get<1>(tup2), get<2>(tup2));

    ans = max(ans, get<2>(tup2));
    clean(i, j);
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
