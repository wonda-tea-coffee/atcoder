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
#include <vector>

#define REP(i,n)   for (int i = 0; i < (n); ++i)
#define SORT(a)    sort((a).begin(), (a).end());
#define UNIQ(a)    SORT(a);(a).erase(unique((a).begin(), (a).end()), (a).end());
#define FIND(a,x)  find((a).begin(), (a).end(), (x)) != (a).end()
#define REVERSE(a) reverse((a).begin(), (a).end());

using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MOD = 1000000007; // 10^9 + 7

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, Y; cin >> N >> Y; Y /= 1000;
  for (int b = 0; b <= min((10 * N - Y) / 5, (Y - N) / 4); b++) {
    if ((10 * N - Y - 5 * b) % 9 > 0) continue;
    int c = (10 * N - Y - 5 * b) / 9;
    cout << N - b - c << " " << b << " " << c << endl;
    return 0;
  }
  cout << "-1 -1 -1" << endl;
}