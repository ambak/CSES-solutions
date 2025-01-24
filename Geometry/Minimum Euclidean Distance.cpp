#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL distance(pair<LL, LL> a, pair<LL, LL> b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
	ios_base::sync_with_stdio(false);
	LL n;
	cin >> n;
	vector<pair<LL, LL>> v;
	for (LL i = 0; i < n; i++) {
		LL x, y;
		cin >> x >> y;
		v.emplace_back(x, y);
	}
	sort(v.begin(), v.end());
	LL res = LONG_LONG_MAX;
	set<pair<LL, LL>> s;
	s.insert({v[0].second, v[0].first});
	int j = 0;
	for (int i = 1; i < n; i++) {
		LL dd = sqrt(res) + 1;
		auto itlow = s.lower_bound({v[i].second - dd, v[i].first - dd});
		auto itup = s.upper_bound({v[i].second + dd, v[i].first + dd});
		for (auto it = itlow; it != itup; it++) {
			res = min(res, distance({it->second, it->first}, v[i]));
		}
		while (v[i].first - v[j].first >= dd) {
			s.erase({v[j].second, v[j].first});
			j++;
		}
		s.insert({v[i].second, v[i].first});
	}
	cout << res << "\n";
	return 0;
}
