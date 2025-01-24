#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL cross_product(pair<LL, LL> start, pair<LL, LL> a, pair<LL, LL> b) {
	return (a.first - start.first) * (b.second - start.second) - (b.first - start.first) * (a.second - start.second);
}

vector<pair<LL, LL> > convex_hull(vector<pair<LL, LL> > &v) {
	sort(v.begin(), v.end());
	vector<pair<LL, LL> > res;
	for (auto p : v) {
		while (res.size() > 1 && cross_product(res[res.size() - 2], res.back(), p) > 0) {
			res.pop_back();
		}
		res.push_back(p);
	}
	auto cmp = [](pair<LL, LL> a, pair<LL, LL> b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		return a.first > b.first;
	};
	sort(v.begin(), v.end(), cmp);
	for (unsigned i = 1; i < v.size(); i++) {
		while (res.size() > 1 && cross_product(res[res.size() - 2], res.back(), v[i]) > 0) {
			res.pop_back();
		}
		res.push_back(v[i]);
	}
	if (res.back() == res[0]) res.pop_back();
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	LL n;
	cin >> n;
	vector<pair<LL, LL> > v;
	for (LL i = 0; i < n; i++) {
		LL x, y;
		cin >> x >> y;
		v.emplace_back(x, y);
	}
	vector<pair<LL, LL> > res = convex_hull(v);

	cout << res.size() << "\n";
	for (auto [x, y] : res) {
		cout << x << " " << y << "\n";
	}
	return 0;
}
