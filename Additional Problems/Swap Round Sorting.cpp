#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> v;
	vector<bool> odw(n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x - 1);
	}
	vector<vector<pair<int, int>>> res;
	vector<pair<int, int>> ans;
	for (int i = 0; i < n; i++) {
		vector<int> cycle;
		for (int j = i; !odw[j]; j = v[j]) {
			cycle.push_back(j);
			odw[j] = true;
		}
		for (int l = 0, r = cycle.size() - 1; l < r; l++, r--) {
			ans.emplace_back(cycle[l] + 1, cycle[r] + 1);
			swap(v[cycle[l]], v[cycle[r]]);
		}
	}
	res.push_back(ans);
	ans.clear();
	for (int i = 0; i < n; i++) {
		if (v[i] != i) {
			ans.emplace_back(i + 1, v[i] + 1);
			swap(v[i], v[v[i]]);
		}
	}
	res.push_back(ans);
	if (res[1].size()) {
		cout << "2\n";
		cout << res[0].size() << "\n";
		for (auto [a, b] : res[0]) cout << a << " " << b << "\n";
		cout << res[1].size() << "\n";
		for (auto [a, b] : res[1]) cout << a << " " << b << "\n";
	} else if (res[0].size()) {
		cout << "1\n";
		cout << res[0].size() << "\n";
		for (auto [a, b] : res[0]) cout << a << " " << b << "\n";
	} else {
		cout << "0\n";
	}
	return 0;
}
