#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL d[200009];

bool check(LL x, LL n, LL k) {
	LL sum = 0;
	LL part = 1;
	for (LL i = 1; i <= n; i++) {
		if (d[i] > x) {
			return false;
		}
		if (d[i] + sum <= x) {
			sum += d[i];
		} else {
			part++;
			sum = d[i];
		}
	}
	if (part <= k) {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	LL n, k;
	cin >> n >> k;
	for (LL i = 1; i <= n; i++) {
		cin >> d[i];
	}
	LL b = 0, e = 2e14L + 5;
	while (true) {
		LL s = (b + e) / 2;
		bool ok = check(s, n, k);
		if (ok && !check(s - 1, n, k)) {
			cout << s << "\n";
			break;
		}
		if (ok) {
			e = s - 1;
		} else {
			b = s + 1;
		}
	}

	return 0;
}
