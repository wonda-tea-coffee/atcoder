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

string s;

string dfs(string res, int sum, int i) {
  if (i == 4) return sum == 7 ? res + "=7" : "";

  int si = s[i] - '0';
  string s1 = dfs(res + "+" + s.substr(i, 1), sum + si, i + 1);
  if (s1.size() > 0) return s1;

  string s2 = dfs(res + "-" + s.substr(i, 1), sum - si, i + 1);
  if (s2.size() > 0) return s2;

  return "";
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> s;
  cout << dfs(s.substr(0, 1), s[0] - '0', 1) << endl;
}