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
const int dx[8] = {1, -1,  0, 0,  1, 1, -1, -1};
const int dy[8] = {0,  0, -1, 1, -1, 1, -1,  1};

void solve() {
  int x, y; cin >> x >> y;
  x--; y--;
  string w; cin >> w;
  string nums[9]; rep(i, 9) cin >> nums[i];

  map<string,int> d;
  d.insert(make_pair("R", 0));
  d.insert(make_pair("L", 1));
  d.insert(make_pair("U", 2));
  d.insert(make_pair("D", 3));
  d.insert(make_pair("RU", 4));
  d.insert(make_pair("RD", 5));
  d.insert(make_pair("LU", 6));
  d.insert(make_pair("LD", 7));

  string ans = "";
  int vx = dx[d[w]];
  int vy = dy[d[w]];
  rep(i, 4) {
    ans += ctos(nums[y][x]);
    if (x + vx < 0 || x + vx >= 9) vx = -vx;
    if (y + vy < 0 || y + vy >= 9) vy = -vy;
    x += vx;
    y += vy;
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
