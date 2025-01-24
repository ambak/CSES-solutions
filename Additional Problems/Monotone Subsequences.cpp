#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		if (k * k < n) {
			cout << "IMPOSSIBLE\n";
		} else {
			int last = 0;
			for (int i = 1; i <= k; i++) {
				int j = k * i;
				bool last_round = false;
				if (j >= n) {
					j = n;
					last_round = true;
				}
				for (; j > last; j--) {
					cout << j << " ";
				}
				last = k * i;
				if (last_round) {
					cout << "\n";
					break;
				}
			}
		}
	}
	return 0;
}
