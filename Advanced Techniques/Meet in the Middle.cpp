#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> subsets_map(vector<LL> &v) {
	vector<LL> m;
	for (int i = 0; i < (1 << v.size()); i++) {
		LL sum = 0;
		for (unsigned j = 0; j < v.size(); j++) {
			if (i & (1 << j)) {
				sum += v[j];
			}
		}
		m.push_back(sum);
	}
	return m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	LL n, x;
	cin >> n >> x;
	vector<LL> v1(n / 2), v2(n - n / 2);
	for (auto &x : v1) cin >> x;
	for (auto &x : v2) cin >> x;
	auto m1 = subsets_map(v1);
	auto m2 = subsets_map(v2);
	sort(m1.begin(), m1.end());
	sort(m2.begin(), m2.end());
	vector<pair<LL, LL> > m3;
	for (auto k : m2) {
		if (!m3.empty() && m3.back().first == k) {
			m3.back().second++;
		} else {
			m3.emplace_back(k, 1);
		}
	}
	LL res = 0;
	int j = m3.size() - 1;
	for (auto k : m1) {
		while (m3[j].first + k > x && j > 0) j--;
		if (m3[j].first + k == x) res += m3[j].second;
	}
	cout << res << "\n";
	return 0;
}
