#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	LL n, area = 0, boundary = 0;
	cin >> n;
	vector<pair<LL, LL>> v(n);
	for (auto &[x, y] : v) cin >> x >> y;
	v.push_back(v[0]);
	for (int i = 0; i < n; i++) {
		area += v[i].first * v[i + 1].second - v[i + 1].first * v[i].second;
		if (v[i].first == v[i + 1].first) {
			boundary += abs(v[i].second - v[i + 1].second);
		}
		if (v[i].second == v[i + 1].second) {
			boundary += abs(v[i].first - v[i + 1].first);
		}
		if (v[i].first != v[i + 1].first && v[i].second != v[i + 1].second) {
			boundary += gcd(abs(v[i].first - v[i + 1].first), abs(v[i].second - v[i + 1].second));
		}
	}
	cout << (abs(area) - boundary + 2) / 2 << " " << boundary << "\n";
	return 0;
}
