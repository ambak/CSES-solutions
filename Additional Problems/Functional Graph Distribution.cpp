#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9 + 7;

LL fact[5009];
LL inv[5009];
LL pown[5009];
LL stirling[5009][5009];

void stirling_first_kind() {
	stirling[1][1] = 1;
	for (int n = 2; n < 5009; n++) {
		for (int k = 1; k <= n; k++) {
			stirling[n][k] = (stirling[n - 1][k - 1] - stirling[n - 1][k] * (n - 1)) % MOD;
		}
	}
}

inline LL modmult(const LL a, const LL b) {
	return a * b % MOD;
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

inline LL inverse(LL a) {
	return exp(a, MOD - 2);
}

LL bc(LL n, LL k) {
	return fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

void init(int n) {
	stirling_first_kind();
	fact[0] = 1;
	for (int i = 1; i < 5009; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	inv[0] = 1;
	for (int i = 1; i < 5009; i++) {
		inv[i] = inverse(fact[i]);
	}
	for (int i = 0; i < 5009; i++) {
		pown[i] = exp(n, i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	LL n;
	cin >> n;
	init(n);
	// https://oeis.org/A060281
	for (int k = 1; k <= n; k++) {
		LL res = 0;
		for (int j = 0; j < n; j++) {
			res = (res + bc(n - 1, j) * modmult(pown[n - 1 - j], abs(stirling[j + 1][k]))) % MOD;
		}
		cout << res << " ";
	}
	return 0;
}