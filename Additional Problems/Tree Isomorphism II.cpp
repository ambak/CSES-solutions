#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

map<vector<int>, int> m;
int id;

vector<int> get_centroids(const int n, vector<vector<int>> &v) {
	vector<int> centroids;
	vector<bool> odw(n + 1);
	const function<int(int)> dfs = [&dfs, &v, &odw, &centroids, &n](int st) {
		odw[st] = true;
		int sum = 1;
		bool is_centroid = true;
		for (int i : v[st]) {
			if (!odw[i]) {
				int res = dfs(i);
				sum += res;
				if (res > n / 2) {
					is_centroid = false;
				}
			}
		}
		if (n - sum > n / 2) {
			is_centroid = false;
		}
		if (is_centroid) {
			centroids.push_back(st);
		}
		return sum;
	};
	dfs(1);
	return centroids;
}

int tree_encode(int st, int parent, vector<vector<int>> &v) {
	vector<int> children;
	for (auto x : v[st]) {
		if (x != parent)
			children.push_back(tree_encode(x, st, v));
	}
	sort(children.begin(), children.end());
	if (m.find(children) == m.end()) m[children] = ++id;
	return m[children];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<vector<int>> t1(n + 1);
		vector<vector<int>> t2(n + 1);
		for (int i = 1; i < n; i++) {
			int a, b;
			cin >> a >> b;
			t1[a].push_back(b);
			t1[b].push_back(a);
		}
		for (int i = 1; i < n; i++) {
			int a, b;
			cin >> a >> b;
			t2[a].push_back(b);
			t2[b].push_back(a);
		}
		auto c1 = get_centroids(n, t1);
		auto c2 = get_centroids(n, t2);
		int ans1 = tree_encode(c1[0], -1, t1);
		bool yes = false;
		for (auto c : c2) {
			int ans2 = tree_encode(c, -1, t2);
			if (ans1 == ans2) {
				yes = true;
			}
		}
		if (yes) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
		id = 0;
		m.clear();
	}
	return 0;
}
