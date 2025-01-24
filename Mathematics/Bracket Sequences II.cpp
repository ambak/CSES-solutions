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
	string s;
	cin >> s;
	bool wrong = false;
	int open = 0;
	int close = 0;
	for (auto c : s) {
		if (c == '(') {
			open++;
		} else {
			close++;
		}
		if (open < close) {
			wrong = true;
		}
	}
	if (n % 2 || wrong || open > n / 2) {
		cout << "0\n";
		return 0;
	}
	if (open == n / 2) {
		cout << "1\n";
		return 0;
	}
	LL res = bc(n - open - close, n / 2 - open);
	LL res2 = bc(n - open - close, n / 2 - open - 1);

	cout << ((res - res2) % MOD + MOD) % MOD << "\n";
	return 0;
}
