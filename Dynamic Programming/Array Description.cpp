#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9L + 7;
LL d[100009];
LL dp[100009][103];

int main() {
	ios_base::sync_with_stdio(false);
	LL n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
	}

	if (d[1] == 0) {
		for (int j = 1; j <= m; j++) {
			dp[1][j] = 1;
		}
	} else {
		dp[1][d[1]] = 1;
	}

	for (int i = 2; i <= n; i++) {
		if (d[i] == 0) {
			for (int j = 1; j <= m; j++) {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
			}
		} else {
			dp[i][d[i]] = (dp[i - 1][d[i] - 1] + dp[i - 1][d[i]] + dp[i - 1][d[i] + 1]) % MOD;
		}
	}
	LL res = 0;
	for (int i = 1; i <= m; i++) {
		res = (res + dp[n][i]) % MOD;
	}
	cout << res << "\n";
	return 0;
}
