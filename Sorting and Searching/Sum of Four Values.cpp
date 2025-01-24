#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> v;
unordered_multimap<LL, pair<int, int> > ms;

int main() {
	ios_base::sync_with_stdio(false);
	LL n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		LL a;
		cin >> a;
		v.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ms.insert({v[i] + v[j], {i + 1, j + 1}});
		}
	}
	bool found = false;
	for (auto it : ms) {
		auto E = ms.equal_range(x - it.first);
		for (auto e = E.first; e != E.second; e++) {
			if (e->second.first != it.second.first && e->second.first != it.second.second && e->second.second != it.second.first && e->second.second != it.second.second) {
				cout << it.second.first << " " << it.second.second << " " << e->second.first << " " << e->second.second << "\n";
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
