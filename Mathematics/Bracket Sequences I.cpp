#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9 + 7;

LL xGCD(LL a, LL b, LL &x, LL &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	LL x1, y1, gcd = xGCD(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return gcd;
}

LL modfact(LL n) {
	LL result = 1;
	while (n > 1) {
		result = result * n % MOD;
		n -= 1;
	}
	return result;
}

LL modmult(LL a, LL b) {
	return a * b % MOD;
}

LL inverse(LL a) {
	LL x, y;
	xGCD(a, MOD, x, y);
	return (x + MOD) % MOD;
}

LL bc(LL n, LL k) {
	return modmult(modmult(modfact(n), inverse(modfact(k))), inverse(modfact(n - k)));
}

int main() {
	ios_base::sync_with_stdio(false);
	LL n;
	cin >> n;
	if (n % 2) {
		cout << "0\n";
		return 0;
	}
	n /= 2;
	LL res = bc(2 * n, n);
	res = modmult(res, inverse(n + 1));
	cout << res << "\n";
	return 0;
}
