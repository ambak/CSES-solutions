#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL C(int i, int j, vector<LL> &sums) {
	LL res = sums[j];
	if (i != 0) res -= sums[i - 1];
	return res * res;
}

void divide(int l, int r, int optl, int optr, vector<LL> &dp_beafore, vector<LL> &dp_curr, vector<LL> &sums) {
	if (l > r) return;

	pair<LL, int> best = {LONG_LONG_MAX, -1};
	int mid = (l + r) / 2;
	for (int i = optl; i <= min(mid, optr); i++) {
		best = min(best, {(i > 0 ? dp_beafore[i - 1] : 0) + C(i, mid, sums), i});
	}
	dp_curr[mid] = best.first;
	divide(l, mid - 1, optl, best.second, dp_beafore, dp_curr, sums);
	divide(mid + 1, r, best.second, optr, dp_beafore, dp_curr, sums);
}

LL dp_DaCopt(int n, int k, vector<LL> &sums) {
	vector<LL> dp_beafore(n), dp_curr(n);
	for (int i = 0; i < n; i++) {
		dp_beafore[i] = C(0, i, sums);
	}
	for (int i = 1; i < k; i++) {
		divide(0, n - 1, 0, n - 1, dp_beafore, dp_curr, sums);
		dp_beafore = dp_curr;
	}
	return dp_beafore[n - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<LL> v(n);
	vector<LL> sums(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (i == 0) {
			sums[i] = v[i];
		} else {
			sums[i] = v[i] + sums[i - 1];
		}
	}
	cout << dp_DaCopt(n, k, sums) << "\n";
	return 0;
}
