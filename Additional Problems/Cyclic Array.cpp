#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL d[1000009][20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	LL n, k;
	cin >> n >> k;
	vector<LL> v(n);
	for (auto &x : v) cin >> x;
	v.insert(v.end(), v.begin(), v.end());
	int res = 3 * n;
	for (int j = 0; j < 20; j++) {
		for (int i = 0; i <= 2 * n; i++) {
			d[i][j] = 2 * n;
		}
	}
	LL s = v[0];
	for (int i = 0, j = 1; i < 2 * n && j < 2 * n;) {
		if (s == k) {
			d[i][0] = j;
			s -= v[i];
			s += v[j];
			i++;
			j++;
		} else if (s > k) {
			d[i][0] = j - 1;
			s -= v[i];
			i++;
		} else {
			s += v[j];
			j++;
		}
	}
	for (int j = 1; j < 20; j++) {
		for (int i = 0; i < 2 * n; i++) {
			d[i][j] = d[d[i][j - 1]][j - 1];
		}
	}
	for (int i = 0; i < n; i++) {
		int x = i;
		int ans = 0;
		for (int j = 19; j >= 0; j--) {
			if (d[x][j] - i < n) {
				x = d[x][j];
				ans += 1 << j;
			}
		}
		res = min(res, ans + 1);
	}
	cout << res << "\n";
	return 0;
}
