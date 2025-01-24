#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v[200009];
pair<bool, bool> odw[200009];
vector<int> res;
bool cycle;

void dfs(int s) {
	odw[s] = {true, true};
	for (auto x : v[s]) {
		if (odw[x].second) {
			cycle = true;
		}
		if (odw[x].first == false) {
			dfs(x);
		}
	}
	res.push_back(s);
	odw[s].second = false;
}

void dfs_start(int n) {
	for (int i = 1; i <= n; i++) {
		if (odw[i].first == 0) {
			dfs(i);
		}
	}
	reverse(res.begin(), res.end());
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	dfs_start(n);
	if (cycle) {
		cout << "IMPOSSIBLE\n";
	} else {
		for (auto x : res) {
			cout << x << " ";
		}
	}
	return 0;
}
