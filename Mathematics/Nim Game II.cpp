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
		vector<int> v;
		while (n--) {
			int x;
			cin >> x;
			x &= 3;
			nimsum ^= x;
			v.push_back(x);
		}
		for (auto x : v) {
			nimsum ^= x;
			if (x >= 1 && (nimsum ^ (x - 1)) == 0) {
				nimsum = -1;
				break;
			} else if (x >= 2 && (nimsum ^ (x - 2)) == 0) {
				nimsum = -1;
				break;
			} else if (x >= 3 && (nimsum ^ (x - 3)) == 0) {
				nimsum = -1;
				break;
			}
			nimsum ^= x;
		}
		if (nimsum == -1) {
			cout << "first\n";
		} else {
			cout << "second\n";
		}
	}
	return 0;
}
