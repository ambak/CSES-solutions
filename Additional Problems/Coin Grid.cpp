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

	vector<Edge<T>> minCut() {
		vector<Edge<T>> res;
		vector<int> A(n);
		queue<int> q;
		q.push(s);
		A[s] = 1;
		while (!q.empty()) {
			auto u = q.front();
			q.pop();
			for (auto &ed : adj[u]) {
				if (ed.flow < ed.cap && A[ed.to] == 0) {
					q.push(ed.to);
					A[ed.to] = 1;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (A[i]) {
				for (auto &ed : adj[i]) {
					if (A[ed.to] == 0 && ed.flow == ed.cap && ed.cap > 0) {
						res.push_back(ed);
					}
				}
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
	int n;
	cin >> n;
	PushRelabel<LL> pr(2 * n + 2, 0, 2 * n + 1, 1e17L);
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (unsigned j = 0; j < s.size(); j++) {
			if (s[j] == 'o') {
				pr.addEdge(i, j + 1 + n, 1e17L);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		pr.addEdge(0, i, 1);
		pr.addEdge(i + n, 2 * n + 1, 1);
	}
	cout << pr.maxFlow() << "\n";
	auto res = pr.minCut();
	for (auto &ed : res) {
		if (ed.to != 2 * n + 1) {
			cout << "1 " << ed.to << "\n";
		} else {
			cout << "2 " << ed.from - n << "\n";
		}
	}
	return 0;
}
