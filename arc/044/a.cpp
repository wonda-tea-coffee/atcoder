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

bool isprime(ll n) {
  if (n == 1) return false;
  if (n != 2 && n % 2 == 0) return false;
  int lim = int(sqrt(n));
  for (int i = 3; i <= lim; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}

int sumOfDigits(ll n) {
  int ret = 0;
  while (n > 0) {
    ret += n % 10;
    n /= 10;
  }
  return ret;
}

bool ok(int n) {
  if (n % 10 % 2 == 0) return false;
  if (n % 10 == 5) return false;
  if (sumOfDigits(n) % 3 != 0) return true;
  return false;
}

void solve() {
  int n; cin >> n;

  if (isprime(n) || (n != 1 && ok(n))) outl("Prime");
  else outl("Not Prime");
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
