#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	LL n, res = 0;
	cin >> n;
	vector<pair<LL, LL>> v(n);
	for (auto &[x, y] : v) cin >> x >> y;
	for (int i = 0; i < n - 1; i++) {
		res += v[i].first * v[i + 1].second - v[i + 1].first * v[i].second;
	}
	res += v.back().first * v[0].second - v[0].first * v.back().second;
	cout << abs(res) << "\n";
	return 0;
}
