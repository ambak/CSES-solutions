#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9 + 7;
const LL X = 2797;
LL x[200005];
const int M = 1 << 20;

LL t1[2 * M];
LL t2[2 * M];

void init() {
	x[0] = 1;
	for (int i = 1; i < 200005; i++) {
		x[i] = (x[i - 1] * X) % MOD;
	}
}

void update_forward(int pos, LL val) {
	pos += M;
	t1[pos] = val;
	pos /= 2;
	while (pos > 0) {
		t1[pos] = (t1[pos * 2] + t1[pos * 2 + 1]) % MOD;
		pos /= 2;
	}
}

LL query_forward(int a, int b) {
	a += M;
	b += M;
	LL res = t1[a];
	if (a != b) res = (res + t1[b]) % MOD;
	while (a / 2 != b / 2) {
		if (a % 2 == 0) res = (res + t1[a + 1]) % MOD;
		if (b % 2 == 1) res = (res + t1[b - 1]) % MOD;
		a /= 2;
		b /= 2;
	}
	return res;
}

void update_backward(int pos, LL val) {
	pos += M;
	t2[pos] = val;
	pos /= 2;
	while (pos > 0) {
		t2[pos] = (t2[pos * 2] + t2[pos * 2 + 1]) % MOD;
		pos /= 2;
	}
}

LL query_backward(int a, int b) {
	a += M;
	b += M;
	LL res = t2[a];
	if (a != b) res = (res + t2[b]) % MOD;
	while (a / 2 != b / 2) {
		if (a % 2 == 0) res = (res + t2[a + 1]) % MOD;
		if (b % 2 == 1) res = (res + t2[b - 1]) % MOD;
		a /= 2;
		b /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init();
	int n, m;
	string s;
	cin >> n >> m >> s;
	for (int i = 0; i < n; i++) {
		update_forward(i, (s[i] * x[i]) % MOD);
		update_backward(i, (s[i] * x[n - i - 1]) % MOD);
	}
	while (m--) {
		int q;
		cin >> q;
		if (q == 1) {
			int k;
			char c;
			cin >> k >> c;
			k--;
			update_forward(k, (c * x[k]) % MOD);
			update_backward(k, (c * x[n - k - 1]) % MOD);
		}
		if (q == 2) {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			LL r1 = query_forward(a, b);
			LL r2 = query_backward(a, b);
			r1 = (r1 * (((b - a + 1) * x[n - a]) % MOD)) % MOD;
			r2 = (r2 * (((b - a + 1) * x[b + 1]) % MOD)) % MOD;
			if (r1 == r2) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
	return 0;
}
