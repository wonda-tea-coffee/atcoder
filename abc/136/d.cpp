#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstring>
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
#define OUT(d) cout << (d);
#define OUT_L(d) std::cout<<(d)<<"\n";
#define Yes() printf("Yes\n");
#define No() printf("No\n");
#define YES() printf("YES\n");
#define NO() printf("NO\n");
#define CEIL(x, y) ((x + y - 1) / (y))

using namespace std;
using ll = long long;
using P = pair<ll,ll>;

const ll MOD = 1000000007; // 10^9 + 7

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));

  string s; cin >> s;
  int n = s.size();
  vector<ll> a(n);

  for (int i = 0; i < n; i++) {
    int d = s[i] == 'L' ? -1 : 1;
    int j = i;
    while (s[j] == s[i]) j += d;
    
    if ((j - i) % 2 == 0) a[j]++;
    else a[j - d]++; 
  }

  cout << a[0];
  for (int i = 1; i < n; i++)
    cout << " " << a[i];
  cout << endl;
}
