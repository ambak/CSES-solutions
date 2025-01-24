#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL t[200009];
LL d[200009];
map<LL, LL> m;

int main() {
	ios_base::sync_with_stdio(false);
	LL n, x;
	cin >> n >> x;
	LL sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		sum += t[i];
	}
	for (int i = 1; i <= n; i++) {
		d[i] = d[i - 1] + t[i];
		if (m.find(d[i]) == m.end()) {
			m[d[i]] = 1;
		} else {
			m[d[i]]++;
		}
	}
	LL res = 0;
	for (int i = 0; i < n; i++) {
		LL aim = x + d[i];
		if (m.find(aim) != m.end()) {
			res += m[aim];
		}
		m[d[i + 1]]--;
	}
	cout << res << "\n";
	return 0;
}
