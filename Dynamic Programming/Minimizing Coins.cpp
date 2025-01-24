#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int dp[1000003];

int main() {
	ios_base::sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= x; i++) {
		dp[i] = 1000003;
	}
	for (int i = 1; i <= n; i++) {
		int c;
		cin >> c;
		for (int j = 0; j <= x; j++) {
			if (dp[j] != 1000003 && j + c <= x) {
				dp[j + c] = min(dp[j + c], dp[j] + 1);
			}
		}
	}
	if (dp[x] == 1000003) {
		cout << "-1\n";
	} else {
		cout << dp[x] << "\n";
	}
	return 0;
}
