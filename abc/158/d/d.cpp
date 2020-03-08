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

  string s; cin >> s;
  ll q; cin >> q;

  deque<char> deq;
  for (int i = 0; i < s.size(); i++)
    deq.push_back(s[i]);
  
  bool rev = false;
  for (int i = 0; i < q; i++) {
    int t; cin >> t;

    if (t == 1) {
      rev = !rev;
    } else {
      int f; cin >> f;
      char c; cin >> c;

      if ((f == 1 && !rev) || (f == 2 && rev)) {
        deq.push_front(c);
      } else {
        deq.push_back(c);
      }
    }

    // outl(string(deq.begin(), deq.end()))
  }

  s = string(deq.begin(), deq.end());

  // outl(s)

  if (rev) reverse(s);

  outl(s)
}
