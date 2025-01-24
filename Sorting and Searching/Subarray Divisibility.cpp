#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL t[200009];
LL d[200009];
map<LL, LL> m;

int main() {
	ios_base::sync_with_stdio(false);
	LL n;
	cin >> n;
	LL sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		sum += t[i];
	}
	for (int i = 1; i <= n; i++) {
		d[i] = d[i - 1] + t[i];
		if (d[i] >= 0) {
			if (m.find(d[i] % n) == m.end()) {
				m[d[i] % n] = 1;
			} else {
				m[d[i] % n]++;
			}
		} else {
			LL tmp = (d[i] % n + n) % n;
			if (tmp < 0) cout << tmp << " ";
			if (m.find(tmp) == m.end()) {
				m[tmp] = 1;
			} else {
				m[tmp]++;
			}
		}
	}
	LL res = 0;
	for (int i = 0; i < n; i++) {
		LL aim = (d[i] % n + n) % n;
		if (m.find(aim) != m.end()) {
			res += m[aim];
		}
		if (i + 1 == n) break;
		if (d[i + 1] >= 0) {
			m[d[i + 1] % n]--;
		} else {
			LL tmp = (d[i + 1] % n + n) % n;
			m[tmp]--;
		}
	}
	cout << res << "\n";
	return 0;
}
