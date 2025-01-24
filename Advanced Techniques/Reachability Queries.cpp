#include <bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
typedef long long LL;

const int M = 50001;
bitset<M> bit[M];

void dfs(int st, vector<vector<int>> &v, vector<int> &odw, int C, vector<int> &col) {
	odw[st] = -1;
	for (auto x : v[st]) {
		if (odw[x] == 0) {
			dfs(x, v, odw, C, col);
		}
	}
	odw[st] = C;
	col.push_back(st);
}

pair<vector<int>, int> scc(int n, vector<vector<int>> &v, vector<vector<int>> &vr) {
	vector<int> odw(n + 1);
	vector<int> odw2(n + 1);
	vector<int> col, tmp;
	int C = 1;
	for (int i = 1; i <= n; i++) {
		if (odw[i] == 0)
			dfs(i, v, odw, C, col);
	}
	reverse(col.begin(), col.end());
	for (auto x : col) {
		if (odw2[x] == 0) {
			dfs(x, vr, odw2, C, tmp);
			C++;
		}
	}
	return {odw2, C};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, Q;
	cin >> n >> m >> Q;
	vector<int> indegree(M);
	vector<vector<int>> v(n + 1, vector<int>());
	vector<vector<int>> vr(n + 1, vector<int>());
	vector<vector<int>> w(n + 1, vector<int>());
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		vr[b].push_back(a);
	}

	auto [odw, C] = scc(n, v, vr);
	for (int i = 1; i <= n; i++) {
		for (auto x : v[i]) {
			if (odw[i] != odw[x]) {
				w[odw[x]].push_back(odw[i]);
				indegree[odw[i]]++;
			}
		}
	}

	queue<int> q;
	for (int i = 1; i < C; i++) {
		if (indegree[i] == 0) q.push(i);
	}
	for (int i = 1; i <= n; i++) {
		bit[odw[i]][i] = 1;
	}

	while (!q.empty()) {
		int id = q.front();
		q.pop();
		for (auto x : w[id]) {
			indegree[x]--;
			if (indegree[x] == 0) q.push(x);
			bit[x] |= bit[id];
		}
	}
	while (Q--) {
		int a, b;
		cin >> a >> b;
		if (bit[odw[a]][b])
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
