#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int a[1000009];
int b[1000009];

int main() {
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	sort(a, a + n);
	sort(b, b + m);
	int res = 0;
	for (int i = 0, j = 0; i < n && j < m;) {
		if (abs(a[i] - b[j]) <= k) {
			res++;
			i++;
			j++;
		} else {
			if (a[i] < b[j])
				i++;
			else
				j++;
		}
	}
	cout << res << "\n";
	return 0;
}
