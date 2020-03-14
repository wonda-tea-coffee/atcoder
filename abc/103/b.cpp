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

string rotateRight(string s, int i) {
  string left = s.substr(s.size() - i, i);
  string right = s.substr(0, s.size() - i);

  return left + right;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));

  string s, t; cin >> s >> t;
  int n = t.size();
  for (int i = 0; i < n; i++) {
    if (rotateRight(s, i) == t) {
      Yes()
      return 0;
    }
  }
  No()
}
