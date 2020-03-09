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
#include <vector>

#define fix(n)          cout<<fixed<<setprecision(n)
#define rep(i,n)        for (int i = 0; i < (n); ++i)
#define sort(a)         sort((a).begin(), (a).end())
#define uniq(a)         SORT(a);(a).erase(unique((a).begin(), (a).end()), (a).end())
#define reverse(a)      reverse((a).begin(), (a).end())
#define ctos(c)         string(1, (c))
#define out(d)          cout << (d)
#define outl(d)         std::cout<<(d)<<"\n"
#define Yes()           printf("Yes\n")
#define No()            printf("No\n")
#define YES()           printf("YES\n")
#define NO()            printf("NO\n")
#define ceil(x, y)      ((x + y - 1) / (y))
#define debug(x)        cerr << #x << ": " << (x) << '\n'
#define debug2(x, y)    cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << '\n'
#define debug3(x, y, z) cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << ", " << #z << ": " << (z) << '\n'
#define dbg(v)          for (size_t _ = 0; _ < v.size(); ++_){ cerr << #v << "[" << _ << "] : " << v[_] << '\n'; }

using namespace std;
using ll = long long;
using P = pair<ll,ll>;

const ll MOD = 1000000007; // 10^9 + 7

void replaceAll(string &s, string from, string to) {
  // debug3(s, from, to);
  int pos;
  int len = from.size();
  while ((pos = s.find(from)) != string::npos) {
    s.replace(pos, len, to);
  }
}

void solve() {
  vector<string> from = {"O", "D", "I", "Z", "S", "B"};
  vector<string> to = {"0", "0", "1", "2", "5", "8"};

  string s; cin >> s;
  for (int i = 0; i < from.size(); i++) {
    replaceAll(s, from[i], to[i]);
  }
  outl(s);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
