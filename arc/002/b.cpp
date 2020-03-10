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

vector<string> split(string s, char sep) {
  vector<string> ret;
  string tmp;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == sep) {
      ret.push_back(tmp);
      tmp = "";
    } else {
      tmp += s[i];
    }
  }
  if (tmp.size() > 0) ret.push_back(tmp);
  return ret;
}

bool isLeapYear(int year) {
  if (year % 400 == 0) return true;
  if (year % 100 == 0) return false;
  return year % 4 == 0;
}

void solve() {
  map<int, int> ml;
  ml.insert(make_pair(1, 31));
  ml.insert(make_pair(2, 28));
  ml.insert(make_pair(3, 31));
  ml.insert(make_pair(4, 30));
  ml.insert(make_pair(5, 31));
  ml.insert(make_pair(6, 30));
  ml.insert(make_pair(7, 31));
  ml.insert(make_pair(8, 31));
  ml.insert(make_pair(9, 30));
  ml.insert(make_pair(10, 31));
  ml.insert(make_pair(11, 30));
  ml.insert(make_pair(12, 31));

  string s; cin >> s;
  vector<string> t = split(s, '/');
  int y = stoi(t[0]);
  int m = stoi(t[1]);
  int d = stoi(t[2]);
  int l = m == 2 && isLeapYear(y) ? 29 : ml[m];

  while (true) {
    if (y % (m * d) == 0) {
      printf("%04d/%02d/%02d\n", y, m, d);
      return;
    }

    d++;
    if (d > l) {
      d = 1;
      m++;
      if (m > 12) {
        m = 1;
        y++;
      }
      l = m == 2 && isLeapYear(y) ? 29 : ml[m];
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
