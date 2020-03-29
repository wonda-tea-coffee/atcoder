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

int h, w, k, ids;
const int MAX = 310;
int a[MAX][MAX];
vector<string> s(MAX);
 
void dfs(int sy, int sx, int ey, int ex) {
  // cout << "sy = " << sy << ", sx = " << sx << ", ey = " << ey << ", ex = " << ex << endl;
	int py = -1, px = -1, qy = -1, qx = -1;

  // 縦に走査
	for (int i = sy; i <= ey; i++) {
    // 横に走査
		for (int j = sx; j <= ex; j++) {
			if (s[i][j] == '#') {
				if (py == -1) py = i, px = j;
				else if (qy == -1) qy = i, qx = j;
      }
    }
  }

  // イチゴが一個しか無かった
	if (qy == -1) {
		ids++;
		for (int i = sy; i <= ey; i++) {
			for (int j = sx; j <= ex; j++) {
				a[i][j] = ids;
      }
    }
		return;
  }

	if (py != qy) {
		int z = min(px, qx);
		dfs(sy,  sx, ey,  z);
		dfs(sy, z+1, ey, ex);
	} else {
		int z = min(py, qy);
		dfs( sy, sx,  z, ex);
		dfs(z+1, sx, ey, ex);
  }
}

void solve() {
	cin >> h >> w >> k;
	rep(i, h) cin >> s[i];

	dfs(0, 0, h-1, w-1);

	for (int i = 0; i < h; i++, puts(""))
		for (int j = 0; j < w; j++) cout << a[i][j] << " ";
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  srand((unsigned)time(NULL));
  fix(12);

  solve();
}
