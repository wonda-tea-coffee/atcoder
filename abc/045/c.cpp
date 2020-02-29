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

ll dfs(string str) {
  int len = str.size();
  if (len == 0) return 0;
  if (len == 1) return str[0] - '0';

  ll ret = stoll(str);
  int left = 0;
  for (int i = 0; i < len - 1; i++) {
    left = left * 10 + (str[i] - '0');

    string ss = str.substr(i + 1, len - i - 1);

    ret += left * pow(2, len - i - 2) + dfs(ss);
  }
  return ret;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s; cin >> s;

  cout << dfs(s) << endl;
}