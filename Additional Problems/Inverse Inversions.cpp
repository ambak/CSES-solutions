#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL t[1000009];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	LL n, k;
	cin >> n >> k;
	LL x = n - 1;
	LL id = n;
	LL pos = 0;
	while (k > 0 && k >= x) {
		t[pos] = id;
		id--;
		pos++;
		k -= x;
		x--;
	}
	if (k > 0) {
		t[n - 1 - k] = id;
	}
	id = 1;
	for (LL i = 0; i < n; i++) {
		if (t[i] == 0) {
			t[i] = id;
			id++;
		}
	}
	for (LL i = 0; i < n; i++) {
		cout << t[i] << " ";
	}
	return 0;
}
