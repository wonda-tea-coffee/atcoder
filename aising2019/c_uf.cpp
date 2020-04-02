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

class DisjointSet {
public:
  vector<int> p, rank, size;
  DisjointSet(int n) {
    p.assign(n, 0);
    rank.assign(n, 0);
    size.assign(n, 0);
    for (int i = 0; i < n; i++) {
      make_set(i);
    }
  }
 
  void make_set(int x) {
    p[x] = x;
    rank[x] = 0;
    size[x] = 1;
  }
 
  int find_set(int x) {
    if (x != p[x]) {
      p[x] = find_set(p[x]);
    }
    return p[x];
  }
 
  bool same(int x, int y) {
    return find_set(x) == find_set(y);;
  }
 
  int union_size(int x) {
    if (x != p[x]) {
      size[x] = union_size(find_set(x));
    }
    return size[x];
  }
 
  void link(int x, int y) {
    if(rank[x]  > rank[y]) {
        p[y] = x;
        size[x] = size[x] + size[y];
    }else if(rank[x] < rank[y]){
        p[x] = y;
        size[y] = size[x] + size[y];
    }else if(x != y) {
      p[y] = x;
      rank[x]++;
      size[x] = size[x] + size[y];
    }
  }
 
  void unite(int x, int y) {
      link(find_set(x), find_set(y));
  }
};

void solve() {
  int H, W; cin >> H >> W;
  vector<string> grid(H);
  int n = H * W;
  int d[n];

  rep(i, H) {
    cin >> grid[i];
    rep(j, W) {
      int idx = i * W + j;
      if (grid[i][j] == '#') d[idx] = 0;
      else d[idx] = 1;
    }
  }

  DisjointSet ds(n);
  rep(i, H)rep(j, W) {
    if (i + 1 < H && grid[i][j] != grid[i + 1][j]) {
      // 縦に伸びる頂点同士を併合
      ds.unite(W * i + j, W * (i + 1) + j);
    }
    if (j + 1 < W && grid[i][j] != grid[i][j + 1]) {
      // 横に伸びる頂点同士を併合
      ds.unite(W * i + j, W * i + j + 1);
    }
  }

  ll ans = 0;
  vector<ll> b(n, 0), w(n, 0);
  rep(i, n) {
    if (d[i] == 0) b[ds.find_set(i)]++;
    else w[ds.find_set(i)]++;
  }
  rep(i, n) ans += b[i] * w[i];
  outl(ans);
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
