#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 1e9L + 7;
char d[1003][1003];
int dp[1003][1003];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	dp[0][0] = 1;
	if (d[0][0] == '*') {
		dp[0][0] = 0;
	}
	for (int i = 1; i < n; i++) {
		if (d[0][i] == '*') {
			dp[0][i] = 0;
		} else {
			dp[0][i] = dp[0][i - 1];
		}
		if (d[i][0] == '*') {
			dp[i][0] = 0;
		} else {
			dp[i][0] = dp[i - 1][0];
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (d[i][j] == '*') {
				dp[i][j] = 0;
			} else {
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
			}
		}
	}
	cout << dp[n - 1][n - 1] << "\n";
	return 0;
}
