#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 1e9L + 7;
int dp[1000003];
int c[103];

int main() {
	ios_base::sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	for (int j = 0; j <= x; j++) {
		for (int i = 1; i <= n; i++) {
			if (j - c[i] >= 0) {
				dp[j] = (dp[j] + dp[j - c[i]]) % MOD;
			}
		}
	}
	cout << dp[x] << "\n";
	return 0;
}
