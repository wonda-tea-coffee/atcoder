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
#include <list>
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

void solve() {
  ll n; cin >> n;
  string s; cin >> s;
  vector<ll> cntr(n+1), cntg(n+1), cntb(n+1);
  for (int i = n-1; i >= 0; i--) {
    cntr[i] = cntr[i+1];
    cntg[i] = cntg[i+1];
    cntb[i] = cntb[i+1];
    if (s[i] == 'R') cntr[i]++;
    if (s[i] == 'G') cntg[i]++;
    if (s[i] == 'B') cntb[i]++;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (s[i] == s[j]) continue;
      ll v;
      char c;
      if (s[i] == 'R' && s[j] == 'G') {v = cntb[j+1];c='B';}
      if (s[i] == 'G' && s[j] == 'R') {v = cntb[j+1];c='B';}
      if (s[i] == 'R' && s[j] == 'B') {v = cntg[j+1];c='G';}
      if (s[i] == 'B' && s[j] == 'R') {v = cntg[j+1];c='G';}
      if (s[i] == 'B' && s[j] == 'G') {v = cntr[j+1];c='R';}
      if (s[i] == 'G' && s[j] == 'B') {v = cntr[j+1];c='R';}
      ans += v;
      if (2 * j - i < n && s[2 * j - i] == c) ans--;
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
