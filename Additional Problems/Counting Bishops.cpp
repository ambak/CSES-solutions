#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9 + 7;
LL dp[1001][1001];

LL fields(LL id) {
	if (id % 2) {
		return id / 4 * 2 + 1;
	}
	return (id - 1) / 4 * 2 + 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	LL n, k;
	cin >> n >> k;
	if (k > 2 * n) {
		cout << "0\n";
		return 0;
	}
	for (int i = 0; i <= 2 * n - 1; i++) {
		dp[i][0] = 1;
	}
	dp[1][1] = 1;
	for (int i = 2; i <= 2 * n - 1; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = dp[i - 2][j] + ((dp[i - 2][j - 1] * (fields(i) - j + 1)) % MOD);
			dp[i][j] %= MOD;
		}
	}
	LL res = 0;
	for (int i = 0; i <= k; i++) {
		res += (dp[2 * n - 1][i] * dp[2 * n - 2][k - i]) % MOD;
		res %= MOD;
	}
	cout << res << "\n";
	return 0;
}
