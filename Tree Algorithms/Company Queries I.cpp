#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<LL> v[200009];
bool odw[200009];
int d[200009][20];

void dfs(int st) {
	odw[st] = true;
	for (auto it : v[st]) {
		if (!odw[it]) {
			d[it][1] = st;
			for (int i = 2; i < 20; i++) {
				d[it][i] = d[d[it][i - 1]][i - 1];
			}
			dfs(it);
		}
	}
}

int query(int x, int k) {
	int res = x;
	int id = 1;
	while (k) {
		if (k & 1) {
			res = d[res][id];
		}
		k /= 2;
		id++;
	}
	return res == 0 ? -1 : res;
}

int main() {
	ios_base::sync_with_stdio(false);
	LL n, q;
	cin >> n >> q;
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		v[x].push_back(i);
	}
	dfs(1);
	while (q--) {
		int x, k;
		cin >> x >> k;
		cout << query(x, k) << "\n";
	}

	return 0;
}
