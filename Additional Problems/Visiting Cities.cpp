#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<pair<LL, LL> > v[200009];
vector<LL> w[200009];
LL odl[200009];
LL n, m;

auto cmp = [](LL a, LL b) {if (odl[a] != odl[b]) return odl[a] < odl[b]; return a < b; };
set<LL, decltype(cmp)> q(cmp);
set<LL> parent[200009];

void dijkstra() {
	for (LL i = 2; i <= n; i++) {
		odl[i] = __LONG_LONG_MAX__;
	}
	q.insert(1);
	while (!q.empty()) {
		auto x = *q.begin();
		q.erase(q.begin());
		for (unsigned i = 0; i < v[x].size(); i++) {
			if (odl[x] + v[x][i].second < odl[v[x][i].first]) {
				if (q.find(v[x][i].first) != q.end()) {
					q.erase(v[x][i].first);
				}
				odl[v[x][i].first] = odl[x] + v[x][i].second;
				q.insert(v[x][i].first);
				parent[v[x][i].first].clear();
				parent[v[x][i].first].insert(x);
			} else if (odl[x] + v[x][i].second == odl[v[x][i].first]) {
				parent[v[x][i].first].insert(x);
			}
		}
	}
}

pair<int, int> low[200009];
bool res[200009];

void dfs(int st, int &C, int parent) {
	low[st] = {C, C};
	int cnt = 0;
	for (auto x : w[st]) {
		if (x == parent) {
			continue;
		}
		if (low[x].first == 0) {
			C++;
			cnt++;
			dfs(x, C, st);
			if (st != 1 && low[x].second >= low[st].first) {
				res[st] = true;
			}
			low[st].second = min(low[st].second, low[x].second);
		} else {
			low[st].second = min(low[st].second, low[x].first);
		}
	}
	if (st == 1 && cnt > 1) res[st] = true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (LL i = 0; i < m; i++) {
		LL a, b, d;
		cin >> a >> b >> d;
		v[a].push_back({b, d});
	}
	dijkstra();
	queue<LL> q;
	q.push(n);
	vector<bool> odw(2 * n + 5);
	odw[n] = true;
	while (!q.empty()) {
		auto x = q.front();
		q.pop();
		for (auto a : parent[x]) {
			if (odw[a] == false) {
				odw[a] = true;
				q.push(a);
			}
			w[a].push_back(x);
			w[x].push_back(a);
		}
	}

	int C = 1;
	dfs(1, C, 0);
	res[1] = true;
	res[n] = true;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (res[i]) {
			ans++;
		}
	}
	cout << ans << "\n";
	for (int i = 1; i <= n; i++) {
		if (res[i]) {
			cout << i << " ";
		}
	}
	return 0;
}
