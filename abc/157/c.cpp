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

  int N, M; cin >> N >> M;
  int S[M]; char C[M]; REP(i, M) cin >> S[i] >> C[i];

  // N = 1   0〜  9
  // N = 2  10〜 99
  // N = 3 100〜999

  int si[3] = {0, 10, 100}, ei[3] = {9, 99, 999};
  for (int i = si[N - 1]; i <= ei[N - 1]; i++) {
    string si = to_string(i);

    bool ok = true;
    for (int mi = 0; mi < M; mi++) {
      ok &= si[S[mi] - 1] == C[mi];
    }

    if (ok) {
      cout << i << endl;
      return 0;
    }
  }

  cout << "-1" << endl;
}
