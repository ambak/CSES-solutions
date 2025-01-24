#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Edge {
	int from, to, cap, cost, id, back_id;
	Edge(int from, int to, int cap, int cost, int id, int back_id) : from(from), to(to), cap(cap), cost(cost), id(id), back_id(back_id) {}
};

const int INF = 1e8;
vector<Edge> v[409];
set<pair<int, int>> matching;
int n, k;

pair<vector<pair<int, int>>, pair<int, int>> bellman_ford() {
	vector<pair<int, int>> dist(n + 1, make_pair(INF, 0));
	vector<pair<int, int>> parent(n + 1);
	dist[0] = {0, INF};
	vector<bool> inqueue(n + 1);
	queue<int> q;
	q.push(0);
	inqueue[0] = true;
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
		while (id != 0) {
			auto &e = v[parent[id].first][parent[id].second];
			v[e.to][e.back_id].cap += K;
			e.cap -= K;
			id = e.from;
		}
		res += 1000 - dist.first * K;
		k -= K;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	vector<int> a(n), b(n);
	LL A = 0, B = 0;
	for (auto &x : a) cin >> x, A += x;
	for (auto &x : b) cin >> x, B += x;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int c;
			cin >> c;
			c = 1000 - c;
			v[i].emplace_back(i, j + n, 1, c, v[i].size(), v[j + n].size());
			v[j + n].emplace_back(j + n, i, 0, -c, v[j + n].size(), v[i].size() - 1);
		}
	}
	for (int i = 1; i <= n; i++) {
		v[0].emplace_back(0, i, a[i - 1], 0, v[0].size(), v[i].size());
		v[i].emplace_back(i, 0, 0, 0, v[i].size(), v[0].size() - 1);
	}
	for (int j = 1; j <= n; j++) {
		v[j + n].emplace_back(j + n, 2 * n + 1, b[j - 1], 0, v[j + n].size(), v[2 * n + 1].size());
		v[2 * n + 1].emplace_back(2 * n + 1, j + n, 0, 0, v[2 * n + 1].size(), v[j + n].size() - 1);
	}
	int N = n;
	n = 2 * n + 1;
	k = A;
	int flow = min_cost_flow();
	if (A != B || k != 0 || flow == -1) {
		cout << "-1\n";
		return 0;
	}
	cout << flow << "\n";
	n = N;
	vector<vector<char>> res(n, vector<char>(n, '.'));
	for (auto &w : v) {
		for (auto &ed : w) {
			if (ed.from > 0 && ed.from < n + 1 && ed.to > n && ed.to < 2 * n + 1 && ed.cap == 0) {
				res[ed.from - 1][ed.to - n - 1] = 'X';
			}
		}
	}
	for (auto &v : res) {
		for (auto c : v) {
			cout << c;
		}
		cout << "\n";
	}
	return 0;
}
