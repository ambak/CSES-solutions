#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<pair<LL, LL> > v[100009];
vector<LL> res[100009];
int n, m;
unsigned k;

auto cmp = [](pair<LL, LL> a, pair<LL, LL> b) {
	if (a.second == b.second) {
		return a < b;
	}
	return a.second < b.second;
};
multiset<pair<LL, LL>, decltype(cmp)> s(cmp);

void dijkstra() {
	s.insert({1, 0});
	while (!s.empty()) {
		auto x = *s.begin();
		s.erase(s.begin());
		if (res[x.first].size() == k) continue;
		res[x.first].push_back(x.second);
		for (auto q : v[x.first]) {
			s.insert({q.first, q.second + x.second});
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		LL a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
	}
	dijkstra();
	for (auto x : res[n]) {
		cout << x << " ";
	}
	return 0;
}
