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
  string line; getline(cin, line);
  vector<string> vals = split(line, ' ');
  ll n = stoll(vals[0]), l = stoll(vals[1]);
  // debug2(n, l);
  vector<string> ami(l + 1);
  rep(i, l + 1) getline(cin, ami[i]);

  int x = -1, y = l;
  for (int i = 0; i < ami[l].size(); i++) {
    if (ami[l][i] == 'o') {
      x = i;
      break;
    }
  }

  int dist = 0;
  while (y >= 0) {
    // debug2(x, y);
    if (ami[y][x] == 'o') y--;
    else if (ami[y][x] == '|' && dist != 0) {
      y--;
      dist = 0;
    } else if (x-1>=0 && ami[y][x-1] == '-') {
      dist = -1;
      x--;
    } else if (x+1<ami[y].size() && ami[y][x+1] == '-') {
      dist = 1;
      x++;
    } else if (ami[y][x] == '-') {
      x += dist;
    } else {
      y--;
    }
  }
  // debug2(x, y);
  outl(x / 2 + 1);
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
