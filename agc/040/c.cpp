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

ll sum(vector<ll> a) {
  ll ret = 0;
  for (int i = 0; i < a.size(); i++)
    ret += a[i];
  return ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));

  string s; cin >> s;
  s += '.';
  ll n = s.size(), ans = 0;

  vector<ll> l(n + 1);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '<') sum++;
    else sum = 0;

    l[i + 1] = sum;
  }

  vector<ll> r(n + 1);
  sum = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '>') sum++;
    else sum = 0;

    r[i] = sum;
  }

  for (int i = 0; i < n; i++) {
    ans += max(l[i], r[i]);
  }

  outl(ans)
}
