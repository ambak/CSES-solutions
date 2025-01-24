#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int a[1000009];

int main() {
	ios_base::sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int res = 0;
	for (int i = 0, j = n - 1; i <= j;) {
		if (a[j] + a[i] <= x) {
			i++;
			j--;
		} else {
			j--;
		}
		res++;
	}
	cout << res << "\n";
	return 0;
}
