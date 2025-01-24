#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int M = 200009;
int d[M];
int t[M];
int nn[M];

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
	cin >> n >> q;
	map<int, int> mm;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
		if (mm.find(d[i]) != mm.end()) {
			nn[mm[d[i]]] = i;
		} else {
			update(i, 1);
		}
		mm[d[i]] = i;
	}
	vector<tuple<int, int, int> > v;
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		v.emplace_back(a, b, i);
	}
	sort(v.begin(), v.end());
	vector<int> res(q);
	int id = 1;
	for (auto [a, b, i] : v) {
		while (a > id) {
			if (query(id)) {
				update(id, -1);
			}
			if (nn[id] != 0) {
				update(nn[id], 1);
			}
			id++;
		}
		res[i] = query(b);
	}
	for (auto x : res) {
		cout << x << "\n";
	}
	return 0;
}
