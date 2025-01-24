#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<int> p(k);
	vector<char> res(n + 1);
	for (int i = 0; i < k; i++) {
		cin >> p[i];
	}
	for (int i = 0; i <= n; i++) {
		if (res[i] == 0) {
			res[i] = 'L';
			for (auto j : p) {
				if (i + j <= n) {
					res[i + j] = 'W';
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << res[i];
	}
	return 0;
}
