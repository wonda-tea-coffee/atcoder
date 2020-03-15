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
#include <regex>
#include <vector>

#define fix(n)          cout<<fixed<<setprecision(n)
#define rep(i,n)        for (int i = 0; i < (n); ++i)
#define sort(a)         sort((a).begin(), (a).end())
#define uniq(a)         sort(a);(a).erase(unique((a).begin(), (a).end()), (a).end())
#define reverse(a)      reverse((a).begin(), (a).end())
#define ctos(c)         string(1, (c))
#define out(d)          cout << (d)
#define outl(d)         std::cout<<(d)<<"\n"
#define YES()           cout << "YES" << endl
#define NO()            cout << "NO" << endl
#define Yes()           cout << "Yes" << endl
#define No()            cout << "No" << endl
#define ceil(x, y)      ((x + y - 1) / (y))
#define debug(x)        cerr << #x << ": " << (x) << '\n'
#define debug2(x, y)    cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << '\n'
#define debug3(x, y, z) cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << ", " << #z << ": " << (z) << '\n'
#define dbg(v)          for (size_t _ = 0; _ < v.size(); ++_){ cerr << #v << "[" << _ << "] : " << v[_] << '\n'; }

using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;

const ll MOD = 1000000007; // 10^9 + 7
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};


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

string repeat(char c, int t) {
  string ret = "";
  for (int i = 0; i < t; i++) ret += c;
  return ret;
}

template<class T>
void outvo(vector<T> v) {
  cout << v[0];
  for (int i = 1; i < v.size(); i++)
    cout << " " << v[i];
  cout << endl;
}

void solve() {
  string s; getline(cin, s);
  vector<string> words = split(s, ' ');
  int n; cin >> n;
  vector<string> ngs(n); rep(i, n) cin >> ngs[i];

  for (int i = 0; i < words.size(); i++) {
    string w = words[i];
    for (int j = 0; j < n; j++) {
      if (w.size() != ngs[j].size()) continue;

      bool match = true;

      for (int k = 0; k < w.size(); k++) {
        if (ngs[j][k] == '*') continue;
        if (ngs[j][k] != w[k]) {
          match = false;
          break;
        }
      }

      if (match) words[i] = repeat('*', w.size());
    }
  }

  // debug(words.size());
  outvo(words);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
