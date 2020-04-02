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

struct UnionFind {
  vector<int> par;
    
  UnionFind(int n) : par(n, -1) { }

  int root(int x) {
    if (par[x] < 0) return x;
    else return par[x] = root(par[x]);
  }
    
  bool same(int x, int y) {
    return root(x) == root(y);
  }
  
  void merge(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return;
    if (par[x] > par[y]) swap(x, y); // merge technique
    par[x] += par[y];
    par[y] = x;
  }
    
  int size(int x) {
    return -par[root(x)];
  }
};

template<class T>
void outvo(vector<T> v) {
  if (v.size() == 0) return;
  cout << v[0];
  for (int i = 1; i < v.size(); i++)
    cout << " " << v[i];
  cout << endl;
}

void solve() {
  ll N, M, K; cin >> N >> M >> K;
  UnionFind uf(N);
  vector<set<ll>> dame(N);

  rep(i, M) {
    ll a, b; cin >> a >> b;
    a--; b--;
    dame[a].insert(b);
    dame[b].insert(a);
    uf.merge(a, b);
  }
  rep(i, K) {
    ll c, d; cin >> c >> d;
    c--; d--;
    if (uf.same(c, d)) {
      dame[c].insert(d);
      dame[d].insert(c);
    }
  }

  vector<ll> ans(N);
  rep(i, N) ans[i] = uf.size(i) - dame[i].size() - 1;

  outvo(ans);
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
