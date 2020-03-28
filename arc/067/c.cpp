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

// 正の整数n未満の素数を全て求める
vector<ll> sieve(ll n) {
  vector<bool> is_prime(n);
  rep(i, n) is_prime[i] = true;

  is_prime[1] = false;
  for (ll i = 4; i < n; i += 2) is_prime[i] = false;
  ll lim = ll(sqrt(n));
  for (ll i = 3; i <= lim; i += 2) {
    for (ll j = 3; i * j < n; j += 2) {
      is_prime[i * j] = false;
    }
  }

  vector<ll> ret;
  for (ll i = 1; i < n; i++) {
    if (is_prime[i]) ret.push_back(i);
  }
  return ret;
}

void solve() {
  ll n; cin >> n;
  ll ans = 1;
  vector<ll> primes = sieve(n + 1);

  for (int p : primes) {
    ll cnt = 1, q = p;
    while (q <= n) {
      cnt += n / q;
      q *= p;
    }
    ans = ans * cnt % MOD;
  }

  outl(ans);
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
