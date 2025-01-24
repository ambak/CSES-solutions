#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	ios_base::sync_with_stdio(false);
	LL p, a, n;
	cin >> p >> a >> n;
	vector<pair<LL, LL>> v(n);
	for (auto &[st, nd] : v) cin >> st >> nd;
	sort(v.begin(), v.end(), [](auto a, auto b) { return a.first == b.first ? a.second < b.second : a.first > b.first; });

	LL sump = 0;
	LL suma = 0;
	priority_queue<LL> dif;
	for (int i = 0; i < p; i++) {
		sump += v[i].first;
		dif.push(v[i].second - v[i].first);
	}
	vector<pair<LL, LL>> w;
	w.insert(w.begin(), v.begin() + p, v.end());
	sort(w.begin(), w.end(), [](auto a, auto b) { return a.second == b.second ? a.first < b.first : a.second > b.second; });
	multiset<LL> rest;
	for (int i = 0; i < a; i++) {
		rest.insert(w[i].second);
		suma += w[i].second;
	}
	LL res = sump + suma;
	if (p == 0) {
		cout << res << "\n";
		return 0;
	}
	for (int i = p; i < p + a; i++) {
		suma += dif.top();
		dif.pop();
		sump += v[i].first;
		dif.push(v[i].second - v[i].first);
		if (rest.find(v[i].second) != rest.end()) {
			rest.erase(rest.find(v[i].second));
			suma -= v[i].second;
		} else {
			suma -= *rest.begin();
			rest.erase(rest.begin());
		}
		res = max(res, sump + suma);
	}
	cout << res << "\n";
	return 0;
}
