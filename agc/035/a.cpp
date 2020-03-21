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

using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;

const ll MOD = 1000000007; // 10^9 + 7
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

void solve() {
  int n; cin >> n;
  map<int, int> map;
  rep(i, n) {
    int a; cin >> a;
    if (map.find(a) == map.end()) map.insert(make_pair(a, 1));
    else map[a]++;
  }
  if (map.size() >= 4) No();
  else if (map.size() == 1) {
    if (map.find(0) != map.end()) Yes();
    else No();
  } else if (map.size() == 2) {
    if (n % 3 != 0) No();
    else if (map[0] == n / 3) Yes();
    else No();
  } else {
    if (n % 3 != 0) No();
    else {
      vector<int> m;
      for (auto it : map) {
        if (it.second != n / 3) {
          No();
          return;
        }
        m.push_back(it.first);
      }
      int a[3] = {0,0,1};
      int b[3] = {1,2,2};
      int c[3] = {2,1,0};
      for (int i = 0; i < 3; i++) {
        if ((m[a[i]] ^ m[b[i]]) == m[c[i]]) {
          Yes();
          return;
        }
      }
      No();
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
