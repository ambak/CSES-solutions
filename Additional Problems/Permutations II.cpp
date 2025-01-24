#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9 + 7;
LL dp[1005];
LL n;

void Hertzsprung_problem() {
	dp[1] = 1;
	dp[4] = 2;
	for (LL i = 5; i <= n; i++) {
		dp[i] = (dp[i - 1] * (i + 1)) % MOD - (dp[i - 2] * (i - 2)) % MOD - (dp[i - 3] * (i - 5)) % MOD + (dp[i - 4] * (i - 3)) % MOD;
		dp[i] = (dp[i] + 2 * MOD) % MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	Hertzsprung_problem();
	cout << dp[n] << "\n";
	return 0;
}
