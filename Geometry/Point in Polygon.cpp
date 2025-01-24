#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL cross_product(pair<LL, LL> p1, pair<LL, LL> p2, pair<LL, LL> p3) {
	return (p3.first - p1.first) * (p3.second - p2.second) - (p3.first - p2.first) * (p3.second - p1.second);
}

LL intersect(pair<LL, LL> p1, pair<LL, LL> p2, pair<LL, LL> p3, pair<LL, LL> p4) {
	LL a = cross_product(p1, p2, p3);
	LL b = cross_product(p1, p2, p4);
	LL c = cross_product(p3, p4, p1);
	LL d = cross_product(p3, p4, p2);

	bool boundary = false;
	if (c == 0 && ((p3 <= p1 && p1 <= p4) || (p4 <= p1 && p1 <= p3)))
		boundary = true;
	if (boundary) return 2;

	bool yes = false;
	if ((a >= 0 && b <= 0) || (a <= 0 && b >= 0)) {
		if ((c >= 0 && d <= 0) || (c <= 0 && d >= 0)) {
			yes = true;
		}
	}
	if (a == b && c == d && a == c && a == 0) {
		vector<pair<LL, LL>> l1 = {p1, p2};
		vector<pair<LL, LL>> l2 = {p3, p4};
		sort(l1.begin(), l1.end());
		sort(l2.begin(), l2.end());
		if ((l1[1] >= l2[0] && l1[1] <= l2[1]) || (l2[1] >= l1[0] && l2[1] <= l1[1])) {
			yes = true;
		} else {
			yes = false;
		}
	}
	if (yes) return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	LL n, m;
	cin >> n >> m;
	vector<pair<LL, LL>> v(n);
	for (auto &[x, y] : v) cin >> x >> y;
	while (m--) {
		pair<LL, LL> p, P{0, INT_MAX};
		cin >> p.first >> p.second;
		LL count = 0;
		bool boundary = false;
		for (int i = 0; i < n - 1; i++) {
			LL ix = intersect(p, P, v[i], v[i + 1]);
			count += ix;
			if (ix == 2) {
				boundary = true;
				break;
			}
		}
		LL ix = intersect(p, P, v.back(), v[0]);
		count += ix;
		if (ix == 2) boundary = true;
		if (boundary) {
			cout << "BOUNDARY\n";
		} else if (count % 2) {
			cout << "INSIDE\n";
		} else {
			cout << "OUTSIDE\n";
		}
	}
	return 0;
}
