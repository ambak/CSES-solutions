#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

set<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	v.insert(0);
	int res = 1;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (v.find(a - 1) == v.end()) {
			res++;
		}
		v.insert(a);
	}
	cout << res << "\n";
	return 0;
}
