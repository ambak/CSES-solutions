#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v[i] = stoi(s, nullptr, 2);
	}
	int res = k;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			res = min(res, __builtin_popcount(v[i] ^ v[j]));
		}
	}
	cout << res << "\n";
	return 0;
}
