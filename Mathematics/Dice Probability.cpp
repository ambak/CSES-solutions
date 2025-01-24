#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

double dp[105][605];

int main() {
	ios_base::sync_with_stdio(false);
	int n, a, b;
	cin >> n >> a >> b;

	dp[0][0] = 1.;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6 * n; j++) {
			double X = 0.;
			for (int k = max(j - 6, 0); k < j; k++) {
				X += dp[i - 1][k];
			}
			dp[i][j] = X / 6;
		}
	}

	double res = 0.;
	for (int i = a; i <= b; i++) {
		res += dp[n][i];
	}
	cout << fixed << setprecision(6) << res << "\n";
	return 0;
}
