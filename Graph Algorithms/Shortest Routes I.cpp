#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<pair<LL, LL> > v[200009];

LL odl[200009];
int n, m;

auto cmp = [](LL a, LL b) {if (odl[a] != odl[b]) return odl[a] < odl[b]; return a < b; };
std::set<LL, decltype(cmp)> q(cmp);

void dijkstra() {
	for (int i = 2; i <= n; i++) {
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
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		v[a].push_back({b, d});
	}
	dijkstra();
	for (int i = 1; i <= n; i++) {
		cout << odl[i] << " ";
	}
	return 0;
}