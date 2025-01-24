#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL p[19];

LL count_ones(LL n, LL mask = 1000000000000000000LL, int size = 18) {
	if (size == 0) {
		if (n > 0) return 1;
		return 0;
	}
	LL x = n / mask;
	if (x > 1) {
		return mask + (x)*p[size] + count_ones(n % mask, mask / 10, size - 1);
	} else if (x == 1) {
		return p[size] + n % mask + 1 + count_ones(n % mask, mask / 10, size - 1);
	} else if (x == 0) {
		return count_ones(n % mask, mask / 10, size - 1);
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	LL mul = 1;
	for (LL i = 1; i < 19; i++) {
		p[i] = i * mul;
		mul *= 10;
	}
	LL n;
	cin >> n;
	LL l = 0, r = 1000000000000000000LL;
	LL res = 0;
	while (l <= r) {
		LL mid = l / 2 + r / 2 + (l % 2 + r % 2) / 2;
		if (count_ones(mid) <= n) {
			res = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << res << "\n";
	return 0;
}
