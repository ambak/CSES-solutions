#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<pair<int, int> > v;
multiset<int> m;

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end());
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (int(m.size()) < k) {
			m.insert(v[i].second);
			continue;
		}
		if (*m.begin() <= v[i].first) {
			res++;
			m.erase(m.begin());
			m.insert(v[i].second);
		} else if (*m.rbegin() > v[i].second) {
			m.erase(m.find(*m.rbegin()));
			m.insert(v[i].second);
		}
	}
	cout << res + m.size() << "\n";
	return 0;
}
