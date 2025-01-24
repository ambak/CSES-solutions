#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dp[1003][1 << 10];
const int MOD = 1e9 + 7;

void f(int n, int i, int mask, int next_mask, vector<int> &v) {
	if (i == n) {
		v.push_back(next_mask);
		return;
	}
	if (mask & (1 << i)) {
		f(n, i + 1, mask, next_mask, v);
		return;
	}
	if (i < n - 1 && !(mask & (1 << (i + 1)))) {
		f(n, i + 2, mask, next_mask, v);
	}
	f(n, i + 1, mask, next_mask | (1 << i), v);
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	dp[0][0] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < (1 << n); j++) {
			if (dp[i - 1][j] == 0) continue;
			vector<int> v;
			f(n, 0, j, 0, v);
			for (int x : v) {
				dp[i][x] = (dp[i][x] + dp[i - 1][j]) % MOD;
			}
		}
	}
	cout << dp[m][0] << "\n";
	return 0;
}
