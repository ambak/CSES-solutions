#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, m;
vector<int> v[100009];
stack<int> stos;
vector<int> res;
set<pair<int, int> > odw;

void euler() {
	while (!stos.empty()) {
		int u = stos.top();
		bool ok = true;
		for (int i = v[u].size() - 1; i >= 0; i--) {
			int x = v[u][i];
			auto p = make_pair(u, x);
			v[u].pop_back();
			auto it = odw.find(p);
			if (it != odw.end()) {
				continue;
			}
			odw.insert(p);
			stos.push(x);
			ok = false;
			break;
		}
		if (ok == false) {
			continue;
		}
		res.push_back(u);
		stos.pop();
	}
}

void dfs(int st, vector<bool>& odw) {
	odw[st] = true;
	for (int x : v[st]) {
		if (odw[x] == false) {
			dfs(x, odw);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	vector<unsigned> indegree(n + 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}

	vector<bool> odw(n + 1);
	dfs(1, odw);
	for (int i = 2; i < n; i++) {
		if (v[i].size() != indegree[i] || (odw[i] == 0 && !v[i].empty())) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
	if (v[1].size() != indegree[1] + 1 || v[n].size() != indegree[n] - 1) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}

	stos.push(1);
	euler();
	reverse(res.begin(), res.end());
	for (int x : res) {
		cout << x << " ";
	}
	return 0;
}
