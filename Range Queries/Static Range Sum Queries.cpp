#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL t[200009];

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		LL x;
		cin >> x;
		t[i] = t[i - 1] + x;
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << t[b] - t[a - 1] << "\n";
	}
	return 0;
}
