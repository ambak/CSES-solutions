#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	LL n;
	cin >> n;
	LL res = 1;
	LL x = 2;
	while (n) {
		if (n & 1) {
			res = (res * x) % MOD;
		}
		n /= 2;
		x = (x * x) % MOD;
	}
	cout << res << "\n";
	return 0;
}
