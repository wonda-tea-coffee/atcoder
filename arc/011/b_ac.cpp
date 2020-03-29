#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main() {
	int N; cin >> N;
	vector<string> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];

	map<char, string> m;
	m['b'] = m['c'] = "1";
	m['d'] = m['w'] = "2";
	m['t'] = m['j'] = "3";
	m['f'] = m['q'] = "4";
	m['l'] = m['v'] = "5";
	m['s'] = m['x'] = "6";
	m['p'] = m['m'] = "7";
	m['h'] = m['k'] = "8";
	m['n'] = m['g'] = "9";
	m['z'] = m['r'] = "0";

	vector<string> ans;
	for (int i = 0; i < N; i++) {
		string tmp = "";
		for (auto &it : v[i]) it = tolower(it);
		for (int j = 0; j < v[i].size(); j++) {
			tmp += m[v[i][j]];
		}

		if (!tmp.empty()) ans.emplace_back(tmp);
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
		if (i < ans.size() - 1)
			cout << " ";
	}
	cout << endl;

	return 0;
}
