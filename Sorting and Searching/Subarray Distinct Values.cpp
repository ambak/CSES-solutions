#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL d[200009];
map<LL, LL> m;

int main() {
	ios_base::sync_with_stdio(false);
	LL n, k;
	cin >> n >> k;
	LL res = 0;
	LL count = 0;
	LL j = 0;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
		m[d[i]]++;
		if (m[d[i]] == 1) {
			count++;
		}
		while (count > k) {
			m[d[j]]--;
			if (m[d[j]] == 0) {
				count--;
			}
			j++;
		}
		res += i - j + 1;
	}
	cout << res << "\n";

	return 0;
}
