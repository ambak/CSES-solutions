#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL res[10009];
int main() {
	ios_base::sync_with_stdio(false);
	LL t;
	cin >> t;
	for (LL i = 1; i <= t; i++) {
		for (LL j = 1; j <= i; j++) {
			res[i] += i * i * (i - j) + i * (i - 1) / 2;
			if (i - j > 1) {
				res[i] -= (i - 2) * 2 + (i - 1) * 2;
			}
			if (i - j == 1) {
				res[i] -= (i - 2) * 2;
			}
		}
		cout << res[i] << "\n";
	}
	return 0;
}
