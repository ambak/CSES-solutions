#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL d = 40926266145LL;

inline LL swap_bit(LL c, const LL a1, const LL a2, const LL diff) {
	LL b1 = (c & a1) >> diff;
	LL b2 = (c & a2) << diff;
	c = (c & ~a1) & (c & ~a2);
	c = c | b1 | b2;
	return c;
}

int f(LL t) {
	if (t == d) return 0;
	vector<LL> v;
	vector<LL> w;
	unordered_set<LL> s;
	v.push_back(t);
	s.insert(t);
	const LL sb[12][3] = {
		{0xf00000000LL, 0x0f0000000LL, 4},
		{0x0f0000000LL, 0x00f000000LL, 4},
		{0x000f00000LL, 0x0000f0000LL, 4},
		{0x0000f0000LL, 0x00000f000LL, 4},
		{0x000000f00LL, 0x0000000f0LL, 4},
		{0x0000000f0LL, 0x00000000fLL, 4},

		{0xf00000000LL, 0x000f00000LL, 12},
		{0x0f0000000LL, 0x0000f0000LL, 12},
		{0x00f000000LL, 0x00000f000LL, 12},
		{0x000f00000LL, 0x000000f00LL, 12},
		{0x0000f0000LL, 0x0000000f0LL, 12},
		{0x00000f000LL, 0x00000000fLL, 12},
	};
	for (int j = 1;; ++j) {
		for (auto t : v) {
			for (int i = 0; i < 12; ++i) {
				LL tt = swap_bit(t, sb[i][0], sb[i][1], sb[i][2]);
				if (s.find(tt) == s.end()) {
					if (tt == d) {
						return j;
					}
					w.push_back(tt);
					s.insert(tt);
				}
			}
		}
		v = w;
		w.clear();
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	LL x = 0;
	for (int i = 0; i < 9; i++) {
		LL n;
		cin >> n;
		x += n << (4 * i);
	}
	cout << f(x) << "\n";
	return 0;
}
