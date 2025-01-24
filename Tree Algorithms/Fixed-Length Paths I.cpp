#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, k;
vector<int> v[200009];
vector<int> w[200009];
bool odw[200009];
LL depth[200009];
int subtree_size[200009];

void get_size(int st, int parent) {
	subtree_size[st] = 1;
	for (auto x : v[st]) {
		if (x != parent && !odw[x]) {
			get_size(x, st);
			subtree_size[st] += subtree_size[x];
		}
	}
}

int get_centroid(int st, int K, int parent = 0) {
	bool ok = true;
	while (true) {
		ok = true;
		for (auto x : v[st]) {
			if (!odw[x] && subtree_size[x] > K && x != parent) {
				parent = st;
				st = x;
				ok = false;
				break;
			}
		}
		if (ok) break;
	}
	return st;
}

int calc_depth(bool count, int d, int st, int parent, LL &ans) {
	if (d > k) return k;
	int de = d;
	if (count) {
		ans += depth[k - d];
	} else {
		depth[d]++;
	}
	for (auto x : v[st]) {
		if (!odw[x] && x != parent) {
			de = max(de, calc_depth(count, d + 1, x, st, ans));
		}
	}
	return de;
}

LL centroid_decomp(int st, int parent = 0) {
	LL ans = 0;
	depth[0] = 1;
	get_size(st, 0);
	int K = subtree_size[st];
	if (K < k) {
		return 0;
	}
	int centroid = get_centroid(st, K / 2);
	odw[centroid] = true;
	int N = 0;
	for (auto x : v[centroid]) {
		if (!odw[x]) {
			calc_depth(true, 1, x, 0, ans);
			N = max(N, calc_depth(false, 1, x, 0, ans));
		}
	}
	for (int i = 1; i <= N; i++) depth[i] = 0;
	for (auto x : v[centroid]) {
		if (!odw[x] && x != parent) {
			ans += centroid_decomp(x, centroid);
		}
	}
	return ans;
}

bool odw2[200009];
int td[200009];
int C = 2;
void dfs_map(int st) {
	odw2[st] = true;
	for (auto x : w[st]) {
		if (odw2[x] == false) {
			td[x] = C;
			C++;
			v[td[st]].push_back(td[x]);
			v[td[x]].push_back(td[st]);
			dfs_map(x);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		w[a].push_back(b);
		w[b].push_back(a);
	}
	td[1] = 1;
	dfs_map(1);
	cout << centroid_decomp(1) << "\n";
	return 0;
}
