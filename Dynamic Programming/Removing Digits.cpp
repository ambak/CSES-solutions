#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int M = 1000003;
int dp[M];

int solve(int x) {
	if (dp[x] == M) {
		int tmp = x;
		while (tmp) {
			if (tmp % 10) {
				dp[x] = min(dp[x], solve(x - tmp % 10) + 1);
			}
			tmp /= 10;
		}
	}
	return dp[x];
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = M;
	}
	cout << solve(n) << "\n";
	return 0;
}
