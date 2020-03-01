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
const int INF = 1010101010;

int D, G;
vector<int> p(10), c(10);

int dfs(int i, int score, int solved) {
  if (i == D) {
    if (score >= G) return solved;
    else return INF;
  }

  return min(
    dfs(i + 1, score, solved),
    dfs(i + 1, score + 100 * (i + 1) * p[i] + c[i], solved + p[i])
  );
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> D >> G;
  REP(i, D) cin >> p[i] >> c[i];

  cout << dfs(0, 0, 0) << endl;
}