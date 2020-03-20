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

void solve() {
  ll N, K, R, S, P; cin >> N >> K >> R >> S >> P;
  string T; cin >> T;
  vector<string> t;

  for (int i = 0; i < K; i++) {
    string ti = "";
    for (int j = i; j < N; j += K) {
      ti += T[j];
    }
    t.push_back(ti);
  }

  ll ans = 0;
  for (int i = 0; i < t.size(); i++) {
    int r = 0, s = 0, p = 0;
    if (t[i][0] == 'r') p += P;
    if (t[i][0] == 's') r += R;
    if (t[i][0] == 'p') s += S;

    int n = t[i].size();
    // debug2(t[i], n);
    for (int j = 1; j < n; j++) {
      int rr = max(s, p), ss = max(r, p), pp = max(r, s);

      if (t[i][j] == 'r') pp += P;
      if (t[i][j] == 's') rr += R;
      if (t[i][j] == 'p') ss += S;

      r = rr; s = ss; p = pp;
    }

    ans += max({r, s, p});
  }
  outl(ans);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
