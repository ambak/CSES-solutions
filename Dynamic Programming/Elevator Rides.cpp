#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int w[21];
LL dp[1 << 20][2];

int main() {
	ios_base::sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}
	for (int i = 1; i < (1 << n); i++) {
		dp[i][0] = INT_MAX;
		dp[i][1] = INT_MAX;
	}
	dp[0][1] = x;
	for (int i = 1; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				LL tmp[2];
				int id = i ^ (1 << j);
				if (dp[id][1] + w[j] <= x) {
					tmp[0] = dp[id][0];
					tmp[1] = dp[id][1] + w[j];
				} else {
					tmp[0] = dp[id][0] + 1;
					tmp[1] = w[j];
				}

				if (tmp[0] < dp[i][0] || (tmp[0] == dp[i][0] && tmp[1] < dp[i][1])) {
					dp[i][0] = tmp[0];
					dp[i][1] = tmp[1];
				}
			}
		}
	}
	cout << dp[(1 << n) - 1][0] << "\n";
	return 0;
}
