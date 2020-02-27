#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int l, r;
  cin >> l >> r;

  if (r - l + 1 >= 2019) {
    cout << 0 << endl;
  } else {
    ll ans = 2019;
    for (ll li = l; li <= r; li++) {
      for (ll ri = li + 1; ri <= r; ri++) {
        ans = min(li * ri % 2019, ans);
      }
    }
    cout << ans << endl;
  }
}
