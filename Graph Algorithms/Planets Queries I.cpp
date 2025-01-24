#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL odl[32][200009];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> odl[1][i];
	}
	for (int j = 2; j < 32; j++) {
		for (int i = 1; i <= n; i++) {
			odl[j][i] = odl[j - 1][odl[j - 1][i]];
		}
	}
	for (int i = 0; i < m; i++) {
		int x, k;
		cin >> x >> k;
		int j = 1;
		while (k) {
			if (k & 1) {
				x = odl[j][x];
			}
			j++;
			k >>= 1;
		}
		cout << x << "\n";
	}

	return 0;
}
