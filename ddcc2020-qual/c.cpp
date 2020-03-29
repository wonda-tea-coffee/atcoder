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
#define all(a)          (a).begin(), (a).end()
#define sort(a)         sort(all(a))
#define uniq(a)         sort(a);(a).erase(unique(all(a), (a).end())
#define reverse(a)      reverse(all(a))
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
#define pb              push_back
#define fst             first
#define int             long long
#define INF             __LONG_LONG_MAX__

using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;

const ll MOD = 1000000007; // 10^9 + 7
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int n, m, k, ids;
const int MAX = 310;
int a[MAX][MAX];
vector<string> s(MAX);
 
void dfs(int sx, int sy, int ex, int ey) {
	int pxi = -1, pyi = -1, pxj = -1, pyj = -1;
	for (int i = sx; i <= ex; ++i) {
		for (int j = sy; j <= ey; ++j) {
			if (s[i][j] == '#') {
				if (pxi == -1) pxi = i, pyi = j;
				else if (pxj == -1) pxj = i, pyj = j;
      }
    }
  }
	if (pxj == -1) {
		++ids;
		for (int i = sx; i <= ex; ++i) {
			for (int j = sy; j <= ey; ++j) {
				a[i][j] = ids;
      }
    }
		return;
  }
	if (pxi != pxj) {
		int z = min(pxi, pxj);
		dfs(sx, sy, z, ey);
		dfs(z + 1, sy, ex, ey);
	} else {
		int z = min(pyi, pyj);
		dfs(sx, sy, ex, z);
		dfs(sx, z + 1, ex, ey);
  }
}

void solve() {
	cin >> n >> m >> k;
	rep(i, n) cin >> s[i];

	dfs(0, 0, n-1, m-1);

	for (int i = 0; i < n; ++i, puts(""))
		for (int j = 0; j < m; ++j) cout << a[i][j] << " ";
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
