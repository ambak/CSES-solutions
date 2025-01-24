#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 1e9L + 7;
int dp[103][1000003];

int main() {
	ios_base::sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}
	for (int i = 1; i <= n; i++) {
		int c;
		cin >> c;
		for (int j = 0; j <= x; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - c >= 0) {
				dp[i][j] = (dp[i][j] + dp[i][j - c]) % MOD;
			}
		}
	}
	cout << dp[n][x] << "\n";
	return 0;
}
