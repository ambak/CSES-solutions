#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Edge {
	int from, to, cap, cost, id, back_id;
	Edge(int from, int to, int cap, int cost, int id, int back_id) : from(from), to(to), cap(cap), cost(cost), id(id), back_id(back_id) {}
};

const int INF = 1e8;
vector<Edge> v;
int n, m, k;

pair<vector<int>, pair<int, int>> bellman_ford() {
	vector<pair<int, int>> dist(n + 1, make_pair(INF, 0));
	vector<int> parent(n + 1);
	dist[1] = {0, INF};
	for (int i = 1; i <= n; i++) {
		for (auto &e : v) {
			if (e.cap > 0 && dist[e.from].first + e.cost < dist[e.to].first) {
				dist[e.to].first = dist[e.from].first + e.cost;
				dist[e.to].second = min(dist[e.from].second, e.cap);
				parent[e.to] = e.id;
			}
		}
	}
	return {parent, dist[n]};
}

int min_cost_flow() {
	int res = 0;
	while (k) {
		auto [parent, dist] = bellman_ford();
		if (dist.second == 0) {
			return -1;
		}
		int id = n;
		int K = min(dist.second, k);
		while (id != 1) {
			auto e = v[parent[id]];
			v[e.id].cap -= K;
			v[e.back_id].cap += K;
			id = e.from;
		}
		res += dist.first * K;
		k -= K;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, r, c;
		cin >> a >> b >> r >> c;
		v.emplace_back(a, b, r, c, v.size(), v.size() + 1);
		v.emplace_back(b, a, 0, -c, v.size(), v.size() - 1);
	}
	cout << min_cost_flow() << "\n";
	return 0;
}
