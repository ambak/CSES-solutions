#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	map<vector<LL>, LL> m;
	vector<LL> t(26);
	vector<bool> d(26);
	for (auto c : s) {
		d[c - 'a'] = true;
	}
	LL res = 0;
	m[t] = 1;
	for (auto c : s) {
		t[c - 'a']++;
		LL mini = 1e9;
		for (LL i = 0; i < 26; i++) {
			if (d[i]) mini = min(t[i], mini);
		}
		for (LL i = 0; i < 26; i++) {
			if (d[i]) t[i] -= mini;
		}
		if (m.find(t) == m.end()) {
			m[t] = 1;
		} else {
			res += m[t];
			m[t]++;
		}
	}
	cout << res << "\n";
	return 0;
}
