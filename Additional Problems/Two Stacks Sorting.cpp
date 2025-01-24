#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int M = 1 << 19;

int edge[M];
int color[M];

struct dsu {
	int parent, size;
} d[M];

int find(int a) {
	if (a == -1) return a;
	if (d[a].parent == a) {
		return a;
	}
	d[a].parent = find(d[a].parent);
	return d[a].parent;
}

int unite(int a, int b) {
	if (a == -1) return find(b);
	if (b == -1) return find(a);
	int A = find(a);
	int B = find(b);
	if (A == B) return A;
	if (d[A].size > d[B].size) {
		d[B].parent = A;
		d[A].size += d[B].size;
	} else {
		d[A].parent = B;
		d[B].size += d[A].size;
	}
	return find(a);
}

void makeset(int a) {
	d[a].parent = a;
	d[a].size = 1;
}

struct tree {
	vector<int> v;
	int k;
} t[M * 2 + 5];

void update(int a, int v) {
	a += M;
	t[a].v.push_back(v);
	a /= 2;
	while (a != 0) {
		t[a].v.push_back(v);
		a /= 2;
	}
}

bool query(int a, int b) {
	int A = a;
	a += M;
	b += M;
	int parent = -1;
	if (!t[a].v.empty()) parent = unite(t[a].v[t[a].k], parent);
	if (!t[b].v.empty()) parent = unite(t[b].v[t[b].k], parent);
	while (a / 2 != b / 2) {
		if ((a & 1) == 0 && !t[a + 1].v.empty()) {
			for (--t[a + 1].k; t[a + 1].k < int(t[a + 1].v.size()); t[a + 1].k++) {
				if (t[a + 1].k >= 0) {
					parent = unite(t[a + 1].v[t[a + 1].k], parent);
					if (edge[t[a + 1].v[t[a + 1].k]] != -1) {
						unite(edge[t[a + 1].v[t[a + 1].k]], find(A));
					}
					edge[t[a + 1].v[t[a + 1].k]] = find(A);
				}
			}
		}
		if ((b & 1) == 1 && !t[b - 1].v.empty()) {
			for (--t[b - 1].k; t[b - 1].k < int(t[b - 1].v.size()); t[b - 1].k++) {
				if (t[b - 1].k >= 0) {
					parent = unite(t[b - 1].v[t[b - 1].k], parent);
					if (edge[t[b - 1].v[t[b - 1].k]] != -1) {
						unite(edge[t[b - 1].v[t[b - 1].k]], A);
					}
					edge[t[b - 1].v[t[b - 1].k]] = find(A);
				}
			}
		}
		a /= 2;
		b /= 2;
	}
	if (find(parent) == find(A)) {
		return false;
	}
	edge[A] = find(parent);
	edge[find(A)] = find(parent);
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	vector<pair<int, int>> w;
	for (auto& x : v) cin >> x;
	int nx = 1;
	int id = 0;
	vector<int> st(n + 1, -1);
	for (auto x : v) {
		st[x] = id;
		makeset(id);
		id++;
		while (nx <= n && st[nx] != -1) {
			w.emplace_back(st[nx], id);
			st[nx] = -1;
			id++;
			nx++;
		}
	}
	sort(w.begin(), w.end());
	for (int i = 0; i <= id; i++) edge[i] = -1;
	for (auto [a, b] : w) {
		bool ok = query(a, b);
		if (ok == false) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		update(b, a);
	}
	for (auto [a, b] : w) {
		if (color[find(a)] == 0) {
			color[find(a)] = 1;
			if (edge[find(a)] != -1) {
				color[find(edge[find(a)])] = 2;
			}
		}
		cout << color[find(a)] << " ";
	}
	return 0;
}
