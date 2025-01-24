#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL C(int i, int j, vector<LL> &Ltab, vector<LL> &Rtab, vector<LL> &sums) {
	LL res = 0;
	if (i + 1 >= j) return 0;
	int n = sums.size();
	int mid = (j + i) / 2;
	res += (Rtab[mid] - Rtab[i]);
	res -= (sums[mid] - sums[i]) * (i + 1);
	res += (Ltab[mid + 1] - Ltab[j]);
	res -= (sums[j - 1] - sums[mid]) * (n - j);
	return res;
}

void divide(int l, int r, int optl, int optr, vector<LL> &dp_beafore, vector<LL> &dp_curr, vector<LL> &Ltab, vector<LL> &Rtab, vector<LL> &sums) {
	if (l > r) return;
	pair<LL, int> best = {LONG_LONG_MAX, -1};
	int mid = (l + r) / 2;
	for (int i = optl; i <= min(mid, optr); i++) {
		best = min(best, {(i > 0 ? dp_beafore[i] : 0) + C(i, mid, Ltab, Rtab, sums), i});
	}
	dp_curr[mid] = best.first;
	divide(l, mid - 1, optl, best.second, dp_beafore, dp_curr, Ltab, Rtab, sums);
	divide(mid + 1, r, best.second, optr, dp_beafore, dp_curr, Ltab, Rtab, sums);
}

LL dp_DaCopt(int n, int k, vector<LL> &Ltab, vector<LL> &Rtab, vector<LL> &sums) {
	vector<LL> dp_beafore(n), dp_curr(n);
	for (int i = 0; i < n - 1; i++) {
		dp_beafore[i + 1] += Ltab[0] - Ltab[i + 1];
		dp_beafore[i + 1] -= sums[i] * (n - i - 1);
	}
	for (int i = 1; i < k; i++) {
		divide(0, n - 1, 0, n - 1, dp_beafore, dp_curr, Ltab, Rtab, sums);
		dp_beafore = dp_curr;
	}
	LL res = LONG_LONG_MAX;
	for (int i = 0; i < n; i++) {
		LL rest = (Rtab[n - 1] - Rtab[i]);
		rest -= (sums[n - 1] - sums[i]) * (i + 1);
		res = min(res, dp_curr[i] + rest);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<LL> v(n);
	vector<LL> Ltab(n);
	vector<LL> Rtab(n);
	vector<LL> sums(n);
	for (auto &x : v) cin >> x;
	for (int i = 0; i < n; i++) {
		sums[i] = (i ? sums[i - 1] : 0) + v[i];
		Rtab[i] = (i ? Rtab[i - 1] : 0) + v[i] * (i + 1);
	}
	for (int i = n - 1; i >= 0; i--) {
		Ltab[i] = (i != n - 1 ? Ltab[i + 1] : 0) + v[i] * (n - i);
	}
	if (k == 1) {
		LL ans = LONG_LONG_MAX;
		for (int i = 0; i < n; i++) {
			LL res = (Rtab[n - 1] - Rtab[i]);
			res -= (sums[n - 1] - sums[i]) * (i + 1);
			res += (Ltab[0] - Ltab[i]);
			res -= (i > 0 ? sums[i - 1] : 0) * (n - i);
			ans = min(ans, res);
		}
		cout << ans << "\n";
	} else {
		cout << dp_DaCopt(n, k, Ltab, Rtab, sums) << "\n";
	}
	return 0;
}
