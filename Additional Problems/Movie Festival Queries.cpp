#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> v[1000009];
int d[1000009][20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	vector<pair<int, int>> p;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		p.push_back({a, b});
	}
	auto cmp_sort = [](pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) {
			return a.second > b.second;
		}
		return a.first < b.first;
	};
	sort(p.begin(), p.end(), cmp_sort);
	auto cmp = [&p](int a, int b) {
		if (p[a].second == p[b].second) {
			return a < b;
		}
		return p[a].second < p[b].second;
	};
	set<int, decltype(cmp)> s(cmp);
	vector<pair<int, int>> to_remove;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 20; j++) {
			d[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		while (!s.empty() && p[*s.rbegin()].second >= p[i].second) {
			to_remove.push_back({*s.rbegin(), i});
			s.erase(*s.rbegin());
		}
		while (!s.empty() && p[*s.begin()].second <= p[i].first) {
			v[i].push_back(*s.begin());
			d[*s.begin()][0] = i;
			s.erase(s.begin());
		}
		s.insert(i);
	}
	for (auto [a, b] : to_remove) {
		for (auto x : v[a]) {
			d[x][0] = b;
			v[b].push_back(x);
		}
	}
	for (int j = 1; j < 20; j++) {
		for (int i = 0; i < n; i++) {
			if (d[i][j - 1] == -1) continue;
			d[i][j] = d[d[i][j - 1]][j - 1];
		}
	}
	vector<int> w;
	sort(to_remove.begin(), to_remove.end());
	for (int i = 0, j = 0; i < n; i++) {
		if (j < int(to_remove.size()) && i == to_remove[j].first) {
			j++;
		} else {
			w.push_back(i);
		}
	}
	auto cmp_lower = [&p](int a, int b) {
		return p[a].first < b;
	};
	while (q--) {
		int a, b;
		cin >> a >> b;
		auto it = lower_bound(w.begin(), w.end(), a, cmp_lower);
		int x = *it;
		if (it != w.begin()) {
			it--;
			if (p[*it].first >= a) {
				x = *it;
			}
		}
		if (p[x].second > b) {
			cout << 0 << "\n";
			continue;
		}
		int res = 1;
		int j = 19;
		for (; j >= 0; j--) {
			if (d[x][j] != -1) {
				break;
			}
		}
		while (j >= 0) {
			if (d[x][j] != -1 && p[d[x][j]].second <= b) {
				res += 1 << j;
				x = d[x][j];
			}
			j--;
		}
		cout << res << "\n";
	}
	return 0;
}
