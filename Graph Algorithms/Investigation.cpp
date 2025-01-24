#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<pair<int, int> > v[200009];
pair<LL, LL> parent[200009];  // first: number of routes % MOD; second: minimum price
int longest[200009];
int shortest[200009];
const int MOD = 1e9 + 7;
bool odw[200009];

set<pair<LL, LL> > q;

void dijkstra() {
	q.insert({0, 1});
	while (!q.empty()) {
		auto [ss, s] = *q.begin();
		q.erase(q.begin());
		if (odw[s]) {
			continue;
		}
		odw[s] = true;
		for (auto [x, y] : v[s]) {
			if (parent[x].second > parent[s].second + y) {
				parent[x].second = parent[s].second + y;
				parent[x].first = parent[s].first;
				longest[x] = longest[s] + 1;
				shortest[x] = shortest[s] + 1;
				q.insert({parent[x].second, x});
			} else if (parent[x].second == parent[s].second + y) {
				parent[x].first = (parent[x].first + parent[s].first) % MOD;
				longest[x] = max(longest[x], longest[s] + 1);
				shortest[x] = min(shortest[x], shortest[s] + 1);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = {0, LONG_LONG_MAX};
	}
	parent[1] = {1, 0};
	dijkstra();
	cout << parent[n].second << " " << parent[n].first << " " << shortest[n] << " " << longest[n] << "\n";

	return 0;
}
