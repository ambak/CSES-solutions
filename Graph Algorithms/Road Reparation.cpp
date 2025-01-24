#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<pair<int, int> > v[100009];
bool odw[100009];

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}
	LL res = 0;
	set<pair<int, int> > s;
	odw[1] = true;
	for (auto x : v[1]) {
		s.insert({x.second, x.first});
	}
	while (!s.empty()) {
		auto y = *s.begin();
		s.erase(s.begin());
		if (odw[y.second] == false) {
			odw[y.second] = true;
			res += y.first;
			for (auto x : v[y.second]) {
				s.insert({x.second, x.first});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (odw[i] == false) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}
	cout << res << "\n";
	return 0;
}
