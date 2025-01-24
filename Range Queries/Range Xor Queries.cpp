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
		t[a] = t[l] ^ t[r];
		a /= 2;
	}
}

LL query(int a, int b) {
	a += M;
	b += M;
	LL res = t[a];
	if (a != b) res ^= t[b];
	while (a / 2 != b / 2) {
		if ((a & 1) == 0) res = res ^ t[a + 1];
		if ((b & 1) == 1) res = res ^ t[b - 1];
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
		LL x;
		cin >> x;
		update(i - 1, x);
	}
	while (m--) {
		LL a, b;
		cin >> a >> b;
		cout << query(a - 1, b - 1) << "\n";
	}

	return 0;
}
