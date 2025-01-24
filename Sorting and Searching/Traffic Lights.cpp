#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

multiset<int, greater<int>> ms;
set<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	int n, x;
	cin >> x >> n;
	s.insert(0);
	s.insert(x);
	ms.insert(x - 0);
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		s.insert(p);
		auto it = s.find(p);
		int begin = *(--it);
		it++;
		int end = *(++it);
		ms.erase(ms.find(end - begin));
		ms.insert(end - p);
		ms.insert(p - begin);
		cout << *ms.begin() << " ";
	}

	return 0;
}
