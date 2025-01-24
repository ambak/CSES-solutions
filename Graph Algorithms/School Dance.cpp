#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

class Matching {
public:
	Matching(int n, int m) : n(n), m(m), v(n + m), mt(n + m), odw(n + m) {};
	void addEdge(int a, int b) {
		v[a].push_back(b);
		v[b].push_back(a);
	}
	vector<pair<int, int>> match() {
		vector<pair<int, int>> res;
		for (int i = 0; i < n + m; i++) {
			mt[i] = -1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n + m; j++) {
				odw[j] = false;
			}
			dfs(i);
		}
		for (int i = 0; i < n + m; i++) {
			if (mt[i] != -1 && mt[i] > i) {
				res.emplace_back(i, mt[i]);
			}
		}
		return res;
	}

private:
	const int n, m;
	vector<vector<int>> v;
	vector<int> mt;
	vector<bool> odw;

	bool dfs(int st) {
		odw[st] = true;
		for (auto u : v[st]) {
			if (mt[u] == -1 || (!odw[mt[u]] && dfs(mt[u]))) {
				mt[u] = st;
				mt[st] = u;
				return true;
			}
		}
		return false;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	Matching match(n, m);
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		match.addEdge(a - 1, b - 1 + n);
	}

	auto res = match.match();
	cout << res.size() << "\n";
	for (auto [a, b] : res) {
		cout << a + 1 << " " << b + 1 - n << "\n";
	}
	return 0;
}
