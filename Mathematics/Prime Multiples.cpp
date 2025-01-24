#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> v;

void dw(LL n, LL x, LL k, LL il, LL c, LL &res, int i) {
	for (; i < k; i++) {
		if (il <= n / v[i]) {
			il *= v[i];
			if (c + 1 == x) {
				res += n / il;
			} else {
				dw(n, x, k, il, c + 1, res, i + 1);
			}
			il /= v[i];
		} else {
			break;
		}
	}
}

LL f(LL n, LL x, LL k) {
	LL res = 0;
	dw(n, x, k, 1, 0, res, 0);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	LL n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		LL x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	LL res = 0;
	for (int i = 0; i < k; i++) {
		if (i % 2 == 0) {
			res += f(n, i + 1, k);
		} else {
			res -= f(n, i + 1, k);
		}
	}
	cout << res << "\n";
}
