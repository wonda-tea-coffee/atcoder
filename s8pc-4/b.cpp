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
#define uniq(a)         sort(a);(a).erase(unique(all(a), (a).end()))
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

int popcount(ll n) {
  int ret = 0;
  while (n > 0) {
    if (n & 1) ret++;
    n >>= 1;
  }
  return ret;
}

// 要考慮
// - 最初からk色以上見えてる場合

void solve() {
  ll n, k; cin >> n >> k;
  vector<ll> a(n); rep(i, n) cin >> a[i];
  vector<ll> b(n);

  ll ans = INF;
  rep(i, 1<<n) {
    // 一番左の人を見えなくするのは無理
    if ((i & 1) == 0) continue;

    // k色見えないのでダメ
    if (popcount(i) < k) continue;

    copy(all(a), b.begin());
    ll maxh = b[0], view = 1, cost = 0;
    bool ok = true;
    for (int j = 1; j < n; j++) {
      // 今見てる建物を見えるようにすべきか
      bool b1 = ((i >> j) & 1) == 1;
      // 今見てる建物は左から見えるのか
      bool b2 = b[j] > maxh;

      if (b1 && b2) {
        // もう見えてるのでOK
        view++;
      } else if (b1 && !b2) {
        // 見えるようにする
        cost += maxh + 1 - b[j];
        b[j] = maxh + 1;
        view++;
      } else if (!b1 && b2) {
        // 見せたくないのに見えてる
        // 前の建物を高くするよりないけど無駄なのでスキップ
        ok = false;
        break;
      } else {
        // 見せたくないし、見えてないからOK
      }

      maxh = max(maxh, b[j]);
    }

    if (!ok) continue;

    // debug3(i, view, cost);

    ans = min(ans, cost);
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
