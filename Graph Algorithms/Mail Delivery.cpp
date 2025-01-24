#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, m;
vector<int> v[100009];
stack<int> stos;
vector<int> res;
set<pair<int, int> > odw;

auto prepare_pair(pair<int, int> p) {
	if (p.first > p.second) swap(p.first, p.second);
	return p;
}

void euler() {
	while (!stos.empty()) {
		int u = stos.top();
		bool ok = true;
		for (int i = v[u].size() - 1; i >= 0; i--) {
			int x = v[u][i];
			auto p = prepare_pair({u, x});
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
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	vector<bool> odw(n + 1);
	dfs(1, odw);
	for (int i = 1; i <= n; i++) {
		if (v[i].size() % 2 != 0 || (odw[i] == 0 && !v[i].empty())) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}

	stos.push(1);
	euler();
	for (int x : res) {
		cout << x << " ";
	}
	return 0;
}
