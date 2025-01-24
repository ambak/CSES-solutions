#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9 + 7;

LL fact[1000009];

void init() {
	fact[0] = 1;
	for (int i = 1; i < 1000009; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}
}

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

inline LL modmult(const LL a, const LL b) {
	return a * b % MOD;
}

LL inverse(LL a) {
	LL x, y;
	xGCD(a, MOD, x, y);
	return (x + MOD) % MOD;
}

LL bc(LL n, LL k) {
	return modmult(modmult(fact[n], inverse(fact[k])), inverse(fact[n - k]));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	int n;
	cin >> n;
	while (n--) {
		LL a, b;
		cin >> a >> b;
		if (b == 0) {
			cout << a << "\n";
		} else {
			cout << bc(a, b) << "\n";
		}
	}
	return 0;
}
