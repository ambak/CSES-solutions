#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXSUM = 100000;
int d[109];
int dp[MAXSUM + 2];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = MAXSUM; j >= d[i]; j--) {
			if (dp[j - d[i]]) {
				dp[j] = 1;
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= MAXSUM; i++) {
		res += dp[i];
	}
	cout << res << "\n";
	for (int i = 1; i <= MAXSUM; i++) {
		if (dp[i]) {
			cout << i << " ";
		}
	}
	cout << "\n";
	return 0;
}
