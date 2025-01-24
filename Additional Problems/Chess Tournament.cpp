#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<pair<int, int>> v;
int t[100009];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	bool ok = true;
	LL sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> t[i];
		sum += t[i];
		if (t[i] > n - 1) {
			ok = false;
		}
	}
	auto cmp = [](int a, int b) {
		if (t[a] == t[b]) return a < b;
		return t[a] > t[b];
	};
	set<int, decltype(cmp)> s(cmp);

	for (int i = 1; i <= n; i++) {
		if (t[i] > 0) {
			s.insert(i);
		}
	}

	while (s.size() >= 2) {
		int a = *s.begin();
		s.erase(s.begin());
		vector<int> used;
		for (auto b : s) {
			v.push_back({a, b});
			used.push_back(b);
			t[a]--;
			if (t[a] == 0) {
				break;
			}
		}
		if (t[a] != 0) {
			ok = false;
			break;
		}
		for (auto b : used) {
			s.erase(b);
			t[b]--;
			if (t[b] > 0) {
				s.insert(b);
			}
		}
	}

	if (ok == false || s.size()) {
		cout << "IMPOSSIBLE\n";
	} else {
		cout << v.size() << "\n";
		for (auto [a, b] : v) {
			cout << a << " " << b << "\n";
		}
	}
	return 0;
}
