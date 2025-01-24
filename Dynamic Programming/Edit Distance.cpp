#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int dp[5009][5009];

int main() {
	ios_base::sync_with_stdio(false);
	string a, b;
	cin >> a >> b;
	a = ' ' + a;
	b = ' ' + b;
	for (unsigned i = 0; i <= a.size(); i++) {
		dp[i][0] = i;
	}
	for (unsigned j = 0; j <= b.size(); j++) {
		dp[0][j] = j;
	}
	for (unsigned i = 1; i <= a.size(); i++) {
		for (unsigned j = 1; j <= b.size(); j++) {
			if (a[i] == b[j]) {
				dp[i][j] = dp[i - 1][j - 1];
			} else {
				dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
			}
		}
	}
	cout << dp[a.size()][b.size()] << "\n";
	return 0;
}
