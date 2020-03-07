#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define rep(i,n)   for (int i = 0; i < (n); ++i)
#define sort(a)    sort((a).begin(), (a).end());
#define uniq(a)    SORT(a);(a).erase(unique((a).begin(), (a).end()), (a).end());
#define find(a,x)  find((a).begin(), (a).end(), (x)) != (a).end()
#define reverse(a) reverse((a).begin(), (a).end());
#define out(d) cout << (d);
#define outl(d) std::cout<<(d)<<"\n";
#define Yes() printf("Yes\n");
#define No() printf("No\n");
#define YES() printf("YES\n");
#define NO() printf("NO\n");
#define ceil(x, y) ((x + y - 1) / (y))

using namespace std;
using ll = long long;
using P = pair<ll,ll>;

const ll MOD = 1000000007; // 10^9 + 7

bool ok(ll n) {
  string s = to_string(n);
  int m = s.size();
  for (int i = 1; i < m; i++) {
    if (s[i - 1] + 1 != s[i]) return false;
  }

  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));

  ll n; cin >> n;
  vector<ll> a(n); rep(i, n) cin >> a[i];

  ll ans = -1;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ll prod = a[i] * a[j];
      if (prod <= ans) continue;
      if (ok(prod)) ans = prod;
    }
  }

  outl(ans)
}
