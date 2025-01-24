#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	LL n;
	cin >> n;
	LL res = 0;
	LL sq = sqrt(n);
	for (LL i = 1; i * i <= n; i++) {
		LL x = n / i;
		res = (res + i * x) % MOD;
		LL l = sq + 1;
		LL r = (n / i);
		LL z = 0;
		if (l > r) {
			continue;
		}
		if ((l + r) % 2 == 0) {
			z = ((l + r) / 2) % MOD;
			z = (z * ((r - l + 1) % MOD)) % MOD;
			if (l == r) {
				z = l % MOD;
			}
		} else {
			z = (l + r) % MOD;
			z = (z * (((r - l + 1) / 2) % MOD)) % MOD;
		}

		res = (res + z) % MOD;
	}
	cout << res << "\n";
	return 0;
}
