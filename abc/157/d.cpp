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

  int N, M, K; cin >> N >> M >> K;
  vector<vector<int>> friends(N), blocks(N);
  REP(i, M) {
    int a, b; cin >> a >> b;
    friends[a - 1].push_back(b - 1);
    friends[b - 1].push_back(a - 1);
  }
  REP(i, K) {
    int a, b; cin >> a >> b;
    blocks[a - 1].push_back(b - 1);
    blocks[b - 1].push_back(a - 1);
  }
  vector<set<int>> candidates(N);

  REP(i, N) {
    for (int j = 0; j < friends[i].size(); j++) {
      candidates[i].insert(friends[i][j]);
    }
    candidates[i].erase(i);
    
  }

  REP(i, N) {
    cout << candidates[i].size();
    if (i != N - 1) cout << " ";
  }
  cout << endl;
}
