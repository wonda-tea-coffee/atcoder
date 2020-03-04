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

void replaceAll(string &s, string from, string to) {
	int pos;
	int len = from.size();
	while ((pos = s.find(from)) != string::npos) {
		s.replace(pos, len, to);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	srand((unsigned)time(NULL));

	string s; cin >> s;

	replaceAll(s ,"ch", "*");
	replaceAll(s ,"o", "*");
	replaceAll(s ,"k", "*");
	replaceAll(s ,"u", "*");

	if (count(s.begin(), s.end(), '*') == s.size()) {
		YES()
	} else {
		NO()
	}
}