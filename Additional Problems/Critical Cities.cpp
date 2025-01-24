#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class LengauerTarjan {
public:
	LengauerTarjan(int n) : n(n) {
		df = 0;
		succ = vector<vector<int>>(n);
		pred = vector<vector<int>>(n);
		bucket = vector<vector<int>>(n);
		vertex = vector<int>(n, -1);
		dfnum = vector<int>(n);
		sdom = vector<int>(n, -1);
		idom = vector<int>(n);
		parent = vector<int>(n);
		ancestor = vector<int>(n, -1);
	}

	void add_edge(int u, int w) {
		succ[u].push_back(w);
		pred[w].push_back(u);
	}

	vector<int> dominators(int source) {
		dfs(source);
		for (int i = n - 1; i > 0; i--) {
			int w = vertex[i];
			if (w == -1) {
				continue;
			}
			for (auto v : pred[w]) {
				int u = eval(v);
				if (sdom[u] != -1 && dfnum[sdom[u]] < dfnum[sdom[w]]) {
					sdom[w] = sdom[u];
				}
			}
			bucket[sdom[w]].push_back(w);
			link(parent[w], w);
			for (auto v : bucket[parent[w]]) {
				int u = eval(v);
				if (dfnum[sdom[u]] < dfnum[sdom[v]]) {
					idom[v] = u;
				} else {
					idom[v] = parent[w];
				}
			}
			bucket[parent[w]].clear();
		}
		for (int i = 1; i < n; i++) {
			int w = vertex[i];
			if (idom[w] != sdom[w]) {
				idom[w] = idom[idom[w]];
			}
		}
		idom[source] = -1;
		return idom;
	}

private:
	void dfs(int v) {
		dfnum[v] = df;
		vertex[df] = v;
		sdom[v] = v;
		df++;
		for (auto w : succ[v]) {
			if (sdom[w] == -1) {
				parent[w] = v;
				dfs(w);
			}
		}
	}

	int eval(int v) {
		int u = v;
		while (ancestor[v] != -1) {
			if (dfnum[sdom[v]] < dfnum[sdom[u]]) {
				u = v;
			}
			v = ancestor[v];
		}
		return u;
	}

	void link(int v, int w) {
		ancestor[w] = v;
	}

	vector<vector<int>> succ;
	vector<vector<int>> pred;
	vector<vector<int>> bucket;
	vector<int> vertex;
	vector<int> dfnum;
	vector<int> sdom;
	vector<int> idom;
	vector<int> parent;
	vector<int> ancestor;
	int df;
	const int n;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	LengauerTarjan lt(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		lt.add_edge(a, b);
	}
	auto idom = lt.dominators(0);
	set<int> res;
	int w = n - 1;
	while (w != -1) {
		res.insert(w);
		w = idom[w];
	}
	cout << res.size() << "\n";
	for (auto u : res) {
		cout << u + 1 << " ";
	}
	cout << "\n";
	return 0;
}
