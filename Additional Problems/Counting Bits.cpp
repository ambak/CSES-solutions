#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	LL n, res = 0;
	cin >> n;
	for (LL i = 1; i < 60; i++) {
		res += (n + 1) / (1LL << i) * (1LL << (i - 1));
		res += max(0LL, ((n + 1) % (1LL << i)) - (1LL << (i - 1)));
	}
	cout << res << "\n";
	return 0;
}
