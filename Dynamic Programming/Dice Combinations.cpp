#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9L + 7;
LL dp[7];

int main() {
	ios_base::sync_with_stdio(false);
	LL n;
	cin >> n;
	LL res = 1;
	if (n == 1) {
		cout << "1\n";
		return 0;
	}
	dp[1] = 1;
	for (int i = 1; i < n; i++) {
		LL tmp = res;
		for (int j = 5; j > 0; j--) {
			res = (res + dp[j]) % MOD;
			dp[j + 1] = dp[j];
		}
		dp[1] = tmp;
	}
	cout << res << "\n";
	return 0;
}
