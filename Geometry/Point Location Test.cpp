#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL cross_product(pair<LL, LL> start, pair<LL, LL> a, pair<LL, LL> b) {
	return (a.first - start.first) * (b.second - start.second) - (b.first - start.first) * (a.second - start.second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		pair<LL, LL> a, b, c;
		cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
		LL q = cross_product(a, b, c);
		if (q > 0)
			cout << "LEFT\n";
		else if (q == 0)
			cout << "TOUCH\n";
		else
			cout << "RIGHT\n";
	}
	return 0;
}
