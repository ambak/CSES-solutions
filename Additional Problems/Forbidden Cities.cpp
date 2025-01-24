#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

pair<int, int> low[100009];
vector<int> v[100009];
bool res[100009];
stack<pair<int, int>> s;
vector<set<int>> w;
vector<int> g[200009];
int t[100009];

void dfs(int st, int &C, int parent) {
	low[st] = {C, C};
	int cnt = 0;
	for (auto x : v[st]) {
		if (x == parent) {
			continue;
		}
		if (low[x].first == 0) {
			s.push({st, x});
			C++;
			cnt++;
			dfs(x, C, st);
			if (st != 1 && low[x].second >= low[st].first) {
				res[st] = true;
				set<int> c;
				int id = w.size();
				while (!s.empty()) {
					auto [a, b] = s.top();
					s.pop();
					c.insert(a);
					c.insert(b);
					if (t[a] == 0) t[a] = id;
					if (t[b] == 0) t[b] = id;
					if (a == st || b == st) break;
				}
				w.push_back(c);
				t[st] = w.size();
				w.push_back({st});
			}
			low[st].second = min(low[st].second, low[x].second);
		} else {
			low[st].second = min(low[st].second, low[x].first);
		}
	}
	if (st == 1 && cnt > 1) {
		res[st] = true;
		set<int> c;
		int id = w.size();
		while (!s.empty()) {
			auto [a, b] = s.top();
			s.pop();
			c.insert(a);
			c.insert(b);
			if (t[a] == 0) t[a] = id;
			if (t[b] == 0) t[b] = id;
			if (a == st || b == st) break;
		}
		w.push_back(c);
		t[st] = w.size();
		w.push_back({st});
	}
}

class LCA {
public:
	LCA(int n) {
		odw = vector<int>(2 * n + 2);
		d = vector<vector<int>>(2 * n + 2, vector<int>(20));
	}
	void dfs(int st, int c) {
		odw[st] = c;
		for (auto it : g[st]) {
			if (odw[it] == 0) {
				d[it][1] = st;
				for (int i = 2; i < 20; i++) {
					d[it][i] = d[d[it][i - 1]][i - 1];
				}
				dfs(it, c + 1);
			}
		}
	}

	int query(int a, int b) {
		if (odw[a] < odw[b]) {
			swap(a, b);
		}
		int k = odw[a] - odw[b];
		int id = 1;
		while (k) {
			if (k & 1) {
				a = d[a][id];
			}
			k /= 2;
			id++;
		}
		if (a == b) {
			return a;
		}
		for (int i = 19; i > 0; i--) {
			if (d[a][i] != d[b][i]) {
				a = d[a][i];
				b = d[b][i];
			}
		}
		return d[a][1];
	}

private:
	vector<int> odw;
	vector<vector<int>> d;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int C = 1;
	dfs(1, C, 0);
	set<int> c;
	int id = w.size();
	while (!s.empty()) {
		auto [a, b] = s.top();
		s.pop();
		c.insert(a);
		c.insert(b);
		if (t[a] == 0) t[a] = id;
		if (t[b] == 0) t[b] = id;
	}
	w.push_back(c);
	set<int> articulation_points;
	for (int i = 1; i <= n; i++) {
		if (res[i]) articulation_points.insert(i);
	}

	for (unsigned i = 0; i < w.size(); i++) {
		if (w[i].size() == 1)
			continue;
		else {
			for (auto x : w[i]) {
				if (res[x] == true) {
					int y = t[x];
					g[i].push_back(y);
					g[y].push_back(i);
				}
			}
		}
	}

	auto lca = LCA(n);
	lca.dfs(0, 1);
	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == c || b == c) {
			cout << "NO\n";
			continue;
		}
		if (articulation_points.find(c) == articulation_points.end()) {
			cout << "YES\n";
		} else {
			a = t[a];
			b = t[b];
			c = t[c];
			int l1 = lca.query(a, b);
			int l2 = lca.query(a, c);
			int l3 = lca.query(b, c);
			if (l1 == c || (l1 == l2 && l3 == c) || (l1 == l3 && l2 == c))
				cout << "NO\n";
			else
				cout << "YES\n";
		}
	}
	return 0;
}
