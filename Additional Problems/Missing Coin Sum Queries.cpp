#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
typedef long long LL;

const LL M = 1 << 18;

struct segtree {
	LL s[32];
	LL mini[32];
} t[M * 2];

void insert(LL val, int pos) {
	pos += M;
	while (pos > 1) {
		for (int i = 1; i < 31; i++) {
			if (val < (1 << i)) {
				t[pos].s[i] += val;
			}
			if (val >= (1 << (i - 1)) && val < (1 << i)) {
				t[pos].mini[i] = min(val, t[pos].mini[i] == 0 ? val : t[pos].mini[i]);
			}
		}
		pos >>= 1;
	}
}

inline void update(segtree &res, segtree &in) {
	for (int i = 1; i < 31; i++) {
		res.s[i] += in.s[i];
		res.mini[i] = min(res.mini[i] == 0 ? in.mini[i] : res.mini[i], in.mini[i] == 0 ? res.mini[i] : in.mini[i]);
	}
}

void query(int a, int b, segtree &res) {
	for (int i = 0; i < 32; i++) {
		res.s[i] = 0;
		res.mini[i] = 0;
	}
	a += M;
	b += M;
	update(res, t[a]);
	if (a != b) update(res, t[b]);
	while (a / 2 != b / 2) {
		if (!(a & 1)) update(res, t[a + 1]);
		if (b & 1) update(res, t[b - 1]);
		a >>= 1;
		b >>= 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		LL x;
		cin >> x;
		insert(x, i);
	}
	segtree res;
	while (q--) {
		int a, b;
		cin >> a >> b;
		query(a, b, res);
		LL C = 0;
		for (int i = 1; i < 31; i++) {
			C = res.s[i];
			if (C + 1 < (1 << (i + 1)) && (res.mini[i + 1] == 0 || C + 1 < res.mini[i + 1])) {
				break;
			}
		}
		cout << C + 1 << "\n";
	}
	return 0;
}
