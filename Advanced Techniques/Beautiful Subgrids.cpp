#include <bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
typedef long long LL;

bitset<3000> v[3000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	LL res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			LL b = (v[i] & v[j]).count() - 1;
			res += (1 + b) * b / 2;
		}
	}
	cout << res << "\n";
	return 0;
}
