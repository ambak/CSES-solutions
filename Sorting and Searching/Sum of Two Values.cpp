#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

multimap<int, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		m.insert({a, i});
	}
	if (x % 2 == 0 && m.count(x / 2) > 1) {
		auto range = m.equal_range(x / 2);
		int count = 0;
		for (auto it = range.first; it != range.second && count < 2; it++, count++) {
			cout << it->second + 1 << " ";
		}
		return 0;
	} else {
		for (auto it : m) {
			auto jt = m.find(x - (it.first));
			if (jt != m.end() && jt->second != it.second) {
				cout << it.second + 1 << " " << jt->second + 1;
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
