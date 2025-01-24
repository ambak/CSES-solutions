#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL odl[505][505];
int n, m, q;

void floyd() {
	for (int j = 1; j <= n; j++)
		for (int i = 1; i <= n; i++)
			for (int k = 1; k <= n; k++)
				if (odl[i][k] > odl[i][j] + odl[j][k] && odl[i][j] != __LONG_LONG_MAX__ && odl[j][k] != __LONG_LONG_MAX__)
					odl[i][k] = odl[i][j] + odl[j][k];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> q;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			odl[i][j] = __LONG_LONG_MAX__;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		if (odl[a][b] > d) {
			odl[a][b] = d;
			odl[b][a] = d;
		}
	}
	floyd();
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		if (a == b) {
			cout << "0\n";
		} else if (odl[a][b] == __LONG_LONG_MAX__) {
			cout << "-1\n";
		} else {
			cout << odl[a][b] << "\n";
		}
	}
	return 0;
}
