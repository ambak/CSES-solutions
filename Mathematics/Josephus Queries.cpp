#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int josephus(int n, int k, int p = 0) {
	if (n == 1) {
		return 1;
	}
	if (k <= (n + p) / 2) {
		return k * 2 - p;
	}
	return josephus(n - (n + p) / 2, k - (n + p) / 2, (p + n) % 2) * 2 - 1 + p;
}

int main() {
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--) {
		int n, k;
		cin >> n >> k;
		cout << josephus(n, k) << "\n";
	}
	return 0;
}
