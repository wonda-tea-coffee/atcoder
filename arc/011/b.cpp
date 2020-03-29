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
#define INF             __LONG_LONG_MAX__

using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;

const ll MOD = 1000000007; // 10^9 + 7
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

map<char, string> m;

string convert(string w) {
  string ret = "";

  for (char &wi : w) {
    wi = tolower(wi);
    ret += m[wi];
  }

  return ret;
}

void solve() {
  ll n; cin >> n;

	m['b'] = m['c'] = "1";
	m['d'] = m['w'] = "2";
	m['t'] = m['j'] = "3";
	m['f'] = m['q'] = "4";
	m['l'] = m['v'] = "5";
	m['s'] = m['x'] = "6";
	m['p'] = m['m'] = "7";
	m['h'] = m['k'] = "8";
	m['n'] = m['g'] = "9";
	m['z'] = m['r'] = "0";

  vector<string> ans;
  rep(i, n) {
    string w; cin >> w;
    string con = convert(w);
    if (!con.empty()) ans.push_back(con);
  }

  if (ans.size() == 0) {
    cout << endl;
    return;
  }

  cout << ans[0];
  for (int i = 1; i < ans.size(); i++)
    cout << " " + ans[i];
  cout << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
