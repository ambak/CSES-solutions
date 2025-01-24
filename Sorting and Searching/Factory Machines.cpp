#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> v;
LL t;
bool check(LL x) {
	LL res = 0;
	for (int it : v) {
		res += x / it;
		if (res >= t) {
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		LL a;
		cin >> a;
		v.push_back(a);
	}
	LL l = 0;
	LL r = 1e18L + 5;
	while (l != r) {
		LL c = (l + r) / 2;
		if (check(c)) {
			r = c;
		} else {
			l = c + 1;
		}
	}
	cout << l << "\n";

	return 0;
}
