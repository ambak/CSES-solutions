#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int M = 1 << 19;
// left, max, right, sum
tuple<LL, LL, LL, LL> t[M * 2 + 5];

void update(int a, LL v) {
	a += M;
	t[a] = {v, v, v, v};
	a /= 2;
	while (a != 0) {
		int l = 2 * a;
		int r = 2 * a + 1;
		auto [ll, lm, lr, ls] = t[l];
		auto [rl, rm, rr, rs] = t[r];
		LL L = max(ll, ls + rl);
		LL MM = max(max(lm, rm), lr + rl);
		LL R = max(rr, rs + lr);
		LL S = ls + rs;
		t[a] = {L, MM, R, S};
		a /= 2;
	}
}

int main() {
	int n, q;
	ios_base::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		LL x;
		cin >> x;
		update(i, x);
	}
	while (q--) {
		LL k, x;
		cin >> k >> x;
		update(k, x);
		cout << get<1>(t[1]) << "\n";
	}
	return 0;
}
