#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	LL n;
	cin >> n;
	LL sum = (1 + n) * n / 2;
	if (sum % 2 == 1) {
		cout << "NO\n";
	} else {
		vector<int> a, b;
		sum /= 2;
		for (int i = n; i >= 1; i--) {
			if (i <= sum) {
				a.push_back(i);
				sum -= i;
			} else {
				b.push_back(i);
			}
		}
		cout << "YES\n";
		cout << a.size() << "\n";
		for (auto x : a) {
			cout << x << " ";
		}
		cout << "\n"
			 << b.size() << "\n";
		for (auto x : b) {
			cout << x << " ";
		}
	}
	return 0;
}
