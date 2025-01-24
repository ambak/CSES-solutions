#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9 + 7;
LL C[5005][5005];
LL dp[29][5005];
LL cnt[29];

int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	LL n = s.size();
	for (auto c : s) {
		cnt[c - 'a']++;
	}
	vector<int> v;
	v.push_back(0);
	for (int i = 0; i < 26; i++) {
		if (cnt[i]) {
			v.push_back(cnt[i]);
		}
	}
	C[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= n; j++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	}
	dp[0][0] = 1;
	int start = 0;
	for (int i = 1; i < int(v.size()); i++) {
		for (int j = 0; j <= start; j++) {
			for (int k = 1; k <= v[i]; k++) {
				dp[i][j + k] += dp[i - 1][j] * C[v[i] - 1][k - 1] % MOD * C[k + j][k];
				dp[i][j + k] %= MOD;
			}
		}
		start += v[i];
	}

	LL res = 0;
	for (int i = 0; i <= n; i++) {
		if ((i + n) % 2 == 0) {
			res += dp[v.size() - 1][i];
		} else {
			res -= dp[v.size() - 1][i];
		}
		res = (res + MOD) % MOD;
	}
	cout << (res + MOD) % MOD << "\n";
	return 0;
}
