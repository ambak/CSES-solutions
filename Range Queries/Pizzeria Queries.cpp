#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int M = 1 << 19;
pair<LL, LL> t[M * 2 + 5];

void update(int a, LL v) {
	a += M;
	t[a] = {v, v};
	a /= 2;
	int sh = 0;
	while (a != 0) {
		int l = 2 * a;
		int r = 2 * a + 1;
		t[a].first = min(t[l].first, t[r].first + (1 << sh));
		t[a].second = min(t[r].second, t[l].second + (1 << sh));
		a /= 2;
		sh++;
	}
}

LL query(int a) {
	a += M;
	LL res = t[a].first;
	int sh = 0;
	int lsh = 1, rsh = 1;
	while (a != 1) {
		if ((a & 1) == 0) {
			res = min(res, t[a + 1].first + lsh);
			lsh += 1 << sh;
		} else {
			res = min(res, t[a - 1].second + rsh);
			rsh += 1 << sh;
		}
		sh++;
		a /= 2;
	}
	return res;
}

int main() {
	int n, q;
	ios_base::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 0; i <= M * 2; i++) {
		t[i] = {INT_MAX, INT_MAX};
	}
	for (int i = 1; i <= n; i++) {
		LL x;
		cin >> x;
		update(i, x);
	}
	while (q--) {
		LL a, b, c;
		cin >> c >> a;
		if (c == 1) {
			cin >> b;
			update(a, b);
		} else {
			cout << query(a) << "\n";
		}
	}
	return 0;
}
