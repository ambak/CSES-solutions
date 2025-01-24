#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	int res = 0;
	vector<int> a, b, c;
	a.reserve(n);
	b.reserve(n);
	c.reserve(n);
	a.push_back(0);
	for (int i = 1; i < n; i++) {
		for (auto x : a) {
			b.push_back(x + 1);
		}
		for (unsigned j = 0, k = 0;;) {
			if (k == b.size()) {
				a = c;
				b.clear();
				c.clear();
				break;
			}
			if (j < a.size() && a[j] < b[k]) {
				c.push_back(a[j]);
				j++;
			} else if (j < a.size() && a[j] == b[k]) {
				j++;
				k++;
			} else {
				c.push_back(b[k]);
				k++;
			}
		}
	}

	for (auto x : a) {
		res ^= v[x];
	}
	cout << res << "\n";
	return 0;
}
