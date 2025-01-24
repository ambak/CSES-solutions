#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9 + 7;
LL D[1000009];

int main() {
	ios_base::sync_with_stdio(false);
	LL n;
	cin >> n;
	D[0] = 1;
	for (int i = 2; i <= n; i++) {
		D[i] = ((i - 1) * (D[i - 1] + D[i - 2])) % MOD;
	}
	cout << D[n] << "\n";
	return 0;
}
