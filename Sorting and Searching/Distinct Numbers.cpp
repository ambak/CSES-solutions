#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	set<int> s;
	for (int i = 0; i < t; i++) {
		int x;
		cin >> x;
		s.insert(x);
	}
	cout << s.size() << "\n";
	return 0;
}
