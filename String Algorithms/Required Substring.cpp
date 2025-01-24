#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9 + 7;
LL dp[1001][101];
int P[26][101][101];
int p[26][101];

int KMP(string s, int P[]) {
	P[0] = 0;
	int t = P[0];
	for (int i = 1; i < int(s.size()); i++) {
		while (t > 0 && s[t] != s[i]) t = P[t - 1];
		if (s[t] == s[i]) t++;
		P[i] = t;
	}
	return P[s.size() - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;

	for (int k = 0; k < 26; k++) {
		for (int j = 0; j < int(s.size()); j++) {
			p[k][j] = KMP(s + '#' + s.substr(0, j) + char(k + 'A'), P[k][j]);
		}
	}

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < int(s.size()); j++) {
			for (int k = 0; k < 26; k++) {
				dp[i][p[k][j]] += dp[i - 1][j];
				dp[i][p[k][j]] %= MOD;
			}
		}
	}

	LL res = 1;
	for (int i = 0; i < n; i++) res = (res * 26) % MOD;
	for (int i = 0; i < int(s.size()); i++) {
		res = (res - dp[n][i] + MOD) % MOD;
	}
	cout << res << "\n";
	return 0;
}
