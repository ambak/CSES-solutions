#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	LL x, n;
	cin >> x >> n;
	multiset<LL> s;
	for (int i = 0; i < n; i++) {
		LL a;
		cin >> a;
		s.insert(a);
	}
	LL res = 0;
	while (s.size() > 1) {
		LL a = *s.begin();
		s.erase(s.begin());
		LL b = *s.begin();
		s.erase(s.begin());
		res += a + b;
		s.insert(a + b);
	}
	cout << res << "\n";
	return 0;
}
