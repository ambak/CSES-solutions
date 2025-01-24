#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int M = 1 << 19;
LL t[M * 2 + 5];

void update(int a, LL v) {
	a += M;
	t[a] = v;
	a /= 2;
	while (a != 0) {
		int l = 2 * a;
		int r = 2 * a + 1;
		t[a] = max(t[l], t[r]);
		a /= 2;
	}
}

LL query(int a, int b) {
	a += M;
	b += M;
	LL res = max(t[a], t[b]);
	while (a / 2 != b / 2) {
		if ((a & 1) == 0) res = max(res, t[a + 1]);
		if ((b & 1) == 1) res = max(res, t[b - 1]);
		a /= 2;
		b /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		LL h;
		cin >> h;
		update(i, h);
	}
	while (m--) {
		int g;
		cin >> g;
		if (query(1, n) < g) {
			cout << "0 ";
			continue;
		}
		int l = 1;
		int r = n;
		while (l != r) {
			int s = (l + r) / 2;
			if (query(l, s) >= g) {
				r = s;
			} else {
				l = s + 1;
			}
		}
		cout << l << " ";
		update(l, query(l, l) - g);
	}

	return 0;
}
