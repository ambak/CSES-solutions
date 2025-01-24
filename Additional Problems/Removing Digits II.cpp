#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dp[10][20][10];
LL dp2[10][20][10];

void init() {
	for (int j = 0; j < 20; j++) {
		for (int i = 0; i < 10; i++) {
			for (int k = 0; k < 10; k++) {
				if (i + j + k == 0) continue;
				if (i + j == 0) {
					dp[i][j][k] = 1;
					continue;
				}
				if (j == 0) {
					if (i > k) {
						dp[i][j][k] = 1;
						dp2[i][j][k] = 10 + k - i;
					} else {
						dp[i][j][k] = 2;
						dp2[i][j][k] = 10 - i;
					}
					continue;
				}
				int z = k;
				for (int x = 9; x >= 0; x--) {
					dp[i][j][k] += dp[max(x, i)][j - 1][z];
					z = dp2[max(x, i)][j - 1][z];
				}
				dp2[i][j][k] = z;
			}
		}
	}
}

LL nines(LL n) {
	LL res = 0;
	n /= 10;
	while (n) {
		if (n % 10 == 9)
			res++;
		else
			break;
		n /= 10;
	}
	return res;
}

LL i_max(LL n, int j) {
	for (int i = 0; i <= j; i++) {
		n /= 10;
	}
	LL res = 0;
	while (n) {
		res = max(res, n % 10);
		n /= 10;
	}
	return res;
}

LL solve(LL n) {
	LL res = 0;
	while (n) {
		int k = n % 10;
		int j = nines(n);
		int i = i_max(n, j);
		res += dp[i][j][k];
		LL minus = 1;
		for (int m = 0; m <= j; m++) {
			minus *= 10;
		}
		n -= minus;
		n -= n % 10;
		n += dp2[i][j][k];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	init();
	LL n;
	cin >> n;
	cout << solve(n) << "\n";
	return 0;
}
