#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dd[5003];
LL d[5003];
LL dp[5003][5003];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	LL sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
		sum += d[i];
		dd[i] = sum;
		dp[i][i] = d[i];
	}

	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 1; j <= n; j++) {
			dp[i][j] = dd[j] - dd[i - 1] - min(dp[i + 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[1][n] << "\n";
	return 0;
}
