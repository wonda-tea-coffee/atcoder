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

int n;
map<string, string> m;

string to_key(string s) {
  string ret = "";
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      // debug2(s[i], s[j]);
      if (s[i] == s[j]) {
        ret += "|" + to_string(i) + "," + to_string(j);
      }
    }
  }
  return ret;
}

void dfs(string s, int len) {
  if (len == n) {
    // debug2(s, n);
    string k = to_key(s);
    if (m.find(k) == m.end()) {
      m.insert(make_pair(k, s));
    }
    return;
  }
  for (int i = 0; i < n; i++) 
    dfs(s + ctos((char)'a' + i), len + 1);
}

void solve() {
  cin >> n;
  dfs("", 0);
  // debug(m.size());

  vector<string> v;
  for (auto it = m.begin(); it != m.end(); it++)
    v.push_back(it->second);
  
  sort(v);
  for (string vi : v) outl(vi);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
