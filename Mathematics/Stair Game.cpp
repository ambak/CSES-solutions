#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		int nim = 0;
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			if (i % 2 == 0) {
				nim ^= x;
			}
		}
		if (nim) {
			cout << "first\n";
		} else {
			cout << "second\n";
		}
	}
	return 0;
}
