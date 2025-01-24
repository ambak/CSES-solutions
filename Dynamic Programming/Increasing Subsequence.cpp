#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 200001;
int dp[MAXN + 1];

int main() {
	ios_base::sync_with_stdio(false);
	LL n;
	cin >> n;
	for (int i = 1; i <= MAXN; i++) {
		dp[i] = 1e9 + 7;
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		int b = 1;
		int e = MAXN;
		while (true) {
			int c = (b + e) / 2;
			if (dp[c] >= x && dp[c - 1] < x) {
				dp[c] = x;
				break;
			}
			if (dp[c] > x) {
				e = c - 1;
			} else {
				b = c + 1;
			}
		}
	}
	for (int i = 0; i < n + 2; i++) {
		if (dp[i] == 1e9 + 7) {
			cout << i - 1 << "\n";
			break;
		}
	}
	return 0;
}
