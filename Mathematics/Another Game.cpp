#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto &x : v) cin >> x;
		int odd = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] % 2)
				odd++;
		}
		if (odd == 0) {
			cout << "second\n";
		} else {
			cout << "first\n";
		}
	}
	return 0;
}
