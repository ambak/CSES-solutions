#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int M = 1e6 + 5;
int d[M];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		d[x]++;
	}
	for (int res = M; res > 0; res--) {
		int p = 0;
		for (int i = res; i < M; i += res) {
			p += d[i];
		}
		if (p > 1) {
			cout << res << "\n";
			break;
		}
	}
	return 0;
}
