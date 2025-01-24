#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> v;
vector<pair<LL, pair<int, int> > > ms;
multimap<LL, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	LL n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		LL a;
		cin >> a;
		v.push_back(a);
		if (m.count(a) < 3) {
			m.insert({a, i});
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ms.push_back({v[i] + v[j], {i + 1, j + 1}});
		}
	}
	bool found = false;
	for (auto it : ms) {
		auto E = m.equal_range(x - it.first);
		for (auto e = E.first; e != E.second; e++) {
			if (e->second != it.second.first && e->second != it.second.second) {
				cout << it.second.first << " " << it.second.second << " " << e->second << "\n";
				found = true;
				break;
			}
		}
		if (found) {
			break;
		}
	}
	if (found == false) {
		cout << "IMPOSSIBLE\n";
	}
	return 0;
}
