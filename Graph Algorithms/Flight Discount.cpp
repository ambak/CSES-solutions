#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<pair<LL, LL>> v[100009];
LL odl[100009];
LL odl2[100009];
LL biggest[100009];
auto cmp = [](LL a, LL b) -> LL { return odl[a] == odl[b] ? a < b : odl[a] < odl[b]; };
set<int, decltype(cmp)> s(cmp);

void dijkstra(LL start, LL n) {
	for (int i = 0; i <= n; i++) {
		odl[i] = LONG_LONG_MAX;
		odl2[i] = LONG_LONG_MAX;
	}
	odl[start] = 0;
	odl2[start] = 0;
	s.insert(start);
	while (!s.empty()) {
		auto p = *s.begin();
		s.erase(s.begin());
		for (auto it : v[p]) {
			LL distance = odl[p] + it.second + biggest[p] - max(biggest[p], it.second / 2 + it.second % 2);
			distance = min(distance, odl2[p] + it.second / 2);
			LL distance2 = odl2[p] + it.second;
			if (distance < odl[it.first] || distance2 < odl2[it.first]) {
				if (distance < odl[it.first]) {
					odl[it.first] = distance;
					biggest[it.first] = max(biggest[p], it.second / 2 + it.second % 2);
				}
				odl2[it.first] = min(distance2, odl2[it.first]);
				if (s.find(it.first) != s.end()) {
					s.erase(s.find(it.first));
				}
				s.insert(it.first);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	LL n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		LL a, b, d;
		cin >> a >> b >> d;
		v[a].push_back({b, d});
	}
	dijkstra(1, n);
	cout << odl[n] << "\n";
	return 0;
}
