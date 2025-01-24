#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> solve(LL a, int n, int m, vector<LL> &v) {
	vector<LL> res;
	res.push_back(a);
	res.push_back(v[0] - a);
	multiset<LL> ms;
	for (int i = 1; i < m; i++) {
		ms.insert(v[i]);
	}
	for (int i = 2; i < n; i++) {
		LL b = *ms.begin() - a;
		for (auto c : res) {
			auto it = ms.find(b + c);
			if (it != ms.end()) {
				ms.erase(it);
			} else {
				return vector<LL>();
			}
		}
		res.push_back(b);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int m = n * (n - 1) / 2;
	vector<LL> v(m);
	for (auto &x : v) cin >> x;
	sort(v.begin(), v.end());
	for (int i = 2; i < m; i++) {
		LL a = v[1] + v[0] - v[i];
		if (a >= 0 && a % 2) continue;
		a /= 2;
		auto w = solve(a, n, m, v);
		if (!w.empty()) {
			for (auto x : w) {
				cout << x << " ";
			}
			break;
		}
	}
	return 0;
}
