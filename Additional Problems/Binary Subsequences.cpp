// https://math.stackexchange.com/questions/3934503/number-of-binary-sequences-with-exactly-n-distinct-subsequences

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	n += 2;

	int k = n;
	int d = 1;
	for (int i = 1; i < n; i++) {
		if (gcd(i, n) == 1) {
			int res = 0;
			int a = i;
			int b = n;
			while (a) {
				res += b / a;
				int c = a;
				a = b % a;
				b = c;
				if (a > b) swap(a, b);
			}
			if (res < k) {
				k = res;
				d = i;
			}
		}
	}

	n -= d;
	while (n != d) {
		if (n > d) {
			cout << "0";
			n -= d;
		}
		if (d > n) {
			cout << "1";
			d -= n;
		}
	}
	return 0;
}
