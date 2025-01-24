#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int dp[2][100009];
int h[100009];
int s[100009];

int main() {
	ios_base::sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = h[i]; j <= x; j++) {
			dp[1][j] = max(dp[0][j], dp[0][j - h[i]] + s[i]);
		}
		for (int j = h[i]; j <= x; j++) {
			dp[0][j] = dp[1][j];
		}
	}
	cout << dp[1][x] << "\n";
	return 0;
}
