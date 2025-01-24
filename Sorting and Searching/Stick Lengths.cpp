#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int a[1000009];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	LL res = 0;
	for (int i = 0; i < n; i++) {
		res += abs(a[i] - a[n / 2]);
	}
	cout << res << "\n";
	return 0;
}
