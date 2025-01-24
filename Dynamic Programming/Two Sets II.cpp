#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9L + 7;
LL dp[125003];

int main() {
	ios_base::sync_with_stdio(false);
	LL n;
	cin >> n;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = (1 + n) * n / 4; j >= i; j--) {
			dp[j] = (dp[j] + dp[j - i]) % MOD;
		}
	}
	if ((1 + n) * n / 2 % 2 == 0) {
		cout << dp[(1 + n) * n / 4] << "\n";
	} else {
		cout << "0\n";
	}
	return 0;
}
