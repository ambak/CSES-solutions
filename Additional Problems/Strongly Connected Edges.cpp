#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v[100009];
vector<int> w[100009];
bool odw[100009];
pair<int, int> low[100009];
vector<pair<int, int>> bridge;
set<pair<int, int>> used;

void bridges(int st, int &C, int parent) {
	low[st] = {C, C};
	for (auto x : v[st]) {
		if (x == parent) {
			continue;
		}
		if (low[x].first == 0) {
			C++;
			bridges(x, C, st);
			low[st].second = min(low[st].second, low[x].second);
		} else {
			low[st].second = min(low[st].second, low[x].first);
		}
	}
	if (low[st].first == low[st].second) {
		bridge.push_back({st, parent});
	}
}

void dfs(int st) {
	odw[st] = true;
	for (auto x : v[st]) {
		if (used.find(make_pair(st, x)) == used.end() && used.find(make_pair(x, st)) == used.end()) {
			w[st].push_back(x);
			used.insert(make_pair(st, x));
		}
		if (odw[x] == false) {
			dfs(x);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	int C = 1;
	bridges(1, C, 0);
	bridge.pop_back();
	bool distinct = false;
	for (int i = 1; i <= n; i++) {
		if (low[i] == make_pair(0, 0)) {
			distinct = true;
		}
	}
	if (bridge.size() > 0 || distinct == true) {
		cout << "IMPOSSIBLE\n";
	} else {
		dfs(1);
		for (int i = 1; i <= n; i++) {
			for (auto x : w[i]) {
				cout << i << " " << x << "\n";
			}
		}
	}
	return 0;
}
