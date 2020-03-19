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
  return s[0] == 'M' || s[0] == 'A' || s[0] == 'R' || s[0] == 'C' || s[0] == 'H';
}

void solve() {
  int n; cin >> n;
  map<char, ll> map;
  rep(i, n) {
    string s; cin >> s;
    if (!ok(s)) continue;
    if (map.find(s[0]) == map.end()) map.insert(make_pair(s[0], 1));
    else map[s[0]]++;
  }
  if (map.size() == 0) {
    outl(0);
  } else {
    ll sum = 0;
    vector<char> v = {'M', 'A', 'R', 'C', 'H'};
    for (int vi : v) {
      if (map.find(vi) == map.end()) map.insert(make_pair(vi, 0));
    }
    for (int i = 0; i < 5; i++) {
      for (int j = i+1; j < 5; j++) {
        for (int k = j+1; k < 5; k++) {
          // debug3(i, j, k);
          // debug3(v[i], v[j], v[k]);
          // debug3(map[v[i]], map[v[j]], map[v[k]]);
          sum += map[v[i]] * map[v[j]] * map[v[k]];
        }
      }
    }
    outl(sum);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}