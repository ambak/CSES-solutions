#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 400009;

int d[N];

void insert(int x, int v) {
	for (; x < N; x += x & -x) {
		d[x] += v;
	}
}

int query(int x) {
	int res = 0;
	for (; x > 0; x -= x & -x) {
		res += d[x];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= 2 * n; i++) {
		insert(i, 1);
	}
	k++;
	int actual = 1;
	while (query(n)) {
		int l = actual;
		int r = actual + n;
		int count = k;
		if (query(n) < k) {
			count %= query(n);
			if (count == 0)
				count = query(n);
		}
		while (true) {
			int s = (l + r) / 2;
			int res = query(s) - query(actual - 1);
			if (res == count && query(s) - query(s - 1) == 1) {
				int ans = s;
				if (ans > n) {
					ans -= n;
				}
				cout << ans << " ";
				insert(ans, -1);
				insert(ans + n, -1);
				actual = ans;
				break;
			} else if (res < count) {
				l = s + 1;
			} else {
				r = s - 1;
			}
		}
	}
	return 0;
}
