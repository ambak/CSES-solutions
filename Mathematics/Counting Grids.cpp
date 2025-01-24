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

LL modmult(LL a, LL b) {
	return a * b % MOD;
}

LL inverse(LL a) {
	LL x, y;
	xGCD(a, MOD, x, y);
	return (x + MOD) % MOD;
}

LL exp(LL a, LL b) {
	LL res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % MOD;
		}
		b >>= 1;
		a = (a * a) % MOD;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	LL n;
	cin >> n;
	LL res = 0;
	n = n * n;
	res += exp(2, n);
	res += exp(2, n / 4 + n % 2);
	res += exp(2, n / 2 + n % 2);
	res += exp(2, n / 4 + n % 2);
	res %= MOD;
	res *= inverse(4);
	res %= MOD;
	cout << res << "\n";
	return 0;
}
