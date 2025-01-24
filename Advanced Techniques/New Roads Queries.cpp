#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

pair<vector<vector<pair<int, int>>>, vector<int>> spanning_tree(vector<tuple<int, int, int>> &edges, int n) {
	vector<vector<pair<int, int>>> trees(n + 1);
	vector<int> roots_list;
	vector<bool> odw(n + 1);
	priority_queue<tuple<int, int, int>> pq;
	vector<vector<pair<int, int>>> G(n + 1, vector<pair<int, int>>());
	for (auto [i, a, b] : edges) {
		G[a].push_back({b, i});
		G[b].push_back({a, i});
	}
	for (int i = 1; i <= n; i++) {
		if (odw[i] == false) {
			odw[i] = true;
			roots_list.push_back(i);
			for (auto [a, id] : G[i]) {
				pq.push({-id, a, i});
			}
			while (!pq.empty()) {
				auto [id, a, b] = pq.top();
				id = -id;
				pq.pop();
				if (odw[a] == false) {
					odw[a] = true;
					trees[b].emplace_back(a, id);
					trees[a].emplace_back(b, id);
					for (auto [A, ID] : G[a]) {
						pq.push({-ID, A, a});
					}
				}
			}
		}
	}
	return {trees, roots_list};
}

class LCA {
public:
	LCA(vector<int> roots_list, vector<vector<pair<int, int>>> v, int n) : v(v), roots_list(roots_list), n(n) {
		odw.resize(n + 1);
		number.resize(n + 1);
		d.resize(n + 1);
		for (auto &dd : d) dd.resize(20);
		for (int nr = 1; nr <= (int)roots_list.size(); nr++) {
			dfs(roots_list[nr - 1], 1, nr);
		}
	}

	void dfs(int st, int c, int nr) {
		odw[st] = c;
		number[st] = nr;
		for (auto [it, cost] : v[st]) {
			if (odw[it] == 0) {
				d[it][1].first = st;
				d[it][1].second = cost;
				for (int i = 2; i < 20; i++) {
					d[it][i].first = d[d[it][i - 1].first][i - 1].first;
					d[it][i].second = max(d[d[it][i - 1].first][i - 1].second, d[it][i - 1].second);
				}
				dfs(it, c + 1, nr);
			}
		}
	}

	int query(int a, int b) {
		int cost = 0;
		if (number[a] != number[b])
			return -1;
		if (odw[a] < odw[b]) {
			swap(a, b);
		}
		int k = odw[a] - odw[b];
		int id = 1;
		while (k) {
			if (k & 1) {
				cost = max(cost, d[a][id].second);
				a = d[a][id].first;
			}
			k /= 2;
			id++;
		}
		if (a == b) {
			return cost;
		}
		for (int i = 19; i > 0; i--) {
			if (d[a][i].first != d[b][i].first) {
				cost = max(cost, d[a][i].second);
				a = d[a][i].first;
				cost = max(cost, d[b][i].second);
				b = d[b][i].first;
			}
		}
		while (a != b) {
			cost = max(cost, d[a][1].second);
			a = d[a][1].first;
			cost = max(cost, d[b][1].second);
			b = d[b][1].first;
		}
		return cost;
	}

private:
	vector<vector<pair<int, int>>> v;
	vector<int> roots_list;
	int n;
	vector<int> odw;
	vector<int> number;
	vector<vector<pair<int, int>>> d;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	vector<tuple<int, int, int>> edges;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		edges.emplace_back(i, a, b);
	}
	auto [trees, roots_list] = spanning_tree(edges, n);
	LCA lca = LCA(roots_list, trees, n);
	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << lca.query(a, b) << "\n";
	}
	return 0;
}
