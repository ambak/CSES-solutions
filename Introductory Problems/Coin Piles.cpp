#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int y = 2 * a - b;
		bool yes = false;
		if (y % 3 == 0 && y >= 0) {
			y /= 3;
			if (a - 2 * y >= 0) {
				yes = true;
			}
		}
		cout << (yes ? "YES\n" : "NO\n");
	}
	return 0;
}
