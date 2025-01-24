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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, int>> a(m);
	vector<pair<int, int>> b(k);
	set<pair<int, int>> sa;
	DSUWithRollback dsu(n);
	for (auto &[st, nd] : a) {
		cin >> st >> nd;
		if (st > nd) swap(st, nd);
		sa.insert({st, nd});
	}
	for (auto &[st, nd] : b) {
		cin >> st >> nd;
		if (st > nd) swap(st, nd);
		sa.erase(sa.find({st, nd}));
	}
	for (auto &[st, nd] : sa) {
		dsu.unite(st, nd);
	}
	vector<bool> odw(k);
	for (int i = k - 1; i >= 0; i--) {
		if (dsu.unite(b[i].first, b[i].second)) {
			odw[i] = true;
		}
	}
	for (int i = 0; i < k; i++) {
		if (odw[i]) {
			dsu.rollback();
		}
		cout << dsu.components() << " ";
	}
	cout << "\n";
	return 0;
}
