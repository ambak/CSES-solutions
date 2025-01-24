#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, x;
	cin >> n >> x;
	vector<tuple<LL, LL, LL>> d(n);
	for (auto &t : d) cin >> get<0>(t);
	for (auto &t : d) cin >> get<1>(t);
	for (auto &t : d) cin >> get<2>(t);
	vector<pair<LL, LL>> v;
	for (int i = 0; i < n; i++) {
		LL h, s, k;
		h = get<0>(d[i]);
		s = get<1>(d[i]);
		k = get<2>(d[i]);
		LL z = 1;
		while (k) {
			if (k >= z) {
				v.push_back({h * z, s * z});
				k -= z;
				z <<= 1;
			} else {
				v.push_back({h * k, s * k});
				k = 0;
			}
		}
	}
	vector<LL> dp(x + 1, -1);
	dp[0] = 0;
	for (auto [h, s] : v) {
		for (int i = x; i >= 0; i--) {
			if (dp[i] != -1 && i + h <= x) {
				dp[i + h] = max(dp[i + h], dp[i] + s);
			}
		}
	}
	LL res = 0;
	for (auto z : dp) {
		if (z != -1) {
			res = max(res, z);
		}
	}
	cout << res << "\n";
	return 0;
}
