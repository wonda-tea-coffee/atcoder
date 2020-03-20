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

int calc(string s) {
  int ret = 0, n = s.size();
  int i = 0;
  while (i < n) {
    int cnt = 0, j = i;
    while (j < n && s[i] == s[j]) {
      j++;
      cnt++;
    }
    ret += cnt / 2;
    i = j;
  }
  // debug(ret);
  return ret;
}

void solve() {
  string s; cin >> s;
  ll k; cin >> k;

  int n = s.size();
  int l = 0, r = 0;
  while (l < n && s[0] == s[l]) l++;
  while (n - 1 - r >= 0 && s[0] == s[n - 1 - r]) r++;

  // debug2(l, r);

  if (l == n) outl(n * k / 2);
  else if (l == 1 && r == 0) outl(calc(s) * k);
  else {
    string sub = s.substr(l, n - r - l);
    // debug3(l, r, sub);
    // debug(calc(sub));

    outl(l / 2 + (l + r) / 2 * (k - 1) + calc(sub) * k + r / 2);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
