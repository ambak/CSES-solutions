#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int prev = -1;
	int x;
	LL res = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x > prev) {
			prev = x;
		} else {
			res += prev - x;
		}
	}
	cout << res << "\n";
	return 0;
}
