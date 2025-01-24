#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v[2509];

int bfs(int st, int n) {
	vector<int> odw(n + 1);
	odw[st] = 1;
	queue<pair<int, int>> q;
	q.push({st, st});
	int res = 1e7;
	while (!q.empty()) {
		auto z = q.front();
		q.pop();
		for (auto x : v[z.first]) {
			if (x == z.second) continue;
			if (odw[x] == 0) {
				q.push({x, z.first});
				odw[x] = odw[z.first] + 1;
			} else if (odw[x]) {
				res = min(res, odw[x] + odw[z.first] - 1);
			}
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m, res = 1e7;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int id = 1; id <= n; id++) {
		res = min(res, bfs(id, n));
	}
	if (res == 1e7)
		cout << "-1\n";
	else
		cout << res << "\n";
	return 0;
}
