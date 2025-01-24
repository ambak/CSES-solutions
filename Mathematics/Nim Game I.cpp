#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int nimsum = 0;
		while (n--) {
			int x;
			cin >> x;
			nimsum ^= x;
		}
		if (nimsum) {
			cout << "first\n";
		} else {
			cout << "second\n";
		}
	}
	return 0;
}
