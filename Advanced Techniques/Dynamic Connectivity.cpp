#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class DSUWithRollback {
public:
	DSUWithRollback(int n) {
		parent.resize(n + 1);
		rank.resize(n + 1);
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
			rank[i] = 1;
		}
		comp = n;
	}
	int find(int x) {
		if (x == parent[x]) {
			return x;
		}
		return find(parent[x]);
	}
	bool unite(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return false;
		if (rank[a] < rank[b]) swap(a, b);
		s.push(DSU(a, b, parent[b], rank[a]));
		parent[b] = parent[a];
		rank[a] += rank[b];
		comp--;
		return true;
	}
	void rollback() {
		auto dsu = s.top();
		s.pop();
		comp++;
		parent[dsu.b] = dsu.parent;
		rank[dsu.a] = dsu.rank;
	}
	int components() {
		return this->comp;
	}
	int size() {
		return s.size();
	}

private:
	vector<int> parent;
	vector<int> rank;
	int comp;
	struct DSU {
		int a, b, parent, rank;
		DSU(int a, int b, int parent, int rank) : a(a), b(b), parent(parent), rank(rank) {}
	};
	stack<DSU> s;
};

class DynamicConnectivity {
public:
	DynamicConnectivity(int n, int k) : dsu(DSUWithRollback(n)) {
		t.resize(4 * k + 9);
		ans.resize(k + 1);
	}
	void add(int b, int e, int u, int v, int l, int r, int st) {
		if (l <= b && r >= e) {
			t[st].push_back(Q(u, v));
			return;
		}
		int mid = (b + e) / 2;
		if (l <= mid) add(b, mid, u, v, l, r, st * 2);
		if (r >= mid + 1) add(mid + 1, e, u, v, l, r, st * 2 + 1);
	}
	void solve(int b, int e, int st = 1) {
		int cnt = 0;
		for (auto &q : t[st]) {
			if (dsu.unite(q.u, q.v)) {
				cnt++;
			}
		}
		if (b == e) {
			ans[b] = dsu.components();
		} else {
			int mid = (b + e) / 2;
			solve(b, mid, st * 2);
			solve(mid + 1, e, st * 2 + 1);
		}
		while (cnt--) {
			dsu.rollback();
		}
	}
	vector<int> answer() {
		return ans;
	}

private:
	DSUWithRollback dsu;
	struct Q {
		int u, v;
		Q(int u = 0, int v = 0) : u(u), v(v) {}
	};
	vector<vector<Q>> t;
	vector<int> ans;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	map<pair<int, int>, vector<pair<int, int>>> g;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		g[{a, b}].push_back({0, k + 1});
	}
	for (int i = 1; i <= k; i++) {
		int c, a, b;
		cin >> c >> a >> b;
		if (a > b) swap(a, b);
		if (c == 1) {
			g[{a, b}].push_back({i, k + 1});
		} else {
			g[{a, b}].back().second = i;
		}
	}
	DynamicConnectivity dc(n, k);
	for (auto &v : g) {
		for (auto [l, r] : v.second) {
			dc.add(0, k + 1, v.first.first, v.first.second, l, r - 1, 1);
		}
	}
	dc.solve(0, k + 1);
	auto ans = dc.answer();
	for (int i = 0; i <= k; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}
