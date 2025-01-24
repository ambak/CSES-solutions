#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int t[1000009];
bool p[1000009];
vector<int> factors[1000009];
int s[1000009];

void dw(int n, int x, int k, int il, int c, LL &res, int i, vector<int> &v, bool ss, int value) {
	for (; i < k; i++) {
		if (il <= n / v[i]) {
			il *= v[i];
			if (c + 1 == x) {
				if (ss) {
					s[il] += value;
				} else {
					res += s[il];
				}
			} else {
				dw(n, x, k, il, c + 1, res, i + 1, v, ss, value);
			}
			il /= v[i];
		} else {
			break;
		}
	}
}

LL f(int n, int x, int k, vector<int> &v, bool ss, int value) {
	LL res = 0;
	dw(n, x, k, 1, 0, res, 0, v, ss, value);
	return res;
}

void sieve(int n) {
	for (int i = 2; i <= n; i++) {
		if (p[i] == false) {
			for (int j = i + i; j <= n; j += i) {
				p[j] = true;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	sieve(1000000);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		t[x]++;
	}

	LL res = 0;

	for (int i = 2; i < 1000000; i++) {
		if (p[i] == false) {
			for (int j = i; j <= 1000000; j += i) {
				if (t[j]) {
					factors[j].push_back(i);
				}
			}
		}
	}

	for (int i = 2; i <= 1000000; i++) {
		if (t[i]) {
			for (unsigned j = 0; j < factors[i].size(); j++) {
				f(1000000, j + 1, factors[i].size(), factors[i], true, t[i]);
			}
		}
	}
	for (int i = 2; i <= 1000000; i++) {
		if (t[i]) {
			LL ans = 0;
			for (unsigned j = 0; j < factors[i].size(); j++) {
				if (j % 2 == 0) {
					ans += f(1000000, j + 1, factors[i].size(), factors[i], false, t[i]);
				} else {
					ans -= f(1000000, j + 1, factors[i].size(), factors[i], false, t[i]);
				}
			}
			res += (n - ans) * t[i];
		}
	}
	res += (n - t[1]) * t[1];
	res += (t[1] - 1) * t[1];
	res /= 2;
	cout << res << "\n";
}
