#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

multiset<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.insert(-x);
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		auto it = s.lower_bound(-x);
		if (it != s.end()) {
			cout << -*it << "\n";
			s.erase(it);
		} else {
			cout << -1 << "\n";
		}
	}
	return 0;
}
