#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct dsu {
	int parent, size;
} d[100009];

int find(int a) {
	if (d[a].parent == a) {
		return a;
	}
	d[a].parent = find(d[a].parent);
	return d[a].parent;
}

void unite(int a, int b) {
	int A = find(a);
	int B = find(b);
	if (A == B) return;
	if (d[A].size > d[B].size) {
		d[B].parent = A;
		d[A].size += d[B].size;
	} else {
		d[A].parent = B;
		d[B].size += d[A].size;
	}
}

void makeset(int a) {
	d[a].parent = a;
	d[a].size = 1;
}

bool dfs(int st, vector<int> &marked, vector<vector<int>> &v) {
	marked[st] = 1;
	bool ans = false;
	for (auto x : v[st]) {
		if (marked[x] == 0) {
			ans |= dfs(x, marked, v);
		} else if (marked[x] == 1) {
			ans = true;
		}
	}
	marked[st] = 2;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	int res = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) makeset(i);
	vector<vector<int>> v(n + 1, vector<int>());
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		unite(a, b);
	}
	map<int, vector<int>> w;
	for (int i = 1; i <= n; i++) {
		w[find(i)].push_back(i);
	}
	vector<int> marked(n + 1);
	for (auto &[_, vec] : w) {
		bool cycle = false;
		for (auto u : vec) {
			if (marked[u] == 0) {
				cycle |= dfs(u, marked, v);
			}
		}
		res += vec.size();
		if (cycle == false) res--;
	}
	cout << res << "\n";
	return 0;
}
