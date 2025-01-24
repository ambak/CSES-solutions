#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, N, k, k1, k2;
vector<int> v[200009];
vector<int> w[200009];
bool odw[200009];
LL depth[200009];
LL depth2[200009];
LL ans;
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
			if (subtree_size[x] > K && !odw[x] && x != parent) {
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

int calc_depth(bool count, int d, int st, int parent) {
	if (d > k2) return k2;
	int de = d;
	if (count) {
		ans += depth[min(k2 - d + 1, N)];
		if (k1 - d >= N)
			ans -= depth[min(k2 - d + 1, N)];
		else if (k1 - d >= 0 && k1 - d < N)
			ans -= depth[k1 - d];
	} else {
		depth[d + 1]++;
	}
	for (auto x : v[st]) {
		if (!odw[x] && x != parent) {
			de = max(de, calc_depth(count, d + 1, x, st));
		}
	}
	return de;
}

int calc_depth_clean(int d, int st, int parent) {
	int de = d;
	for (auto x : v[st]) {
		if (!odw[x] && x != parent) {
			de = max(de, calc_depth_clean(d + 1, x, st));
		}
	}
	return de;
}

int get_max_depth(int st, int parent, int d) {
	if (d > k2) return k2;
	int res = d;
	for (auto x : v[st]) {
		if (!odw[x] && x != parent)
			res = max(res, get_max_depth(x, st, d + 1));
	}
	return res;
}

LL centroid_decomp(int st) {
	get_size(st, 0);
	int K = subtree_size[st];
	if (K <= k1) {
		return 0;
	}
	int centroid = get_centroid(st, K >> 1);
	odw[centroid] = true;
	N = 2;

	int NN = N;
	vector<pair<int, int>> order;
	for (auto x : v[centroid]) {
		int X = calc_depth_clean(1, x, 0);
		order.emplace_back(X, x);
	}
	sort(order.begin(), order.end());
	for (auto [_, x] : order) {
		if (!odw[x]) {
			int X = calc_depth(true, 1, x, 0);
			if (X >= N) {
				N = X + 1;
			}
			for (int i = 0; i <= N; i++) depth[i] = 0;
			calc_depth(false, 1, x, 0);
			LL sum = 0;
			for (int i = 2; i <= NN; i++) {
				sum += depth[i];
				depth2[i] += sum;
			}
			for (int i = NN + 1; i <= N; i++) {
				depth2[i] = depth2[i - 1] + depth[i];
			}
			for (int i = 1; i <= N; i++) {
				depth[i] = depth2[i];
			}
			NN = N;
		}
	}
	for (int i = 1; i <= N; i++) depth[i] = depth2[i] = 1;

	for (auto x : v[centroid]) {
		if (!odw[x]) {
			centroid_decomp(x);
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
	cin >> n >> k1 >> k2;
	for (int i = 1; i <= k2; i++) depth[i] = depth2[i] = 1;
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
