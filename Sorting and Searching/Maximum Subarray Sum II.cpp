#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

multiset<LL> m;
LL d[200009];

int main() {
	ios_base::sync_with_stdio(false);
	LL n, a, b;
	cin >> n >> a >> b;
	for (LL i = 1; i <= n; i++) {
		LL x;
		cin >> x;
		d[i] = d[i - 1] + x;
	}
	for (LL i = a; i <= b; i++) {
		m.insert(d[i]);
	}
	LL res = *m.rbegin();
	for (LL i = a + 1; i <= n; i++) {
		m.erase(m.find(d[i - 1]));
		if (i + b - a <= n) {
			m.insert(d[i + b - a]);
		}
		res = max(res, *m.rbegin() - d[i - a]);
	}

	cout << res << "\n";
	return 0;
}
