#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL cross_product(LL x1, LL y1, LL x2, LL y2, LL x3, LL y3) {
	return (x3 - x1) * (y3 - y2) - (x3 - x2) * (y3 - y1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	LL tt;
	cin >> tt;
	while (tt--) {
		LL x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		LL a = cross_product(x1, y1, x2, y2, x3, y3);
		LL b = cross_product(x1, y1, x2, y2, x4, y4);
		LL c = cross_product(x3, y3, x4, y4, x1, y1);
		LL d = cross_product(x3, y3, x4, y4, x2, y2);
		bool yes = false;
		if ((a >= 0 && b <= 0) || (a <= 0 && b >= 0)) {
			if ((c >= 0 && d <= 0) || (c <= 0 && d >= 0)) {
				yes = true;
			}
		}
		if (a == b && c == d && a == c && a == 0) {
			vector<pair<LL, LL> > l1 = {{x1, y1}, {x2, y2}};
			vector<pair<LL, LL> > l2 = {{x3, y3}, {x4, y4}};
			sort(l1.begin(), l1.end());
			sort(l2.begin(), l2.end());
			if ((l1[1] >= l2[0] && l1[1] <= l2[1]) || (l2[1] >= l1[0] && l2[1] <= l1[1])) {
				yes = true;
			} else {
				yes = false;
			}
		}
		cout << (yes ? "YES" : "NO") << "\n";
	}
	return 0;
}
