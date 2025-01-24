#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dp[5005][5005];
int opt[5005][5005];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<LL> v(n);
	vector<LL> sums(n);
	for (auto &x : v) cin >> x;
	for (int i = 0; i < n; i++) {
		sums[i] = (i ? sums[i - 1] : 0) + v[i];
		opt[i][i] = i;
	}
	for (int i = n - 2; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			pair<LL, int> best = {LONG_LONG_MAX, -1};
			for (int k = opt[i][j - 1]; k <= opt[i + 1][j]; k++) {
				best = min(best, {dp[i][k] + dp[k + 1][j], k});
			}
			dp[i][j] = best.first + sums[j] - (i ? sums[i - 1] : 0);
			opt[i][j] = best.second;
		}
	}
	cout << dp[0][n - 1] << "\n";
	return 0;
}
