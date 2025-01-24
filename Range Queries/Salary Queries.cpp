#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int M = 800009;
int d[M];
int t[M];

void update(int x, int v) {
	for (; x < M; x += x & -x) {
		t[x] += v;
	}
}

int query(int x) {
	int res = 0;
	for (; x > 0; x -= x & -x) {
		res += t[x];
	}
	return res;
}

int main() {
	int n, q;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> q;
	vector<tuple<int, int, int>> v;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
		v.push_back({d[i], i, 0});
	}
	vector<tuple<char, int, int>> queries;
	for (int i = 0; i < q; i++) {
		char c;
		int a, b;
		cin >> c >> a >> b;
		queries.emplace_back(c, a, b);
		if (c == '!') {
			v.push_back({b, i, 1});
		} else {
			v.push_back({a, i, 2});
			v.push_back({b, i, 1});
		}
	}
	sort(v.begin(), v.end());
	int id = 0;
	int prev = -1;
	for (auto& [w, i, x] : v) {
		if (w != prev) {
			prev = w;
			id++;
		}
		if (x == 0) {
			d[i] = id;
		} else if (x == 1) {
			auto [c, a, b] = queries[i];
			queries[i] = {c, a, id};
		} else {
			auto [c, a, b] = queries[i];
			queries[i] = {c, id, b};
		}
	}
	for (int i = 1; i <= n; i++) {
		update(d[i], 1);
	}
	for (auto& [c, a, b] : queries) {
		if (c == '!') {
			update(d[a], -1);
			update(b, 1);
			d[a] = b;
		} else {
			cout << query(b) - query(a - 1) << "\n";
		}
	}
	return 0;
}
