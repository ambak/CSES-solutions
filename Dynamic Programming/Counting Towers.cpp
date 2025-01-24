#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9L + 7;
LL dp[1000009][2];

int main() {
	ios_base::sync_with_stdio(false);
	int tt;
	cin >> tt;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= 1e6; i++) {
		dp[i][0] = (dp[i - 1][0] * 4 + dp[i - 1][1]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 2) % MOD;
	}

	while (tt--) {
		int n;
		cin >> n;
		cout << (dp[n][0] + dp[n][1]) % MOD << "\n";
	}
	return 0;
}
