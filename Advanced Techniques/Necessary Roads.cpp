#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

pair<int, int> low[100009];
vector<int> v[100009];
vector<pair<int, int>> res;

void dfs(int st, int &C, int parent) {
	low[st] = {C, C};
	for (auto x : v[st]) {
		if (x == parent) {
			continue;
		}
		if (low[x].first == 0) {
			C++;
			dfs(x, C, st);
			low[st].second = min(low[st].second, low[x].second);
		} else {
			low[st].second = min(low[st].second, low[x].first);
		}
	}
	if (low[st].first == low[st].second) {
		res.push_back({st, parent});
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int C = 1;
	dfs(1, C, 0);
	res.pop_back();
	cout << res.size() << "\n";
	for (auto [a, b] : res) cout << a << " " << b << "\n";
	return 0;
}
