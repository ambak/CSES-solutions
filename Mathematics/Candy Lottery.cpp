#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

long double exp(long double a, LL b) {
	double res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a);
		}
		b >>= 1;
		a = (a * a);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	long double res = 0;
	for (int i = k; i >= 1; i--) {
		res += i * (exp((i / (long double)k), n) - exp(((i - 1) / (long double)k), n));
	}
	cout << fixed << setprecision(6) << res << "\n";
	return 0;
}
