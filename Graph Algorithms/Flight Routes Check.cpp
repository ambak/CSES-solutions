#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v[100009];
int low[100009];
int odw[100009];

int dfs(int s, int step) {
	odw[s] = step;
	low[s] = step;
	int m_low = step;
	int res = step;
	for (auto i : v[s]) {
		if (odw[i] == 0) {
			res = max(res, dfs(i, res + 1));
		}
		m_low = min(m_low, low[i]);
	}
	low[s] = m_low;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a == b) continue;
		v[a].push_back(b);
	}
	dfs(1, 1);
	pair<int, int> res = {0, 0};
	for (int i = 2; i <= n; i++) {
		if (odw[i] == 0) {
			res = {1, i};
		}
	}
	for (int i = 2; i <= n; i++) {
		if (low[i] != 0 && low[i] == odw[i]) {
			res = {i, 1};
			break;
		}
	}
	if (res == make_pair(0, 0)) {
		cout << "YES\n";
	} else {
		cout << "NO\n"
			 << res.first << " " << res.second << "\n";
	}

	return 0;
}
