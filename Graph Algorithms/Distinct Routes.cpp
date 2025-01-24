#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <typename T>
struct Edge {
	T cap, flow;
	int from, to, idx;
	Edge(T cap, T flow, int from, int to, int idx) : cap(cap), flow(flow), from(from), to(to), idx(idx) {};
};

template <typename T>
class PushRelabel {
public:
	PushRelabel(int n, int s, int t, T inf) : n(n), s(s), t(t), inf(inf), excess(n), height(n), adj(n), maxHeight(n * 3), active(n) {};

	void addEdge(int from, int to, T cap) {
		if (from != to) {
			adj[from].emplace_back(cap, T(0), from, to, adj[to].size());
			adj[to].emplace_back(T(0), T(0), to, from, adj[from].size() - 1);
		}
	}

	T maxFlow() {
		excess[s] = inf;
		height[s] = n;
		for (auto &ed : adj[s]) {
			push(ed);
		}
		active[s] = true;
		int H = 0;
		while (H >= 0) {
			if (!maxHeight[H].empty()) {
				int u = maxHeight[H].back();
				maxHeight[H].pop_back();
				active[u] = false;
				if (excess[u] <= 0) {
					continue;
				}
				bool pushed = false;
				for (auto &ed : adj[u]) {
					if (height[u] == height[ed.to] + 1 && ed.cap - ed.flow > 0) {
						H = max(push(ed), H);
						pushed = true;
					}
				}
				if (pushed == false) {
					relabel(u);
					H = max(height[u], H);
					continue;
				}
				if (excess[u] > 0) {
					maxHeight[height[u]].push_back(u);
				}
			} else {
				H--;
			}
		}
		return excess[t];
	}

	set<pair<int, int>> minCut() {
		odw.assign(n, false);
		set<pair<int, int>> res;
		adj2.assign(n, vector<int>());
		maxFlow();
		for (int i = 0; i < n; i++) {
			for (auto &ed : adj[i]) {
				if (ed.cap > 0 && ed.flow > 0) {
					adj2[ed.to].push_back(ed.from);
				} else if (ed.cap > 0 && ed.flow <= 0) {
					adj2[ed.from].push_back(ed.to);
				}
			}
		}
		dfs(s);
		for (int i = 0; i < n; i++) {
			for (int u : adj2[i]) {
				if ((!odw[i] && odw[u]) || (odw[i] && !odw[u])) {
					if (u < i) {
						res.insert({u, i});
					} else {
						res.insert({i, u});
					}
				}
			}
		}
		return res;
	}

	// finds all paths only in a graph with all paths of capacity 1
	// must run maxFlow before
	// it modifies the graph
	vector<vector<int>> getPaths() {
		vector<vector<int>> res(excess[t]);
		odwP.assign(n, false);
		int i = 0;
		for (auto &ed : adj[s]) {
			if (ed.flow > 0) {
				ed.flow = 0;
				res[i].push_back(s);
				dfsPaths(ed.to, res[i]);
				i++;
			}
		}
		return res;
	}

private:
	int n, s, t;
	const T inf;
	vector<T> excess;
	vector<int> height;
	vector<vector<Edge<T>>> adj;
	vector<vector<int>> maxHeight;
	vector<bool> active;
	vector<bool> odw;
	vector<vector<int>> adj2;
	vector<bool> odwP;

	int push(Edge<T> &e) {
		T d = min(excess[e.from], e.cap - e.flow);
		e.flow += d;
		excess[e.to] += d;
		adj[e.to][e.idx].flow -= d;
		excess[e.from] -= d;
		if (e.to != t && e.to != s && excess[e.to] && !active[e.to]) {
			active[e.to] = true;
			maxHeight[height[e.to]].push_back(e.to);
			return height[e.to];
		}
		return 0;
	}

	void relabel(int u) {
		int d = 3 * n;
		for (auto &ed : adj[u]) {
			if (ed.cap - ed.flow > 0) {
				d = min(d, height[ed.to]);
			}
		}
		if (d != 3 * n && !active[u]) {
			active[u] = true;
			height[u] = d + 1;
			maxHeight[d + 1].push_back(u);
		}
	}

	void dfs(int st) {
		odw[st] = true;
		for (auto i : adj2[st]) {
			if (odw[i] == false) {
				dfs(i);
			}
		}
	}

	void dfsPaths(int st, vector<int> &res) {
		res.push_back(st);
		for (auto &ed : adj[st]) {
			if (ed.flow > 0) {
				ed.flow = 0;
				dfsPaths(ed.to, res);
				break;
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	PushRelabel<LL> pr(n, 0, n - 1, 1e17L);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		pr.addEdge(a - 1, b - 1, 1);
	}
	cout << pr.maxFlow() << "\n";
	auto res = pr.getPaths();
	for (auto &ans : res) {
		cout << ans.size() << "\n";
		for (auto u : ans) {
			cout << u + 1 << " ";
		}
		cout << "\n";
	}
	return 0;
}
