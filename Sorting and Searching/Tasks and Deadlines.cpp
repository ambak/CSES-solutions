#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<pair<int, int> > v;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	LL res = 0;
	LL time = 0;
	sort(v.begin(), v.end());
	for (auto i : v) {
		time += i.first;
		res += i.second - time;
	}

	cout << res << "\n";

	return 0;
}
