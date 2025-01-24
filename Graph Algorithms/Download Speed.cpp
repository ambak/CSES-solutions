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
	PushRelabel(int n, int s, int t, T inf) : n(n), s(s), t(t), inf(inf), excess(n), height(n), adj(n), maxHeight(n * 3) {};

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
		int H = 0;
		while (H >= 0) {
			for (int i = maxHeight[H].size() - 1; i >= 0; i--) {
				int u = maxHeight[H][i];
				maxHeight[H].pop_back();
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
					break;
				}
				if (excess[u] > 0) {
					maxHeight[height[u]].push_back(u);
				}
			}
			while (maxHeight[H].empty() && H >= 0) {
				H--;
			}
		}
		return excess[t];
	}

private:
	int n, s, t;
	const T inf;
	vector<T> excess;
	vector<int> height;
	vector<vector<Edge<T>>> adj;
	vector<vector<int>> maxHeight;

	int push(Edge<T> &e) {
		T d = min(excess[e.from], e.cap - e.flow);
		e.flow += d;
		excess[e.to] += d;
		adj[e.to][e.idx].flow -= d;
		excess[e.from] -= d;
		if (e.to != t && e.to != s && excess[e.to]) {
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
		if (d != 3 * n) {
			height[u] = d + 1;
			maxHeight[d + 1].push_back(u);
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
		LL c;
		cin >> a >> b >> c;
		pr.addEdge(a - 1, b - 1, c);
	}
	cout << pr.maxFlow() << "\n";

	return 0;
}
