#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9 + 7;
LL n, x;
LL dp[101][52][10201];	// i - coder id; j - unfinished teams; k - penalty

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> x;
	vector<int> t(n + 1);
	for (int i = 1; i <= n; i++) cin >> t[i];
	sort(t.begin(), t.end());
	dp[0][0][5000] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 50; j++) {
			for (int k = 0; k <= 10000; k++) {
				dp[i][j][k] = dp[i - 1][j][k];
				dp[i][j][k] = (dp[i][j][k] + j * dp[i - 1][j][k]) % MOD;
				if (j > 0) dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][k + t[i]]) % MOD;
				if (k - t[i] >= 0) dp[i][j][k] = (dp[i][j][k] + (j + 1) * dp[i - 1][j + 1][k - t[i]]) % MOD;
			}
		}
	}
	LL res = 0;
	for (int k = 5000; k <= 5000 + x; k++) {
		res = (res + dp[n][0][k]) % MOD;
	}
	cout << res << "\n";
	return 0;
}
