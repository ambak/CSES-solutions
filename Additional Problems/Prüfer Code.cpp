#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n - 2);
	vector<int> cnt(n + 1);
	for (auto &x : v) {
		cin >> x;
		cnt[x]++;
	}
	set<int> leaf;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			leaf.insert(i);
		}
	}
	vector<pair<int, int>> res;
	for (int i = 0; i < n - 3; i++) {
		int x = v[i];
		int l = *leaf.begin();
		leaf.erase(leaf.begin());
		res.emplace_back(l, x);
		cnt[x]--;
		if (cnt[x] == 0) leaf.insert(x);
	}
	res.emplace_back(*leaf.begin(), v.back());
	leaf.erase(leaf.begin());
	res.emplace_back(*leaf.begin(), v.back());
	for (auto [a, b] : res) {
		cout << a << " " << b << "\n";
	}
	return 0;
}
