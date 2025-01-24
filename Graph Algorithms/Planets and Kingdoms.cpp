#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v[100009];
int low[100009];
int odw[100009];

int dfs(int s, int step, int mx, vector<int> &qq, vector<vector<int>> &q) {
	odw[s] = step;
	low[s] = step;
	int m_low = step;
	int res = step;
	for (auto i : v[s]) {
		if (odw[i] == 0) {
			res = max(res, dfs(i, res + 1, mx, qq, q));
		}
		if (odw[i] >= mx) {
			m_low = min(m_low, low[i]);
		}
	}
	low[s] = m_low;
	qq.push_back(s);
	if (low[s] == odw[s]) {
		vector<int> tmp;
		for (int i = qq.size() - 1; i >= 0; i--) {
			if (low[qq[i]] >= m_low) {
				tmp.push_back(qq[i]);
				qq.pop_back();
			}
		}
		q.push_back(tmp);
		for (auto x : tmp) {
			low[x] = INT_MAX;
		}
	}
	return res;
}

auto dfs_run(int n) {
	int step = 0;
	vector<vector<int>> q;
	for (int i = 1; i <= n; i++) {
		if (odw[i] == 0) {
			vector<int> qq;
			step = dfs(i, step + 1, step + 1, qq, q);
		}
	}
	return q;
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
	auto q = dfs_run(n);
	cout << q.size() << "\n";
	int id = 1;
	for (auto qq : q) {
		for (auto x : qq) {
			odw[x] = id;
		}
		id++;
	}
	for (int i = 1; i <= n; i++) {
		cout << odw[i] << " ";
	}
	return 0;
}
