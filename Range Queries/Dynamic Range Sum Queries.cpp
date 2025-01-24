#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL t[200009];

void update(int x, LL v) {
	for (; x < 200009; x += x & -x) {
		t[x] += v;
	}
}

LL query(int x) {
	LL res = 0;
	for (; x > 0; x -= x & -x) {
		res += t[x];
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
		update(i, x);
	}
	while (m--) {
		LL q, a, b;
		cin >> q >> a >> b;
		if (q == 1) {
			LL prev = query(a) - query(a - 1);
			update(a, b - prev);
		} else {
			cout << query(b) - query(a - 1) << "\n";
		}
	}

	return 0;
}
