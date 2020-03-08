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
#include <sstream>
#include <vector>

#define fix(n) cout<<fixed<<setprecision(n);
#define rep(i,n)   for (int i = 0; i < (n); ++i)
#define sort(a)    sort((a).begin(), (a).end());
#define uniq(a)    SORT(a);(a).erase(unique((a).begin(), (a).end()), (a).end());
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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12)

  ll n, p; cin >> n >> p;
  string s; cin >> s;

  if (10 % p == 0) {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      if ((s[i] - '0') % p == 0) ans += i + 1;
    }
    outl(ans)
    return 0;
  }

  vector<int> d(n + 1);
  int ten = 1;
  for (int i = n-1; i >= 0; --i) {
    int a = (s[i]-'0') * ten % p;
    d[i] = (d[i+1]+a) % p;
    ten *= 10; ten %= p;
  }

  ll ans = 0;
  vector<int> cnt(p);
  for (int i = n; i >= 0; --i) {
    ans += cnt[d[i]];
    cnt[d[i]]++;
  }

  outl(ans)
}
