#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int dpa[(1 << 20) + 1][21];
int dpb[(1 << 20) + 1][21];
int cnt[(1 << 20) + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) {
		cin >> x;
		cnt[x]++;
	}

	for (int j = 0; j < 20; j++) {
		for (int i = 0; i < (1 << 20); i++) {
			if (j == 0) {
				dpa[i][j] += cnt[i];
				if (i & (1 << j)) dpa[i][j] += cnt[i ^ (1 << j)];
			} else {
				dpa[i][j] += dpa[i][j - 1];
				if (i & (1 << j)) dpa[i][j] += dpa[i ^ (1 << j)][j - 1];
			}
		}
	}

	for (int j = 0; j < 20; j++) {
		for (int i = 0; i < (1 << 20); i++) {
			if (j == 0) {
				dpb[i][j] += cnt[i];
				if ((i & (1 << j)) == 0) dpb[i][j] += cnt[i ^ (1 << j)];
			} else {
				dpb[i][j] += dpb[i][j - 1];
				if ((i & (1 << j)) == 0) dpb[i][j] += dpb[i ^ (1 << j)][j - 1];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int x = (~v[i]) & 0xFFFFF;
		cout << dpa[v[i]][19] << " " << dpb[v[i]][19] << " " << n - dpa[x][19] << "\n";
	}
	return 0;
}
