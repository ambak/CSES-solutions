#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9 + 7;
LL fact[2000009];
LL dp[2000009];

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

LL bc(LL n, LL k) {
	return modmult(modmult(fact[n], inverse(fact[k])), inverse(fact[n - k]));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	LL n, m;
	cin >> n >> m;
	vector<pair<LL, LL>> v(m + 1);
	for (int i = 0; i < m; i++) {
		cin >> v[i].first >> v[i].second;
	}
	v[m].first = n;
	v[m].second = n;
	sort(v.begin(), v.end());
	if ((v[0].first == 1 && v[0].second == 1) || (v[m - 1].first == n && v[m - 1].second == n)) {
		cout << "0\n";
		return 0;
	}
	fact[0] = 1;
	for (int i = 1; i <= 2 * n; i++) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	for (int i = 0; i <= m; i++) {
		dp[i] = bc(v[i].first + v[i].second - 2, v[i].first - 1);
	}
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j < i; j++) {
			LL xa = v[i].first;
			LL ya = v[i].second;
			LL xb = v[j].first;
			LL yb = v[j].second;
			if (xa >= xb && ya >= yb) {
				dp[i] -= (dp[j] * bc(xa - xb + ya - yb, xa - xb)) % MOD;
				dp[i] = (dp[i] + MOD) % MOD;
			}
		}
	}
	cout << dp[m] << "\n";
	return 0;
}
