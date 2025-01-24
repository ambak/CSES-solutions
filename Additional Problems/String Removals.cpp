#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9 + 7;

LL dp[500009];
int lit[130];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	for (int i = 0; i < 130; i++) lit[i] = -1;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		int c = s[i - 1];
		dp[i] = dp[i - 1] << 1;
		if (lit[c] != -1) {
			dp[i] -= dp[lit[c] - 1];
		}
		lit[c] = i;
		dp[i] += MOD;
		dp[i] %= MOD;
	}
	cout << (dp[n] - 1 + MOD) % MOD << "\n";
	return 0;
}
