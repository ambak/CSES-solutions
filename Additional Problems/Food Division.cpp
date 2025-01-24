#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<LL> a(n);
	for (auto &x : a) cin >> x;
	for (int i = 0; i < n; i++) {
		LL x;
		cin >> x;
		a[i] = a[i] - x;
	}
	vector<LL> v(n);
	for (int i = 1; i < n; i++) {
		v[i] = v[i - 1] + a[i - 1];
	}
	sort(v.begin(), v.end());
	LL res = 0;
	for (int i = 0; i < n; i++) {
		res += abs(v[i] - v[n / 2]);
	}
	cout << res << "\n";
	return 0;
}
