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
	return modmult(fact[n], inverse(modmult(fact[k], fact[n - k])));
}

LL exp(LL a, LL b) {
	if (a == -1) {
		return b % 2 ? -1 : 1;
	}
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
	cin.tie(0);
	cout.tie(0);
	init();
	LL n, k;
	cin >> n >> k;
	LL res = 0;
	// Stirling numbers of the second kind
	// S(n,k) * k!
	for (int i = 0; i < k; i++) {
		res = (res + exp(k - i, n) * bc(k, i) * exp(-1, i)) % MOD;
	}
	cout << res << "\n";
	return 0;
}