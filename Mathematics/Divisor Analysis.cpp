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
	int n;
	cin >> n;
	LL number = 1;
	LL sum = 0;
	LL product = 1;
	LL sB = 0;
	for (int i = 0; i < n; i++) {
		LL a, b;
		cin >> a >> b;
		number = (number * (b + 1)) % MOD;
		LL s = modmult(a, modmult((exp(a, b) - 1), inverse(a - 1)));
		sum = (sum + sum * s + s) % MOD;

		LL A = ((b + 1) * b / 2) % (MOD - 1);

		LL e = exp(a, A);
		product = modmult(modmult(product, e), modmult(exp(product, b), exp(e, sB)));

		sB = (sB + b + ((sB * b) % (MOD - 1))) % (MOD - 1);
	}
	cout << number << " " << sum + 1 << " " << product << "\n";
	return 0;
}
