#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1e9 + 7;
vector<int> v[100009];
int odw[100009];

LL exp(LL a, LL b) {
	LL res = 1;
	while (b) {
		if (b & 1) {
			res = (res * a) % MOD;
		}
		b >>= 1;
		a = (a * a) % MOD;
	}
	return res;
}

LL dfs(int st, int parent) {
	LL res = 0;
	odw[st] = 1;
	for (auto x : v[st]) {
		if (x == parent) {
			continue;
		}
		if (odw[x] == 1) {
			res++;
		} else if (odw[x] == 0) {
			res += dfs(x, st);
		}
	}
	odw[st] = 2;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	LL res = 1;
	for (int i = 1; i < n; i++) {
		if (odw[i] == 0) {
			res = (res * exp(2, dfs(i, i))) % MOD;
		}
	}
	cout << res << "\n";
	return 0;
}
