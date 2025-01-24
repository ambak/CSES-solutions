#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9 + 7;
LL dp[505][250005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) dp[i][0] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]);
			if (j - i >= 0) dp[i][j] += MOD - dp[i - 1][j - i];
			dp[i][j] %= MOD;
		}
	}
	cout << dp[n][k] << "\n";
	return 0;
}
