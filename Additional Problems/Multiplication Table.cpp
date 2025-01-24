#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	LL n;
	cin >> n;
	const LL sr = n * n / 2 + 1;
	LL b = 1, e = 2e11;
	LL res = 0;
	while (b <= e) {
		LL s = (b + e) / 2;
		LL cnt = 0;
		LL cnte = 0;
		for (LL id = 1; id <= n; id++) {
			if (id * n < s - 1) {
				cnt += n;
			} else {
				cnt += (s - 1) / id;
			}
			if (id * n <= s) {
				cnte += n;
			} else {
				cnte += s / id;
			}
		}
		if (cnt < sr && sr <= cnte) {
			bool ok = false;
			for (LL id = 1; id <= n; id++) {
				if (s % id == 0 && s / id <= n) {
					ok = true;
					break;
				}
			}
			if (ok) {
				res = s;
				break;
			}
		}
		if (cnte < sr) {
			b = s + 1;
		}
		if (cnte >= sr) {
			e = s - 1;
		}
	}
	cout << res << "\n";
	return 0;
}
