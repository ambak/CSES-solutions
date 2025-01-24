#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9 + 7;
LL dp[505][505];
LL triangle[505][505];
string s;

void pascal_triangle(int n) {
	for (int i = 0; i <= n; i++) {
		triangle[i][0] = 1;
		triangle[i][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			triangle[i][j] = (triangle[i - 1][j - 1] + triangle[i - 1][j]) % MOD;
		}
	}
}

LL f(int i, int j) {
	if (j + 1 == i) return 1;
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	if ((j - i) % 2 == 0) {
		dp[i][j] = 0;
		return 0;
	}
	LL res = 0;
	for (int k = i + 1; k <= j; k++) {
		if (s[i] == s[k]) {
			res = res + ((f(i + 1, k - 1) * f(k + 1, j)) % MOD) * triangle[(j - i + 1) / 2][(j - k) / 2];
			res %= MOD;
		}
	}
	dp[i][j] = res;
	return dp[i][j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> s;
	int n = int(s.size());
	pascal_triangle(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = -1;
		}
	}
	cout << f(0, n - 1) << "\n";
	return 0;
}
