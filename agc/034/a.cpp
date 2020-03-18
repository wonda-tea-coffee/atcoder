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
#define sort(a)         sort((a).begin(), (a).end())
#define uniq(a)         sort(a);(a).erase(unique((a).begin(), (a).end()), (a).end())
#define reverse(a)      reverse((a).begin(), (a).end())
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

using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;

const ll MOD = 1000000007; // 10^9 + 7
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

bool ok(string s) {
  return s.find("##") == string::npos;
}

void solve() {
  int n, a, b, c, d; cin >> n >> a >> b >> c >> d;
  string s; cin >> s;
  s = '.' + s;

  if (a < b && b < c && c < d) {
    string sub1 = s.substr(a, b - a);
    string sub2 = s.substr(c, d - c);
    if (ok(sub1) && ok(sub2)) Yes();
    else No();
  } else if (a < b && b < d && d < c) {
    string sub1 = s.substr(a, c - a);
    if (!ok(sub1)) {
      No();
      return;
    }

    if (s[d-1] == '.') {
      Yes();
      return;
    }

    string sub2 = s.substr(b-1, d-(b-1));
    if (sub2.find("...") == string::npos) No();
    else Yes();

  } else if (a < c && c < b && b < d) {
    string sub1 = s.substr(a, c - a);
    string sub2 = s.substr(b, d - b);
    if (ok(sub1) && ok(sub2)) Yes();
    else No();
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
