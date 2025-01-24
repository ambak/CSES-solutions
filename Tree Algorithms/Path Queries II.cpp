#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int M = 1 << 19;
LL t[M * 2 + 5];
int L[200009][20];

void update(int a, LL v) {
	a += M;
	t[a] = v;
	a /= 2;
	while (a != 0) {
		int l = 2 * a;
		int r = 2 * a + 1;
		t[a] = max(t[l], t[r]);
		a /= 2;
	}
}

LL query(int a, int b) {
	if (a > b) swap(a, b);
	a += M;
	b += M;
	LL res = max(t[a], t[b]);
	while (a / 2 != b / 2) {
		if ((a & 1) == 0) res = max(res, t[a + 1]);
		if ((b & 1) == 1) res = max(res, t[b - 1]);
		a /= 2;
		b /= 2;
	}
	return res;
}

void dfs_lca(int st, int c, vector<int> &odw, vector<vector<int>> &g) {
	odw[st] = c;
	for (auto it : g[st]) {
		if (odw[it] == 0) {
			L[it][1] = st;
			for (int i = 2; i < 20; i++) {
				L[it][i] = L[L[it][i - 1]][i - 1];
			}
			dfs_lca(it, c + 1, odw, g);
		}
	}
}

int LCA(int a, int b, vector<int> &odw) {
	if (odw[a] < odw[b]) {
		swap(a, b);
	}
	int k = odw[a] - odw[b];
	int id = 1;
	while (k) {
		if (k & 1) {
			a = L[a][id];
		}
		k /= 2;
		id++;
	}
	if (a == b) {
		return a;
	}
	for (int i = 19; i > 0; i--) {
		if (L[a][i] != L[b][i]) {
			a = L[a][i];
			b = L[b][i];
		}
	}
	return L[a][1];
}

void dfs_hld(vector<vector<int>> &g, vector<int> &child_size, int st, vector<bool> &odw, vector<int> &parent) {
	odw[st] = true;
	for (auto x : g[st]) {
		if (odw[x] == false) {
			parent[x] = st;
			dfs_hld(g, child_size, x, odw, parent);
			child_size[st] += child_size[x] + 1;
		}
	}
}

void dfs_hld2(vector<vector<int>> &g, vector<int> &child_size, vector<int> &d, int st, vector<bool> &odw, int &id, vector<int> &path_end, int p_e) {
	odw[st] = true;
	path_end[st] = p_e;
	d[st] = id;
	id++;
	pair<int, int> heavy = {-1, -1};
	for (auto x : g[st]) {
		if (odw[x] == false && child_size[x] > heavy.first) {
			heavy = {child_size[x], x};
		}
	}
	if (heavy.second != -1) {
		dfs_hld2(g, child_size, d, heavy.second, odw, id, path_end, p_e);
	}
	for (auto x : g[st]) {
		if (odw[x] == false && x != heavy.second) {
			dfs_hld2(g, child_size, d, x, odw, id, path_end, x);
		}
	}
}

void HLD(vector<vector<int>> &g, vector<int> &d, vector<int> &path_end, vector<int> &parent) {
	vector<bool> odw(d.size());
	vector<int> child_size(d.size());
	parent[1] = 1;
	dfs_hld(g, child_size, 1, odw, parent);
	for (auto x : odw) x = false;
	int id = 1;
	dfs_hld2(g, child_size, d, 1, odw, id, path_end, 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> v(n + 1);
	vector<int> d(n + 1);
	vector<int> odw_lca(n + 1);
	vector<int> path_end(n + 1);
	vector<int> parent(n + 1);
	vector<vector<int>> g(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs_lca(1, 1, odw_lca, g);
	HLD(g, d, path_end, parent);
	for (int i = 1; i <= n; i++) {
		update(d[i], v[i]);
	}
	while (q--) {
		int Q;
		cin >> Q;
		if (Q == 1) {
			int s, x;
			cin >> s >> x;
			update(d[s], x);
		} else if (Q == 2) {
			int a, b;
			cin >> a >> b;
			int lca = LCA(a, b, odw_lca);
			int res = query(d[lca], d[lca]);
			while (a != lca) {
				int X;
				if (odw_lca[path_end[a]] > odw_lca[lca]) {
					X = query(d[a], d[path_end[a]]);
					a = parent[path_end[a]];
				} else {
					X = query(d[a], d[lca]);
					a = lca;
				}
				res = max(res, X);
			}
			while (b != lca) {
				int X;
				if (odw_lca[path_end[b]] > odw_lca[lca]) {
					X = query(d[b], d[path_end[b]]);
					b = parent[path_end[b]];
				} else {
					X = query(d[b], d[lca]);
					b = lca;
				}
				res = max(res, X);
			}
			cout << res << " ";
		}
	}
	return 0;
}
