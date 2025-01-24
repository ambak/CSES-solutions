#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct project {
	int a;
	int b;
	LL p;
};

vector<project> v;
map<int, LL> m;

int main() {
	ios_base::sync_with_stdio(false);
	LL n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int a, b;
		LL p;
		cin >> a >> b >> p;
		v.push_back(project{a, b, p});
	}
	sort(v.begin(), v.end(), [](project &a, project &b) { return a.b < b.b; });
	LL res = 0;
	for (auto x : v) {
		LL value = 0;
		auto it = m.lower_bound(x.a);
		if (m.size() > 0 && it != m.begin()) {
			it--;
			value = it->second;
		}
		it = m.lower_bound(x.b);
		LL prevvalue = 0;
		if (m.size() > 0 && it != m.begin() && it->first != x.b) {
			it--;
			prevvalue = it->second;
		}
		m[x.b] = max(m[x.b], prevvalue);
		m[x.b] = max(value + x.p, m[x.b]);
		res = max(res, m[x.b]);
	}
	cout << res << "\n";
	return 0;
}
