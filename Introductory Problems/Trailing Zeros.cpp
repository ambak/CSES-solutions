#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	LL n;
	cin >> n;
	LL res = 0;
	while (n) {
		res += n / 5;
		n /= 5;
	}
	cout << res << "\n";
	return 0;
}
