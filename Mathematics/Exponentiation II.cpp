#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL exp(LL a, LL b, const int MOD) {
	LL res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % MOD;
		}
		b >>= 1;
		a = (a * a) % MOD;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int MOD = 1e9 + 7;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << exp(a, exp(b, c, MOD - 1), MOD) << "\n";
	}
	return 0;
}
