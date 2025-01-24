#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 1e9 + 7;
int n, m;
int t[21][21];
LL dp[1 << 20][22];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		t[a][b]++;
	}
	dp[1][1] = 1;
	for (int i = 1; i < (1 << (n - 1)); i++) {
		int x = (i << 1) + 1;
		for (int j = 1; j <= n; j++) {
			if (x & (1 << j)) {
				for (int k = 0; k < n; k++) {
					if (x & (1 << k) && t[k + 1][j + 1]) {
						dp[x][j + 1] = (dp[x][j + 1] + dp[x - (1 << j)][k + 1]) * t[k + 1][j + 1];
					}
				}
				dp[x][j + 1] %= MOD;
			}
		}
	}
	cout << dp[(1 << n) - 1][n];
	return 0;
}
