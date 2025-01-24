#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		LL x, y;
		cin >> x >> y;
		LL res = 0;
		if (x > y) {
			res = (x - 1) * (x - 1);
			if (x % 2 == 0) {
				res += x;
				res += x - y;
			} else {
				res += y;
			}
		} else {
			res = (y - 1) * (y - 1);
			if (y % 2 == 1) {
				res += y;
				res += y - x;
			} else {
				res += x;
			}
		}
		cout << res << "\n";
	}
	return 0;
}
