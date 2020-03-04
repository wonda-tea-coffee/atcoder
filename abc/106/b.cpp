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

// 約数の個数
int cntDivisors(ll n) {
  int ret = 0;
  ll lim = ll(sqrt(n));
  for (ll i = 1; i <= lim; i++) {
    if (n % i > 0) continue;
    ret += 2;
    if (i == n / i) ret--;
  }
  return ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));

  int n; cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i += 2) {
    if (cntDivisors(i) == 8) ans++;
  }
  outl(ans)
}
