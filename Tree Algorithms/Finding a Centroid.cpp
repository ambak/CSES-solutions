#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> v(n + 1);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	auto centroids = get_centroids(n, v);
	cout << centroids[0] << "\n";
	return 0;
}
