#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

multiset<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		auto it = s.upper_bound(k);
		if (it != s.end()) {
			s.erase(it);
		}
		s.insert(k);
	}
	cout << s.size() << "\n";
	return 0;
}
