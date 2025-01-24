#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> v[200009];
int odw[200009];
int d[200009][20];

void dfs(int st, int c) {
	odw[st] = c;
	for (auto it : v[st]) {
		if (odw[it] == 0) {
			d[it][1] = st;
			for (int i = 2; i < 20; i++) {
				d[it][i] = d[d[it][i - 1]][i - 1];
			}
			dfs(it, c + 1);
		}
	}
}

int query(int a, int b) {
	int res = 0;
	if (odw[a] < odw[b]) {
		swap(a, b);
	}
	int k = odw[a] - odw[b];
	res += k;
	int id = 1;
	while (k) {
		if (k & 1) {
			a = d[a][id];
		}
		k /= 2;
		id++;
	}
	if (a == b) {
		return res;
	}
	int h = odw[a];
	for (int i = 19; i > 0; i--) {
		if (d[a][i] != d[b][i]) {
			a = d[a][i];
			b = d[b][i];
		}
	}
	res += 2 * (h - odw[d[a][1]]);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	LL n, q;
	cin >> n >> q;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1, 1);
	while (q--) {
		int a, b;
		cin >> a >> b;
		cout << query(a, b) << "\n";
	}
	return 0;
}
