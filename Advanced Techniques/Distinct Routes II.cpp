#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Edge {
	int from, to, cap, cost, id, back_id;
	Edge(int from, int to, int cap, int cost, int id, int back_id) : from(from), to(to), cap(cap), cost(cost), id(id), back_id(back_id) {}
};

const int INF = 1e8;
vector<Edge> v[509];
set<pair<int, int>> matching[509];
int n, m, k;

pair<vector<pair<int, int>>, pair<int, int>> bellman_ford() {
	vector<pair<int, int>> dist(n + 1, make_pair(INF, 0));
	vector<pair<int, int>> parent(n + 1);
	vector<int> neg_cycle(n + 1);
	dist[1] = {0, INF};
	vector<bool> inqueue(n + 1);
	queue<int> q;
	q.push(1);
	inqueue[1] = true;
	while (!q.empty()) {
		int w = q.front();
		q.pop();
		inqueue[w] = false;
		for (auto &e : v[w]) {
			if (e.cap > 0 && dist[e.from].first + e.cost < dist[e.to].first) {
				dist[e.to].first = dist[e.from].first + e.cost;
				dist[e.to].second = min(dist[e.from].second, e.cap);
				parent[e.to] = {e.from, e.id};
				if (inqueue[e.to] == false) {
					inqueue[e.to] = true;
					q.push(e.to);
					neg_cycle[e.to]++;
					if (neg_cycle[e.to] > n) {
						return {parent, dist[n]};
					}
				}
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
			auto &e = v[parent[id].first][parent[id].second];
			e.cap -= K;
			v[e.to][e.back_id].cap += K;
			id = e.from;
			if (e.cost > 0) {
				matching[e.from].insert({e.from, e.to});
			}
			if (e.cost < 0) {
				matching[e.to].erase({e.to, e.from});
			}
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
	int K = k;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].emplace_back(a, b, 1, 1, v[a].size(), v[b].size());
		v[b].emplace_back(b, a, 0, -1, v[b].size(), v[a].size() - 1);
	}
	int res = min_cost_flow();
	cout << res << "\n";
	if (res != -1) {
		for (int i = 0; i < K; i++) {
			vector<int> ans;
			int id = 1;
			ans.push_back(id);
			while (id != n) {
				auto p = *matching[id].begin();
				matching[id].erase(matching[id].begin());
				ans.push_back(p.second);
				id = p.second;
			}
			cout << ans.size() << "\n";
			for (auto a : ans) {
				cout << a << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
