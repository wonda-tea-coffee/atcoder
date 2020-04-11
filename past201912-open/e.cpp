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

vector<string> split(string s, char sep) {
  vector<string> ret;
  string tmp;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == sep) {
      ret.push_back(tmp);
      tmp = "";
    } else {
      tmp += s[i];
    }
  }
  if (tmp.size() > 0) ret.push_back(tmp);
  return ret;
}

void solve() {
  ll n, q; cin >> n >> q; cin.ignore();
  const ll MAX = 100;
  // f[i][j]: ユーザーiがユーザーjをフォローしている場合 true
  bool f[MAX+1][MAX+1] = {{}};

  rep(qi, q) {
    string s; getline(cin, s);
    vector<string> v = split(s, ' ');
    ll op = stoll(v[0]);
    ll a = stoll(v[1]);

    if (op == 1) {
      ll b = stoll(v[2]);
      f[a][b] = true;
    } else if (op == 2) {
      for (int j = 1; j <= n; j++) {
        if (f[j][a]) f[a][j] = true;
      }
    } else if (op == 3) {
      set<ll> skip;
      for (int x = 1; x <= n; x++) {
        if (f[a][x] && skip.find(x) == skip.end()) {
          for (int y = 1; y <= n; y++) {
            if (f[x][y] && a != y) {
              // debug3(a, x, y);
              if (!f[a][y]) skip.insert(y);
              f[a][y] = true;
            }
          }
        }
      }
    }

    // for (int i = 1; i <= n; i++) {
    //   for (int j = 1; j <= n; j++) {
    //     if (f[i][j]) cout << "Y";
    //     else cout << "N";
    //   }
    //   cout << endl;
    // }
    // cout << endl;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (f[i][j]) cout << "Y";
      else cout << "N";
    }
    cout << endl;
  }
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
