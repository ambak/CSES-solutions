#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	LL n, res = 0;
	cin >> n;
	vector<LL> v(n);
	vector<LL> l(n);
	vector<LL> r(n);
	for (auto &x : v) cin >> x;
	stack<pair<LL, LL>> q;
	v.push_back(-1);
	for (int i = 0; i <= n; i++) {
		while (!q.empty() && q.top().first > v[i]) {
			r[q.top().second] = i;
			q.pop();
		}
		q.push({v[i], i});
	}
	v.pop_back();
	v.insert(v.begin(), -1);
	q.pop();
	for (int i = n; i >= 0; i--) {
		while (!q.empty() && q.top().first > v[i]) {
			l[q.top().second - 1] = i;
			q.pop();
		}
		q.push({v[i], i});
	}
	v.erase(v.begin());
	for (int i = 0; i < n; i++) {
		res = max(res, v[i] * (r[i] - l[i]));
	}
	cout << res << "\n";
	return 0;
}
